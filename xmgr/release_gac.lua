
-- 指定代码路径
local importPath = path.join(os.projectdir(), "Import")

rule("GacUI")

    on_load(function(target)

        -- 反射等级: 无反射(none)、仅类型反射(metaonly)、全反射(full)
        local reflection_level = target:values("GacUI.reflection_level")
        -- 包含单元测试
        -- todo: 增加更多单元测试的配置参数
        local with_unitest = target:values("GacUI.with_unitest")

        target:add("defines", "_UNICODE", "UNICODE")
        target:add("cxflags", "/utf-8")
        target:add("includedirs", importPath, {public = true })
        target:add("headerfiles", path.join(importPath, "**.h"))
        target:add("files", path.join(importPath, "**.cpp"))
        
        if reflection_level == nil then -- 默认为全反射且不包含Compiler
            target:remove("headerfiles", path.join(importPath,"GacUICompiler.h"))
            target:remove("headerfiles", path.join(importPath,"VlppWorkflowCompiler.h"))
            target:remove("files", path.join(importPath,"GacUICompiler.cpp"))
            target:remove("files", path.join(importPath,"VlppWorkflowCompiler.cpp"))
        elseif reflection_level == "full" then
            -- do nothing
        else
            -- todo: metaonly选项还需测试
            if reflection_level == "none" then
                target:add("defines", "VCZH_DEBUG_NO_REFLECTION", {public = true })
            elseif reflection_level == "metaonly" then
                target:add("defines", "VCZH_DEBUG_METAONLY_REFLECTION", {public = true })
            end
            
            target:remove("headerfiles", path.join(importPath, "Skins/DarkSkin/DarkSkinReflection.h"))
            target:remove("headerfiles", path.join(importPath, "GacUICompiler.h"))
            target:remove("headerfiles", path.join(importPath, "GacUIReflection.h"))
            target:remove("headerfiles", path.join(importPath, "VlppGlrParserCompiler.h"))
            target:remove("headerfiles", path.join(importPath, "VlppWorkflowCompiler.h"))
            target:remove("headerfiles", path.join(importPath, "VlppWorkflowRuntime.h"))            
            target:remove("files", path.join(importPath, "Skins/DarkSkin/DarkSkinReflection.cpp"))
            target:remove("files", path.join(importPath, "GacUICompiler.cpp"))
            target:remove("files", path.join(importPath, "GacUIReflection.cpp"))
            target:remove("files", path.join(importPath, "VlppGlrParserCompiler.cpp"))
            target:remove("files", path.join(importPath, "VlppWorkflowCompiler.cpp"))
            target:remove("files", path.join(importPath, "VlppWorkflowRuntime.cpp"))
            
        end
        
        if is_plat("windows") then
            target:add("links", "user32", "gdi32", "ole32", "advapi32", "comdlg32")
            target:add("cxflags", "/bigobj")
            target:remove("files", path.join(importPath, "Vlpp.Linux.cpp"))
            target:remove("files", path.join(importPath, "VlppOS.Linux.cpp"))
        elseif is_plat("linux") then
            -- todo: 未测试!!!可能需要一些编译参数
            target:remove("files", path.join(importPath, "Vlpp.Windows.cpp"))
            target:remove("files", path.join(importPath, "VlppOS.Windows.cpp"))
        end
        
        if with_unitest then
            -- do nothing
        else
            target:remove("headerfiles", path.join(importPath, "GacUI.Unit*.h"))
            target:remove("files", path.join(importPath, "GacUI.Unit*.cpp"))
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
    add_files(path.join(os.projectdir(),"Tools","Executables","CppMerge","*.cpp"))

target_end()


target("GacGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_defines("VCZH_DEBUG_METAONLY_REFLECTION")
    add_files(path.join(os.projectdir(),"Tools","Executables","GacGen","*.cpp"))

target_end()


target("GlrParserGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_files(path.join(os.projectdir(),"Tools","Executables","GlrParserGen","*.cpp"))

target_end()


target("CodePack")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUILite")
    add_files(path.join(os.projectdir(),"Tools","Executables","CodePack","*.cpp"))

target_end()