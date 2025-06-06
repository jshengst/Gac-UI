#include "SyntaxCppGen.h"
#include "../Ast/AstSymbol.h"

namespace vl
{
	namespace glr
	{
		namespace parsergen
		{
			using namespace collections;
			using namespace stream;
			using namespace regex;

/***********************************************************************
GenerateSyntaxFileNames
***********************************************************************/

			Ptr<CppSyntaxGenOutput> GenerateSyntaxFileNames(SyntaxSymbolManager& manager, Ptr<CppParserGenOutput> output)
			{
				auto syntaxOutput = Ptr(new CppSyntaxGenOutput);
				syntaxOutput->syntaxH = manager.Global().name + manager.name + L".h";
				syntaxOutput->syntaxCpp = manager.Global().name + manager.name + L".cpp";
				output->syntaxOutputs.Add(&manager, syntaxOutput);
				return syntaxOutput;
			}

			WString AstClassSymbolToString(AstClassSymbol* astType)
			{
				return GenerateToStream([&](StreamWriter& writer)
				{
					WriteNssName(astType->Owner()->Owner()->cppNss, writer);
					writer.WriteString(L"::");
					writer.WriteString(astType->Owner()->Owner()->classPrefix);
					writer.WriteString(astType->Name());
				});
			}

/***********************************************************************
WriteSyntaxHeaderFile
***********************************************************************/

			void WriteSyntaxHeaderFile(SyntaxSymbolManager& manager, automaton::Executable& executable, automaton::Metadata& metadata, Ptr<CppParserGenOutput> output, stream::StreamWriter& writer)
			{
				WriteFileComment(manager.Global().name, writer);
				if (manager.Global().headerGuard != L"")
				{
					writer.WriteString(L"#ifndef ");
					writer.WriteLine(manager.Global().headerGuard + L"_" + wupper(manager.name) + L"_SYNTAX");
					writer.WriteString(L"#define ");
					writer.WriteLine(manager.Global().headerGuard + L"_" + wupper(manager.name) + L"_SYNTAX");
				}
				else
				{
					writer.WriteLine(L"#pragma once");
				}
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + output->assemblyH + L"\"");
				writer.WriteLine(L"#include \"" + output->lexerH +L"\"");
				writer.WriteLine(L"");

				WString prefix = WriteNssBegin(manager.Global().cppNss, writer);
				{
					writer.WriteLine(prefix + L"enum class " + manager.name + L"States");
					writer.WriteLine(prefix + L"{");
					for (auto&& [ruleName, index] : indexed(metadata.ruleNames))
					{
						writer.WriteLine(prefix + L"\t" + ruleName + L" = " + itow(executable.ruleStartStates[index]) + L",");
					}
					writer.WriteLine(prefix + L"};");
				}
				{
					writer.WriteLine(L"");
					writer.WriteLine(prefix + L"const wchar_t* " + manager.name + L"RuleName(vl::vint index);");
					writer.WriteLine(prefix + L"const wchar_t* " + manager.name + L"StateLabel(vl::vint index);");
					WriteLoadDataFunctionHeader(prefix, manager.Global().name + manager.name + L"Data", writer);
				}
				{
					writer.WriteLine(L"");
					writer.WriteLine(prefix + L"class " + manager.name);
					writer.WriteString(prefix+L"\t: public vl::glr::ParserBase<");
					writer.WriteString(manager.Global().name + L"Tokens, ");
					writer.WriteString(manager.name + L"States, ");
					writer.WriteLine(manager.Global().name + L"AstInsReceiver>");
					writer.WriteLine(prefix + L"\t, protected vl::glr::automaton::IExecutor::ITypeCallback");
					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"protected:");
					writer.WriteLine(prefix + L"\tvl::WString GetClassName(vl::vint32_t classIndex) const override;");
					writer.WriteLine(prefix + L"\tvl::vint32_t FindCommonBaseClass(vl::vint32_t class1, vl::vint32_t class2) const override;");
					writer.WriteLine(prefix + L"public:");
					writer.WriteLine(prefix + L"\t" + manager.name + L"();");
					writer.WriteLine(L"");
					for (auto ruleName : manager.RuleOrder())
					{
						auto ruleSymbol = manager.Rules()[ruleName];
						if (ruleSymbol->isParser)
						{
							auto astType = AstClassSymbolToString(ruleSymbol->ruleType);
							writer.WriteLine(prefix + L"\tvl::Ptr<" + astType + L"> Parse" + ruleName + L"(const vl::WString& input, vl::vint codeIndex = -1) const;");
							writer.WriteLine(prefix + L"\tvl::Ptr<" + astType + L"> Parse" + ruleName + L"(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;");
						}
					}
					writer.WriteLine(prefix + L"};");
				}
				WriteNssEnd(manager.Global().cppNss, writer);

				if (manager.Global().headerGuard != L"")
				{
					writer.WriteString(L"#endif");
				}
			}

/***********************************************************************
WriteSyntaxCppFile
***********************************************************************/

			void WriteSyntaxCppFile(SyntaxSymbolManager& manager, automaton::Executable& executable, automaton::Metadata& metadata, Ptr<CppParserGenOutput> output, stream::StreamWriter& writer)
			{
				WriteFileComment(manager.Global().name, writer);
				writer.WriteLine(L"#include \"" + output->syntaxOutputs[&manager]->syntaxH + L"\"");
				writer.WriteLine(L"");
				WString prefix = WriteNssBegin(manager.Global().cppNss, writer);
				{
					MemoryStream syntaxData;
					executable.Serialize(syntaxData);
					syntaxData.SeekFromBegin(0);
					WriteLoadDataFunctionCpp(prefix, manager.Global().name + manager.name + L"Data", syntaxData, true, writer);
				}
				{
					writer.WriteLine(L"");
					writer.WriteLine(prefix + L"const wchar_t* " + manager.name + L"RuleName(vl::vint index)");
					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"\tstatic const wchar_t* results[] = {");
					for (auto&& ruleName : metadata.ruleNames)
					{
						writer.WriteString(prefix + L"\t\tL\"");
						WriteCppStringBody(ruleName, writer);
						writer.WriteLine(L"\",");
					}
					writer.WriteLine(prefix + L"\t};");
					writer.WriteLine(prefix + L"\treturn results[index];");
					writer.WriteLine(prefix + L"}");
				}
				{
					writer.WriteLine(L"");
					writer.WriteLine(prefix + L"const wchar_t* " + manager.name + L"StateLabel(vl::vint index)");
					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"\tstatic const wchar_t* results[] = {");
					for (auto&& stateLabel : metadata.stateLabels)
					{
						writer.WriteString(prefix + L"\t\tL\"");
						WriteCppStringBody(stateLabel, writer);
						writer.WriteLine(L"\",");
					}
					writer.WriteLine(prefix + L"\t};");
					writer.WriteLine(prefix + L"\treturn results[index];");
					writer.WriteLine(prefix + L"}");
				}
				{
					writer.WriteLine(L"");
					writer.WriteLine(prefix + manager.name + L"::"+ manager.name + L"()");
					writer.WriteString(prefix + L"\t: vl::glr::ParserBase<");
					writer.WriteString(manager.Global().name + L"Tokens, ");
					writer.WriteString(manager.name + L"States, ");
					writer.WriteString(manager.Global().name + L"AstInsReceiver>(");
					writer.WriteString(L"&" + manager.Global().name + L"TokenDeleter, ");
					writer.WriteString(L"&" + manager.Global().name + L"LexerData, ");
					writer.WriteLine(L"&" + manager.Global().name + manager.name + L"Data)");
					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"}");
				}

				{
					writer.WriteLine(L"");
					writer.WriteLine(prefix + L"vl::WString " + manager.name + L"::GetClassName(vl::vint32_t classIndex) const");
					writer.WriteLine(prefix + L"{");
					writer.WriteLine(prefix + L"\treturn vl::WString::Unmanaged(" + manager.Global().name + L"TypeName((" + manager.Global().name + L"Classes)classIndex));");
					writer.WriteLine(prefix + L"}");
				}

				{
					writer.WriteLine(L"");
					writer.WriteLine(prefix + L"vl::vint32_t " + manager.name + L"::FindCommonBaseClass(vl::vint32_t class1, vl::vint32_t class2) const");
					writer.WriteLine(prefix + L"{");
					if (
						output->classIds.Count() == 0 ||
						From(output->classIds.Keys())
							.Where([](auto c) { return c->derivedClass_ToResolve != nullptr; })
							.IsEmpty()
						)
					{
						writer.WriteLine(prefix + L"\treturn -1;"); 
					}
					else
					{
						Array<AstClassSymbol*> idToClasses(output->classIds.Count());
						for (auto [k, v] : output->classIds)
						{
							idToClasses[v] = k;
						}

						writer.WriteLine(prefix + L"\tstatic vl::vint32_t results[" + itow(idToClasses.Count()) + L"][" + itow(idToClasses.Count()) + L"] = {");
						for (auto [c1, i1] : indexed(idToClasses))
						{
							writer.WriteString(prefix + L"\t\t{");
							for (auto [c2, i2] : indexed(idToClasses))
							{
								if (auto baseClass = FindCommonBaseClass(c1, c2))
								{
									writer.WriteString(itow(output->classIds[baseClass]) + L", ");
								}
								else
								{
									writer.WriteString(L"-1, ");
								}
							}
							writer.WriteLine(L"},");
						}
						writer.WriteLine(prefix + L"\t};");
						writer.WriteLine(prefix + L"\treturn vl::glr::AssemblerFindCommonBaseClass(class1, class2, results);");
					}
					writer.WriteLine(prefix + L"}");
				}

				for (auto ruleName : manager.RuleOrder())
				{
					auto ruleSymbol = manager.Rules()[ruleName];
					if (ruleSymbol->isParser)
					{
						auto astType = AstClassSymbolToString(ruleSymbol->ruleType);
						writer.WriteLine(L"");
						writer.WriteLine(prefix + L"vl::Ptr<" + astType + L"> " + manager.name + L"::Parse" + ruleName + L"(const vl::WString& input, vl::vint codeIndex) const");
						writer.WriteLine(prefix + L"{");
						writer.WriteLine(prefix + L"\t return ParseWithString<" + astType + L", " + manager.name + L"States::" + ruleName + L">(input, this, codeIndex);");
						writer.WriteLine(prefix + L"}");
						writer.WriteLine(L"");
						writer.WriteLine(prefix + L"vl::Ptr<" + astType + L"> " + manager.name + L"::Parse" + ruleName + L"(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex) const");
						writer.WriteLine(prefix + L"{");
						writer.WriteLine(prefix + L"\t return ParseWithTokens<" + astType + L", " + manager.name + L"States::" + ruleName + L">(tokens, this, codeIndex);");
						writer.WriteLine(prefix + L"}");
					}
				}
				WriteNssEnd(manager.Global().cppNss, writer);
			}

/***********************************************************************
WriteLexerFiles
***********************************************************************/

			void WriteSyntaxFiles(SyntaxSymbolManager& manager, automaton::Executable& executable, automaton::Metadata& metadata, Ptr<CppParserGenOutput> output, collections::Dictionary<WString, WString>& files)
			{
				WString fileH = GenerateToStream([&](StreamWriter& writer)
				{
					WriteSyntaxHeaderFile(manager, executable, metadata, output, writer);
				});

				WString fileCpp = GenerateToStream([&](StreamWriter& writer)
				{
					WriteSyntaxCppFile(manager, executable, metadata, output, writer);
				});

				files.Add(output->syntaxOutputs[&manager]->syntaxH, fileH);
				files.Add(output->syntaxOutputs[&manager]->syntaxCpp, fileCpp);
			}
		}
	}
}