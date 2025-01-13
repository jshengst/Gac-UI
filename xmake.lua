
-- 测试命令:xmake f --use_release_code=true

add_rules("mode.debug", "mode.release")

-- todo: 优化编译参数，减少编译时间和生成文件大小
if is_mode("debug") then
    -- add_defines("WIN32", "_DEBUG", "_LIB")
    add_cxflags("/W3", "/sdl", "/permissive-")
    add_cxflags("/MTd", {public = true })
else
    -- add_defines("WIN32", "NDEBUG", "_LIB")
    add_cxflags("/W3", "/sdl", "/permissive-", "/GL")
    add_ldflags("/LTCG")
    add_cxflags("/MTd", {public = true })
end

-- 定义配置选项
option("use_release_code")
    set_default(true)
    set_showmenu(true)
    set_description("Building GacUI from Source version or Release version")

    if has_config("use_release_code") then
        includes("xmgr/release_gac.lua")
        print("Building GacUI from Release version") -- 还需要优化，不应该多次打印!!!
    else
        includes("xmgr/source_gac.lua")
        print("Building GacUI from Source version")
    end
option_end()


target("HelloGacUI")
    set_languages("c++20")
    set_kind("binary")

    add_deps("GacUICustom")
    add_rules("GacUI")
    set_values("GacUI.reflection_level", "none")

    add_files(path.join(os.projectdir(),"Tutorial","Lib","GacUI","WinMain.cpp"))
    add_files(path.join(os.projectdir(),"Tutorial","GacUI_HelloWorlds","Cpp","Main.cpp"))

target_end()