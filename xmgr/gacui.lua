
-- 指定代码路径
local source_path = path.join(os.projectdir(),"Source")
local import_Path = path.join(os.projectdir(),"Import")

local src_tools_paths = {
    gg = path.join(source_path,"GacUI","Tools","GacGen","GacGen"),
    cp = path.join(source_path,"VlppParser2","Tools","CodePack","CodePack"),
    gp = path.join(source_path,"VlppParser2","Tools","GlrParserGen","GlrParserGen"),
    cm = path.join(source_path,"Workflow","Tools","CppMerge","CppMerge"),
}
local import_tools_paths = {
    gg = path.join(os.projectdir(), "Tools", "Executables", "GacGen"),
    cp = path.join(os.projectdir(), "Tools", "Executables", "CodePack"),
    gp = path.join(os.projectdir(), "Tools", "Executables", "GlrParserGen"),
    cm = path.join(os.projectdir(), "Tools", "Executables", "CppMerge"),
}
-- 定义包含路径的字典
local src_paths = {
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
local remove_src_compiler = {
    {path = src_paths["ui"], file = "GacUICompiler"},
    {path = src_paths["wf"], file = "VlppWorkflowCompiler"}
}
local remove_import_compiler = {
    {path = import_Path, file = "GacUICompiler"},
    {path = import_Path, file = "VlppWorkflowCompiler"}
}
-- 定义移除reflection的路径键
local remove_src_reflection = {
    {path = src_paths["ui"], file = "DarkSkinReflection"},
    {path = src_paths["ui"], file = "GacUICompiler"},
    {path = src_paths["ui"], file = "GacUIReflection"},
    {path = src_paths["v2"], file = "VlppGlrParserCompiler"},
    {path = src_paths["wf"], file = "VlppWorkflowCompiler"},
    {path = src_paths["wf"], file = "VlppWorkflowRuntime"}
}
local remove_import_reflection = {
    {path = path.join(import_Path, "Skins/DarkSkin"), file = "DarkSkinReflection"},
    {path = import_Path, file = "GacUICompiler"},
    {path = import_Path, file = "GacUIReflection"},
    {path = import_Path, file = "VlppGlrParserCompiler"},
    {path = import_Path, file = "VlppWorkflowCompiler"},
    {path = import_Path, file = "VlppWorkflowRuntime"}
}


rule("GacUI")

    on_load(function(target)

        -- 反射等级: 无反射(none)、仅类型反射(metaonly)、全反射(full)
        local reflection_level = target:values("GacUI.reflection_level")
        -- 启用source代码
        local with_source = target:values("GacUI.with_source")
        -- 启用单元测试
        -- todo: 增加更多单元测试的配置参数
        local with_unitest = target:values("GacUI.with_unitest")

        target:add("defines", "_UNICODE", "UNICODE")
        target:add("cxflags", "/utf-8")

        -- 添加所有代码
        if with_source then
            if not os.isdir(path.join(os.projectdir(), "Source")) then
                raise("Directory does not exist: " .. path.join(os.projectdir(), "Source"))
            end
            for _, key in pairs(src_paths) do
                target:add("includedirs", path, {public = true})
                target:add("headerfiles", path.join(key, "**.h"))
                target:add("files", path.join(key, "**.cpp"))
            end
        else
            if not os.isdir(path.join(os.projectdir(), "Import")) then
                raise("Directory does not exist: " .. path.join(os.projectdir(), "Import"))
            end
            target:add("includedirs", import_Path, {public = true })
            target:add("headerfiles", path.join(import_Path, "**.h"))
            target:add("files", path.join(import_Path, "**.cpp"))
        end

        -- 用于修复WinMain.cpp的路径问题：Skins\DarkSkin\DarkSkin.h
        target:add("includedirs", import_Path, {public = true })

        if reflection_level == nil then
            if with_source then
                for _, item in ipairs(remove_src_compiler) do
                    target:remove("headerfiles", path.join(item.path, item.file .. ".h"))
                    target:remove("files", path.join(item.path, item.file .. ".cpp"))
                end
            else
                for _, item in ipairs(remove_import_compiler) do
                    target:remove("headerfiles", path.join(item.path, item.file .. ".h"))
                    target:remove("files", path.join(item.path, item.file .. ".cpp"))
                end
            end
        elseif reflection_level == "full" then
            -- do nothing，包含compiler代码
        else
            -- todo: metaonly选项未测试
            if reflection_level == "none" then
                target:add("defines", "VCZH_DEBUG_NO_REFLECTION", {public = true })
            elseif reflection_level == "metaonly" then
                target:add("defines", "VCZH_DEBUG_METAONLY_REFLECTION", {public = true })
            end

            if with_source then
                for _, item in ipairs(remove_src_reflection) do
                    target:remove("headerfiles", path.join(item.path, item.file .. ".h"))
                    target:remove("files", path.join(item.path, item.file .. ".cpp"))
                end
            else
                for _, item in ipairs(remove_import_reflection) do
                    target:remove("headerfiles", path.join(item.path, item.file .. ".h"))
                    target:remove("files", path.join(item.path, item.file .. ".cpp"))
                end
            end
        end

        if is_plat("windows") then
            target:add("links", "user32", "gdi32", "ole32", "advapi32", "comdlg32")
            target:add("cxflags", "/bigobj")
            if with_source then
                target:remove("files",path.join(src_paths["vl"],"Vlpp.Linux.cpp"))
                target:remove("files",path.join(src_paths["os"],"VlppOS.Linux.cpp"))
            else
                target:remove("files",path.join(import_Path,"Vlpp.Linux.cpp"))
                target:remove("files",path.join(import_Path,"VlppOS.Linux.cpp"))
            end
        elseif is_plat("linux") then
            -- todo: 未测试
            if with_source then
                target:remove("files",path.join(src_paths["vl"],"Vlpp.Windows.cpp"))
                target:remove("files",path.join(src_paths["os"],"VlppOS.Windows.cpp"))
            else
                target:remove("files",path.join(import_Path,"Vlpp.Windows.cpp"))
                target:remove("files",path.join(import_Path,"VlppOS.Windows.cpp"))
            end
        end
        
        if not with_unitest then
            if with_source then
                target:remove("headerfiles", path.join(src_paths["ui"], "GacUI.UnitTest*.h"))
                target:remove("files", path.join(src_paths["ui"], "GacUI.UnitTest*.cpp"))
            else
                target:remove("headerfiles", path.join(import_Path, "GacUI.UnitTest*.h"))
                target:remove("files", path.join(import_Path, "GacUI.UnitTest*.cpp"))
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
    add_deps("GacUIComplete")
    add_files(path.join(import_tools_paths["cm"],"Main.cpp"))   -- source_path中没用WfMergeCpp.h

target_end()


target("GacGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_defines("VCZH_DEBUG_METAONLY_REFLECTION")
    add_files(path.join(src_tools_paths["gg"],"**.cpp"))

target_end()


target("GlrParserGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_files(path.join(src_tools_paths["gp"],"**.cpp"))

target_end()


target("CodePack")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUILite")
    add_files(path.join(src_tools_paths["cp"],"**.cpp"))

target_end()