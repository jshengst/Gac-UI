
-- ====================Config Path====================

local import_Path = path.join(os.scriptdir(), "Release", "Import")
local tool_Path = path.join(os.scriptdir(), "Release", "Tools", "Executables")


-- ====================Tool Target====================

target("CppMerge")
    set_languages("cxx20")
    set_kind("binary")
    set_group("gactools")
    set_default(false)
    add_defines("_UNICODE", "UNICODE")

    add_includedirs(import_Path)
    add_files(path.join(import_Path, "Vlpp.cpp"))
    add_files(path.join(import_Path, "VlppOS.cpp"))
    add_files(path.join(import_Path, "VlppRegex.cpp"))
    add_files(path.join(tool_Path, "CppMerge", "**.cpp"))

    if is_plat("windows") then
        add_cxflags("/utf-8", "/bigobj")
        add_links("user32", "gdi32", "ole32", "advapi32", "comdlg32")
        add_files(path.join(import_Path, "Vlpp.Windows.cpp"))
        add_files(path.join(import_Path, "VlppOS.Windows.cpp"))

    elseif is_plat("linux") then -- todo: 未测试
        add_files(path.join(import_Path, "Vlpp.Linux.cpp"))
        add_files(path.join(import_Path, "VlppOS.Linux.cpp"))

    end

target_end()


target("GacGen")
    set_languages("cxx20")
    set_kind("binary")
    set_group("gactools")
    set_default(false)
    add_defines("_UNICODE", "UNICODE")
    add_defines("VCZH_DEBUG_METAONLY_REFLECTION")
    
    add_includedirs(import_Path)
    add_files(path.join(import_Path, "GacUI.cpp"))
    add_files(path.join(import_Path, "GacUICompiler.cpp"))
    add_files(path.join(import_Path, "GacUIReflection.cpp"))
    add_files(path.join(import_Path, "Vlpp.cpp"))
    add_files(path.join(import_Path, "VlppGlrParser.cpp"))
    add_files(path.join(import_Path, "VlppOS.cpp"))
    add_files(path.join(import_Path, "VlppParser.cpp"))
    add_files(path.join(import_Path, "VlppReflection.cpp"))
    add_files(path.join(import_Path, "VlppRegex.cpp"))
    add_files(path.join(import_Path, "VlppWorkflowCompiler.cpp"))
    add_files(path.join(import_Path, "VlppWorkflowLibrary.cpp"))
    add_files(path.join(import_Path, "VlppWorkflowRuntime.cpp"))
    add_files(path.join(tool_Path, "GacGen", "**.cpp"))
    
    if is_plat("windows") then
        add_cxflags("/utf-8", "/bigobj")
        add_links("user32", "gdi32", "ole32", "advapi32", "comdlg32")
        add_files(path.join(import_Path, "Vlpp.Windows.cpp"))
        add_files(path.join(import_Path, "VlppOS.Windows.cpp"))

    elseif is_plat("linux") then
        add_files(path.join(import_Path, "Vlpp.Linux.cpp"))
        add_files(path.join(import_Path, "VlppOS.Linux.cpp"))

    end

target_end()


target("GlrParserGen")
    set_languages("cxx20")
    set_kind("binary")
    set_group("gactools")
    set_default(false)
    add_defines("_UNICODE", "UNICODE")

    add_includedirs(import_Path)
    add_files(path.join(import_Path, "Vlpp.cpp"))
    add_files(path.join(import_Path, "VlppGlrParser.cpp"))
    add_files(path.join(import_Path, "VlppGlrParserCompiler.cpp"))
    add_files(path.join(import_Path, "VlppOS.cpp"))
    add_files(path.join(import_Path, "VlppReflection.cpp"))
    add_files(path.join(import_Path, "VlppRegex.cpp"))
    add_files(path.join(tool_Path, "GlrParserGen", "**.cpp"))

    if is_plat("windows") then
        add_cxflags("/utf-8", "/bigobj")
        add_links("user32", "gdi32", "ole32", "advapi32", "comdlg32")
        add_files(path.join(import_Path, "Vlpp.Windows.cpp"))
        add_files(path.join(import_Path, "VlppOS.Windows.cpp"))

    elseif is_plat("linux") then
        add_files(path.join(import_Path, "Vlpp.Linux.cpp"))
        add_files(path.join(import_Path, "VlppOS.Linux.cpp"))

    end
    
target_end()


target("CodePack")
    set_languages("cxx20")
    set_kind("binary")
    set_group("gactools")
    set_default(false)
    add_defines("_UNICODE", "UNICODE")

    add_includedirs(import_Path)
    add_files(path.join(import_Path, "Vlpp.cpp"))
    add_files(path.join(import_Path, "VlppGlrParser.cpp"))
    add_files(path.join(import_Path, "VlppOS.cpp"))
    add_files(path.join(import_Path, "VlppReflection.cpp"))
    add_files(path.join(import_Path, "VlppRegex.cpp"))
    add_files(path.join(tool_Path, "CodePack","**.cpp"))

    if is_plat("windows") then
        add_cxflags("/utf-8", "/bigobj")
        add_links("user32", "gdi32", "ole32", "advapi32", "comdlg32")
        add_files(path.join(import_Path, "Vlpp.Windows.cpp"))
        add_files(path.join(import_Path, "VlppOS.Windows.cpp"))

    elseif is_plat("linux") then
        add_files(path.join(import_Path, "Vlpp.Linux.cpp"))
        add_files(path.join(import_Path, "VlppOS.Linux.cpp"))

    end
target_end()