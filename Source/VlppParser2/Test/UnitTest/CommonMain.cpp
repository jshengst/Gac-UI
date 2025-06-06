#include <VlppOS.h>
#ifdef VCZH_MSVC
#include <Windows.h>
#endif

using namespace vl;
using namespace vl::console;
using namespace vl::collections;
using namespace vl::stream;
using namespace vl::filesystem;

#ifdef VCZH_MSVC
WString GetExePath()
{
	wchar_t buffer[65536];
	GetModuleFileName(NULL, buffer, sizeof(buffer) / sizeof(*buffer));
	vint pos = -1;
	vint index = 0;
	while (buffer[index])
	{
		if (buffer[index] == L'\\' || buffer[index] == L'/')
		{
			pos = index;
		}
		index++;
	}
	return WString::CopyFrom(buffer, pos + 1);
}
#endif

WString GetSourcePath()
{
#if defined VCZH_GCC
	return L"../../../Source/";
#elif defined _WIN64
	return GetExePath() + L"../../../../Source/";
#else
	return GetExePath() + L"../../../Source/";
#endif
}

WString GetTestParserInputPath(const WString& parserName)
{
#if defined VCZH_GCC
	return L"../../Source/" + parserName + L"/";
#elif defined _WIN64
	return GetExePath() + L"../../../Source/" + parserName + L"/";
#else
	return GetExePath() + L"../../Source/" + parserName + L"/";
#endif
}

WString GetTestOutputPath()
{
#if defined VCZH_GCC
	return L"../../ParserLog/";
#elif defined _WIN64
	return GetExePath() + L"../../../ParserLog/";
#else
	return GetExePath() + L"../../ParserLog/";
#endif
}

WString GetParserGenGeneratedOutputPath()
{
	return GetTestOutputPath() + L"../../Source/ParserGen_Generated/";
}

FilePath GetOutputDir(const WString& parserName)
{
	auto outputDir = FilePath(GetTestOutputPath()) / parserName;
	{
		Folder folder = outputDir;
		if (!folder.Exists())
		{
			folder.Create(true);
		}
	}
	return outputDir;
}

void WriteFilesIfChanged(FilePath outputDir, Dictionary<WString, WString>& files)
{
#if defined VCZH_MSVC
	for (auto [key, index] : indexed(files.Keys()))
	{
		File outputFile = outputDir / key;
		auto content = files.Values()[index];
		if (outputFile.Exists())
		{
			auto existing = outputFile.ReadAllTextByBom();
			if (content == existing)
			{
				continue;
			}
		}
		outputFile.WriteAllText(content, false, BomEncoder::Utf8);
	}
#elif defined VCZH_GCC
	Console::WriteLine(L"**** Skipped updating C++ files in Linux ****");
#endif
}

TEST_FILE
{
	TEST_CASE_ASSERT(Folder(GetTestOutputPath()).Exists());
}

using TExecutor = void(*)(void);

TExecutor runBeforeTests = nullptr;
TExecutor runAfterTests = nullptr;

void SetRunBeforeTests(TExecutor value)
{
	runBeforeTests = value;
}

void SetRunAfterTests(TExecutor value)
{
	runAfterTests = value;
}

#if defined VCZH_MSVC
int wmain(int argc, wchar_t* argv[])
#elif defined VCZH_GCC
int main(int argc, char* argv[])
#endif
{
	{
		Folder folder(GetTestOutputPath());
		if (!folder.Exists())
		{
			folder.Create(false);
		}
	}
	if (runBeforeTests) runBeforeTests();
	int result = unittest::UnitTest::RunAndDisposeTests(argc, argv);
	if (runAfterTests) runAfterTests();
	FinalizeGlobalStorage();
#ifdef VCZH_CHECK_MEMORY_LEAKS
	_CrtDumpMemoryLeaks();
#endif
	return result;
}