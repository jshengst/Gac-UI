
-- 指定代码路径
local source_path = path.join(os.projectdir(),"Source")
-- 用于修复WinMain.cpp的路径问题：Skins\DarkSkin\DarkSkin.h
local importPath = path.join(os.projectdir(),"Import")
-- 定义包含路径的字典
local src_paths = {
    gg = path.join(source_path,"GacUI","Tools","GacGen","GacGen"),
    cp = path.join(source_path,"VlppParser2","Tools","CodePack","CodePack"),
    gp = path.join(source_path,"VlppParser2","Tools","GlrParserGen","GlrParserGen"),
    cm = path.join(source_path,"Workflow","Tools","CppMerge","CppMerge"),
    vl = path.join(source_path,"Vlpp","Release","IncludeOnly"),
    ui = path.join(source_path,"GacUI","Release","IncludeOnly"),
    os = path.join(source_path,"VlppOS","Release","IncludeOnly"),
    wf = path.join(source_path,"Workflow","Release","IncludeOnly"),
    vr = path.join(source_path,"VlppRegex","Release","IncludeOnly"),
    vp = path.join(source_path,"VlppParser","Release","IncludeOnly"),
    v2 = path.join(source_path,"VlppParser2","Release","IncludeOnly"),
    vf = path.join(source_path,"VlppReflection","Release","IncludeOnly")
}
-- 定义移除compiler的路径键
local remove_key_compiler = {
    {path = src_paths["ui"], file = "GacUICompiler"},
    {path = src_paths["wf"], file = "VlppWorkflowCompiler"}
}
-- 定义移除reflection的路径键
local remove_key_reflection = {
    {path = src_paths["ui"], file = "DarkSkinReflection"},
    {path = src_paths["ui"], file = "GacUICompiler"},
    {path = src_paths["ui"], file = "GacUIReflection"},
    {path = src_paths["v2"], file = "VlppGlrParserCompiler"},
    {path = src_paths["wf"], file = "VlppWorkflowCompiler"},
    {path = src_paths["wf"], file = "VlppWorkflowRuntime"}
}


rule("GacUI")

    on_load(function(target)

        -- 反射等级: 无反射(none)、仅类型反射(metaonly)、全反射(full)
        local reflection_level = target:values("GacUI.reflection_level")
        -- 启用source版本代码
        local with_source = target:values("GacUI.with_source")
        -- 启用包含单元测试
        -- todo: 增加更多单元测试的配置参数
        local with_unitest = target:values("GacUI.with_unitest")

        target:add("defines", "_UNICODE", "UNICODE")
        target:add("cxflags", "/utf-8")

        -- 添加所有代码
        local path_keys = {"vl", "ui", "os", "wf", "vr", "vp", "v2", "vf"}
        if with_source then
            for _, key in ipairs(path_keys) do
                target:add("includedirs", src_paths[key], {public = true})
                target:add("headerfiles", path.join(src_paths[key], "**.h"))
                target:add("files", path.join(src_paths[key], "**.cpp"))
            end
        else
            target:add("includedirs", importPath, {public = true })
            target:add("headerfiles", path.join(importPath, "**.h"))
            target:add("files", path.join(importPath, "**.cpp"))
        end

        -- 用于修复WinMain.cpp的路径问题：Skins\DarkSkin\DarkSkin.h
        target:add("includedirs", importPath, {public = true })

        if reflection_level == nil then
            if not with_source then
                for _, item in ipairs(remove_key_compiler) do
                    item.path = importPath
                end
            end
            for _, item in ipairs(remove_key_compiler) do
                target:remove("headerfiles", path.join(item.path, item.file .. ".h"))
                target:remove("files", path.join(item.path, item.file .. ".cpp"))
            end
        elseif reflection_level == "full" then
            -- do nothing，包含compiler代码
        else
            -- todo: metaonly选项还需测试
            if reflection_level == "none" then
                target:add("defines", "VCZH_DEBUG_NO_REFLECTION", {public = true })
            elseif reflection_level == "metaonly" then
                target:add("defines", "VCZH_DEBUG_METAONLY_REFLECTION", {public = true })
            end

            for _, item in ipairs(remove_key_reflection) do
                if not with_source then
                    for _, item in ipairs(remove_key_reflection) do
                        item.path = importPath

                        target:remove("headerfiles", path.join(importPath, "Skins/DarkSkin/DarkSkinReflection.h"))
                        target:remove("files", path.join(importPath, "Skins/DarkSkin/DarkSkinReflection.cpp"))
                    end
                end
                target:remove("headerfiles", path.join(item.path, item.file .. ".h"))
                target:remove("files", path.join(item.path, item.file .. ".cpp"))
            end
        end

        if is_plat("windows") then
            target:add("links", "user32", "gdi32", "ole32", "advapi32", "comdlg32")
            target:add("cxflags", "/bigobj")
            if with_source then
                target:remove("files",path.join(src_paths["vl"],"Vlpp.Linux.cpp"))
                target:remove("files",path.join(src_paths["os"],"VlppOS.Linux.cpp"))
            else
                target:remove("files",path.join(importPath,"Vlpp.Linux.cpp"))
                target:remove("files",path.join(importPath,"VlppOS.Linux.cpp"))
            end
        elseif is_plat("linux") then
            -- todo: 未测试!!!可能需要一些编译参数
            if with_source then
                target:remove("files",path.join(src_paths["vl"],"Vlpp.Windows.cpp"))
                target:remove("files",path.join(src_paths["os"],"VlppOS.Windows.cpp"))
            else
                target:remove("files",path.join(importPath,"Vlpp.Windows.cpp"))
                target:remove("files",path.join(importPath,"VlppOS.Windows.cpp"))
            end
        end
        
        if not with_unitest then
            if with_source then
                target:remove("headerfiles", path.join(src_paths["ui"], "GacUI.UnitTest*.h"))
                target:remove("files", path.join(src_paths["ui"], "GacUI.UnitTest*.cpp"))
            else
                target:remove("headerfiles", path.join(importPath, "GacUI.UnitTest*.h"))
                target:remove("files", path.join(importPath, "GacUI.UnitTest*.cpp"))
            end
        end
    end)

rule_end()


target("GacUICustom")
    set_kind("phony")
    set_languages("cxx20")
    set_group("libgacui")
    set_default(false)

target_end()


target("GacUILite")
    set_kind("static")
    set_languages("cxx20")
    set_group("libgacui")
    set_default(false)

    add_rules("GacUI")
    set_values("GacUI.reflection_level", "none")

target_end()


target("GacUI")
    set_kind("static")
    set_languages("cxx20")
    set_group("libgacui")
    set_default(false)

    add_rules("GacUI")
    set_values("GacUI.reflection_level", nil)

target_end()


target("GacUIComplete")
    set_kind("static")
    set_languages("cxx20")
    set_group("libgacui")
    set_default(false)

    add_rules("GacUI")
    set_values("GacUI.reflection_level", "full")

target_end()


-- todo: 由于包含大量无用代码，tools组编译结果体积较大
target("CppMerge")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUILite")
    add_files(path.join(src_paths["cm"],"Main.cpp"))

target_end()


target("GacGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_defines("VCZH_DEBUG_METAONLY_REFLECTION")
    add_files(path.join(src_paths["gg"],"**.cpp"))

target_end()


target("GlrParserGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_files(path.join(src_paths["gp"],"**.cpp"))

target_end()


target("CodePack")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUILite")
    add_files(path.join(src_paths["cp"],"**.cpp"))

target_end()