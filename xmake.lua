
add_rules("mode.debug", "mode.release")


includes("xmake_script/gacui.lua")

target("HelloGacUI")
    set_languages("c++20")
    set_kind("binary")

    add_deps("GacUICustom")
    add_rules("GacUI")
    set_values("GacUI.reflection_level", "none") -- 切换反射等级
    set_values("GacUI.with_source", true) -- 切换使用未合并源代码
    set_values("GacUI.with_unitest", false ) -- 切换是否包含单元测试代码

    add_files(path.join(os.projectdir(),"Release","Tutorial","Lib","GacUI","WinMain.cpp"))
    add_files(path.join(os.projectdir(),"Release","Tutorial","GacUI_HelloWorlds","Cpp","Main.cpp"))

target_end()