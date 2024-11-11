add_rules("mode.debug", "mode.release")
local lib_src = path.join(os.projectdir(),"Import")

local function check_gacui_src(is_no_flection)
    set_languages("c++20")
    add_files(path.join(lib_src,"**.cpp"))
    add_headerfiles(path.join(lib_src,"**.h"))
    add_includedirs(lib_src,{public = true})
    add_defines( "UNICODE", "_UNICODE")
    add_cxflags("/execution-charset:utf-8")
    set_group("libgacui")

    if is_no_flection then
        add_defines("VCZH_DEBUG_NO_REFLECTION")
        remove_files(path.join(lib_src,"VlppWorkflowRuntime.cpp"))
        remove_headerfiles(path.join(lib_src,"VlppWorkflowRuntime.h"))
        remove_files(path.join(lib_src,"GacUIReflection.cpp"))
        remove_headerfiles(path.join(lib_src,"GacUIReflection.h"))
        remove_files(path.join(lib_src,"Skins","DarkSkin","DarkSkinReflection.cpp"))
        remove_headerfiles(path.join(lib_src,"Skins","DarkSkin","DarkSkinReflection.h"))
    end

    on_load(function(target)

        target:remove("files",path.join(lib_src,"GacUICompiler.cpp"))
        target:remove("files",path.join(lib_src,"VlppWorkflowCompiler.cpp"))
        target:remove("headerfiles",path.join(lib_src,"GacUICompiler.h"))
        target:remove("headerfiles",path.join(lib_src,"VlppWorkflowCompiler.h"))
        target:remove("files",path.join(lib_src,"GacUI.UnitTest*.cpp"))
        target:remove("headerfiles",path.join(lib_src,"GacUI.UnitTest*.h"))
        if is_plat("windows") then
            target:remove("files",path.join(lib_src,"Vlpp.Linux.cpp"))
            target:remove("files",path.join(lib_src,"VlppOS.Linux.cpp"))
            target:add("cxflags","/bigobj")
            target:add("defines","WIN32","_WINDOWS",{public = true})
            target:add("ldflags", "/subsystem:windows",{public = true})
            target:add("syslinks","kernel32","user32","gdi32","comdlg32","ole32","advapi32")
        else
            target:remove("files",path.join(lib_src,"Vlpp.Windows.cpp"))
            target:remove("files",path.join(lib_src,"VlppOS.Windows.cpp"))
        end
    end)
end


target("GacUILite")
    set_kind("static")
    check_gacui_src(true)

target("GacUI")
    set_kind("static")
    check_gacui_src()

target("GacUIComplete")
    set_languages("c++20")
    add_deps("GacUI")
    set_kind("static")
    set_group("libgacui")
    add_files(path.join(lib_src,"GacUICompiler.cpp"))
    add_files(path.join(lib_src,"VlppWorkflowCompiler.cpp"))
    add_headerfiles(path.join(lib_src,"GacUICompiler.cpp"))
    add_headerfiles(path.join(lib_src,"VlppWorkflowCompiler.cpp"))
    on_load(function(target)
        if is_plat("windows") then
            target:add("cxflags","/bigobj")
        end
    end)
target_end()
