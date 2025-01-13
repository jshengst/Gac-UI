
-- 指定代码路径
local source_path = path.join(os.projectdir(),"Source")

local cg_src = path.join(source_path,"GacUI","Tools","GacGen","GacGen")
local cp_src = path.join(source_path,"VlppParser2","Tools","CodePack","CodePack")
local gp_src = path.join(source_path,"VlppParser2","Tools","GlrParserGen","GlrParserGen")
local cm_src = path.join(source_path,"Workflow","Tools","CppMerge","CppMerge")
local vl_src = path.join(source_path,"Vlpp","Release","IncludeOnly")
local ui_src = path.join(source_path,"GacUI","Release","IncludeOnly")
local vo_src = path.join(source_path,"VlppOS","Release","IncludeOnly")
local wf_src = path.join(source_path,"Workflow","Release","IncludeOnly")
local vr_src = path.join(source_path,"VlppRegex","Release","IncludeOnly")
local vp_src = path.join(source_path,"VlppParser","Release","IncludeOnly")
local v2_src = path.join(source_path,"VlppParser2","Release","IncludeOnly")
local vf_src = path.join(source_path,"VlppReflection","Release","IncludeOnly")
-- 仅用于修复WinMain.cpp的路径问题：Skins\DarkSkin\DarkSkin.h
local is_src = path.join(os.projectdir(),"Import")


rule("GacUI")

    on_load(function(target)

        -- 反射等级: 无反射(none)、仅类型反射(metaonly)、全反射(full)
        local reflection_level = target:values("GacUI.reflection_level")
        -- 启用包含单元测试
        -- todo: 增加更多单元测试的配置参数
        local with_unitest = target:values("GacUI.with_unitest")

        target:add("defines", "_UNICODE", "UNICODE")
        target:add("cxflags", "/utf-8")

        target:add("includedirs", is_src, {public = true })
        target:add("includedirs", vp_src,vr_src,vo_src,vf_src,{public = true})
        target:add("includedirs", vl_src,ui_src,wf_src,v2_src,{public = true})
        target:add("headerfiles", path.join(vp_src,"**.h"))
        target:add("headerfiles", path.join(vr_src,"**.h"))
        target:add("headerfiles", path.join(vo_src,"**.h"))
        target:add("headerfiles", path.join(vf_src,"**.h"))
        target:add("headerfiles", path.join(vl_src,"**.h"))
        target:add("headerfiles", path.join(ui_src,"**.h"))
        target:add("headerfiles", path.join(wf_src,"**.h"))
        target:add("headerfiles", path.join(v2_src,"**.h"))
        target:add("files", path.join(vp_src,"**.cpp"))
        target:add("files", path.join(vr_src,"**.cpp"))
        target:add("files", path.join(vo_src,"**.cpp"))
        target:add("files", path.join(vf_src,"**.cpp"))
        target:add("files", path.join(vl_src,"**.cpp"))
        target:add("files", path.join(ui_src,"**.cpp"))
        target:add("files", path.join(wf_src,"**.cpp"))
        target:add("files", path.join(v2_src,"**.cpp"))
        
        if reflection_level == nil then
            target:remove("headerfiles", path.join(ui_src,"GacUICompiler.h"))
            target:remove("headerfiles", path.join(wf_src,"VlppWorkflowCompiler.h"))
            target:remove("files", path.join(ui_src,"GacUICompiler.cpp"))
            target:remove("files", path.join(wf_src,"VlppWorkflowCompiler.cpp"))
        elseif reflection_level == "full" then
            -- do nothing
        else
            -- todo: metaonly选项还需测试
            if reflection_level == "none" then
                target:add("defines", "VCZH_DEBUG_NO_REFLECTION", {public = true })
            elseif reflection_level == "metaonly" then
                target:add("defines", "VCZH_DEBUG_METAONLY_REFLECTION", {public = true })
            end
            
            target:remove("headerfiles", path.join(ui_src, "DarkSkinReflection.h"))
            target:remove("headerfiles", path.join(ui_src, "GacUICompiler.h"))
            target:remove("headerfiles", path.join(ui_src, "GacUIReflection.h"))
            target:remove("headerfiles", path.join(v2_src, "VlppGlrParserCompiler.h"))
            target:remove("headerfiles", path.join(wf_src, "VlppWorkflowCompiler.h"))
            target:remove("headerfiles", path.join(wf_src, "VlppWorkflowRuntime.h"))
            target:remove("files", path.join(ui_src, "DarkSkinReflection.cpp"))
            target:remove("files", path.join(ui_src, "GacUICompiler.cpp"))
            target:remove("files", path.join(ui_src, "GacUIReflection.cpp"))
            target:remove("files", path.join(v2_src, "VlppGlrParserCompiler.cpp"))
            target:remove("files", path.join(wf_src, "VlppWorkflowCompiler.cpp"))
            target:remove("files", path.join(wf_src, "VlppWorkflowRuntime.cpp"))

        end

        if is_plat("windows") then
            target:add("links", "user32", "gdi32", "ole32", "advapi32", "comdlg32")
            target:add("cxflags", "/bigobj")
            target:remove("files",path.join(vl_src,"Vlpp.Linux.cpp"))
            target:remove("files",path.join(vo_src,"VlppOS.Linux.cpp"))
        elseif is_plat("linux") then
            -- todo: 未测试!!!可能需要一些编译参数
            target:remove("files",path.join(vl_src,"Vlpp.Windows.cpp"))
            target:remove("files",path.join(vo_src,"VlppOS.Windows.cpp"))
        end
        
        if with_unitest then
            -- do nothing
        else
            target:remove("headerfiles", path.join(ui_src, "GacUI.UnitTest*.h"))
            target:remove("files", path.join(ui_src, "GacUI.UnitTest*.cpp"))
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
    add_files(path.join(cm_src,"Main.cpp"))

target_end()


target("GacGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_defines("VCZH_DEBUG_METAONLY_REFLECTION")
    add_files(path.join(cg_src,"**.cpp"))

target_end()


target("GlrParserGen")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUIComplete")
    add_files(path.join(gp_src,"**.cpp"))

target_end()


target("CodePack")
    set_languages("c++20")
    set_kind("binary")
    set_group("tools")
    set_default(false)
    add_deps("GacUILite")
    add_files(path.join(cp_src,"**.cpp"))

target_end()