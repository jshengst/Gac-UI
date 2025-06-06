#include "AstCppGen.h"

namespace vl
{
	namespace glr
	{
		namespace parsergen
		{
			using namespace collections;
			using namespace stream;

			extern void PrintCppType(AstDefFileGroup* fileGroupContext, AstSymbol* propSymbol, stream::StreamWriter& writer);

/***********************************************************************
WriteEmptyVisitorHeaderFile
***********************************************************************/

			void WriteEmptyVisitorHeaderFile(AstDefFileGroup* group, Ptr<CppAstGenOutput> output, stream::StreamWriter& writer)
			{
				WriteAstUtilityHeaderFile(group, output, L"empty_visitor", writer, [&](const WString& prefix)
				{
					for (auto name : group->SymbolOrder())
					{
						if (auto classSymbol = dynamic_cast<AstClassSymbol*>(group->Symbols()[name]))
						{
							if (classSymbol->derivedClasses.Count() > 0)
							{
								writer.WriteLine(prefix + L"/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>");
								writer.WriteString(prefix + L"class " + name + L"Visitor : public vl::Object, public ");
								PrintCppType(group, classSymbol, writer);
								writer.WriteLine(L"::IVisitor");
								writer.WriteLine(prefix + L"{");

								writer.WriteLine(prefix + L"protected:");
								writer.WriteLine(prefix + L"\t// Dispatch (virtual) --------------------------------");
								for (auto childSymbol : classSymbol->derivedClasses)
								{
									if (childSymbol->derivedClasses.Count() > 0)
									{
										writer.WriteString(prefix + L"\tvirtual void Dispatch(");
										PrintCppType(group, childSymbol, writer);
										writer.WriteLine(L"* node) = 0;");
									}
								}
								writer.WriteLine(L"");

								writer.WriteLine(prefix + L"public:");
								writer.WriteLine(prefix + L"\t// Visitor Members -----------------------------------");
								for (auto childSymbol : classSymbol->derivedClasses)
								{
									writer.WriteString(prefix + L"\tvoid Visit(");
									PrintCppType(group, childSymbol, writer);
									writer.WriteLine(L"* node) override;");
								}

								writer.WriteLine(prefix + L"};");
								writer.WriteLine(L"");
							}
						}
					}
				});
			}

/***********************************************************************
WriteEmptyVisitorCppFile
***********************************************************************/

			void WriteEmptyVisitorCppFile(AstDefFileGroup* group, Ptr<CppAstGenOutput> output, stream::StreamWriter& writer)
			{
				WriteAstUtilityCppFile(group, output->emptyH, L"empty_visitor", writer, [&](const WString& prefix)
				{
					for (auto name : group->SymbolOrder())
					{
						if (auto classSymbol = dynamic_cast<AstClassSymbol*>(group->Symbols()[name]))
						{
							if (classSymbol->derivedClasses.Count() > 0)
							{
								writer.WriteLine(L"");
								writer.WriteLine(L"/***********************************************************************");
								writer.WriteLine(classSymbol->Name() + L"Visitor");
								writer.WriteLine(L"***********************************************************************/");

								writer.WriteLine(L"");
								writer.WriteLine(prefix + L"// Visitor Members -----------------------------------");
								for (auto childSymbol : classSymbol->derivedClasses)
								{
									writer.WriteLine(L"");
									writer.WriteString(prefix + L"void " + classSymbol->Name() + L"Visitor::Visit(");
									PrintCppType(group, childSymbol, writer);
									writer.WriteLine(L"* node)");
									writer.WriteLine(prefix + L"{");
									if (childSymbol->derivedClasses.Count() > 0)
									{
										writer.WriteLine(prefix + L"\tDispatch(node);");
									}
									writer.WriteLine(prefix + L"}");
								}
							}
						}
					}
				});
			}
		}
	}
}