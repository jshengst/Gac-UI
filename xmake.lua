
add_rules("mode.debug", "mode.release")

if is_mode("debug") then -- todo: 优化编译参数
    add_cxflags("/W3", "/sdl", "/permissive-")
    add_cxflags("/MTd", {public = true })
else
    add_cxflags("/W3", "/sdl", "/permissive-", "/GL")
    add_ldflags("/LTCG")
    add_cxflags("/MTd", {public = true })
end

-- includes("gacui.lua")
includes("gactool.lua")

-- target("HelloGacUI")
--     set_languages("cxx20")
--     set_kind("binary")

--     add_deps("GacUICustom")
--     add_rules("GacUI")
--     set_values("GacUI.reflection_level", "none")
--     set_values("GacUI.with_source", true) -- 切换使用未合并源代码

--     add_files(path.join(os.projectdir(),"Release","Tutorial","Lib","GacUI","WinMain.cpp"))
--     add_files(path.join(os.projectdir(),"Release","Tutorial","GacUI_HelloWorlds","Cpp","Main.cpp"))

-- target_end()