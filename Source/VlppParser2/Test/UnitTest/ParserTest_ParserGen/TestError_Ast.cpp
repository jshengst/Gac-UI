#include "TestError.h"

namespace TestError_Ast_TestObjects
{
	template<vint Count>
	void ExpectError(TypeParser& parser, const wchar_t* (&astCodes)[Count], ParserErrorWithoutLocation expectedError)
	{
		ParserSymbolManager global;
		AstSymbolManager astManager(global);
		List<Pair<AstDefFile*, Ptr<GlrAstFile>>> astFiles;
		auto astDefFileGroup = astManager.CreateFileGroup(WString::Unmanaged(L"FileGroup"));
		for (auto [astCode, index] : indexed(From(astCodes)))
		{
			auto astFile = parser.ParseFile(WString::Unmanaged(astCode));
			auto astDefFile = astDefFileGroup->CreateFile(WString::Unmanaged(L"Ast") + itow(index));
			astFiles.Add({ astDefFile,astFile });
		}
		CompileAst(astManager, astFiles);
		AssertError(global, expectedError);
	}

	void ExpectError(TypeParser& parser, const wchar_t* astCode, ParserErrorWithoutLocation expectedError)
	{
		const wchar_t* astCodes[] = { astCode };
		ExpectError(parser, astCodes, expectedError);
	}
}
using namespace TestError_Ast_TestObjects;

TEST_FILE
{
	TypeParser parser;

	TEST_CASE(L"DuplicatedFileGroup")
	{
		ParserSymbolManager global;
		AstSymbolManager astManager(global);
		astManager.CreateFileGroup(L"FileGroup");
		astManager.CreateFileGroup(L"FileGroup");
		AssertError(global, { ParserErrorType::DuplicatedFileGroup,L"FileGroup" });
	});

	TEST_CASE(L"DuplicatedFile")
	{
		ParserSymbolManager global;
		AstSymbolManager astManager(global);
		auto group = astManager.CreateFileGroup(L"FileGroup");
		group->CreateFile(L"Ast");
		group->CreateFile(L"Ast");
		AssertError(global, { ParserErrorType::DuplicatedFile,L"Ast" });
	});

	TEST_CASE(L"FileGroupDependencyNotExists")
	{
		ParserSymbolManager global;
		AstSymbolManager astManager(global);
		astManager.CreateFileGroup(L"FileGroup")->AddDependency(L"Random");
		AssertError(global, { ParserErrorType::FileGroupDependencyNotExists,L"FileGroup",L"Random"});
	});

	TEST_CASE(L"FileGroupCyclicDependency")
	{
		ParserSymbolManager global;
		AstSymbolManager astManager(global);
		auto g1 = astManager.CreateFileGroup(L"A");
		auto g2 = astManager.CreateFileGroup(L"B");
		g1->AddDependency(L"B");
		g2->AddDependency(L"A");
		AssertError(global, { ParserErrorType::FileGroupCyclicDependency,L"B",L"A" });
	});

	TEST_CASE(L"DuplicatedSymbolInFile")
	{
		const wchar_t* inputs[] = {
LR"AST(
			enum A {}
			enum A {}
)AST",
LR"AST(
			class A {}
			class A {}
)AST",
LR"AST(
			enum A {}
			class A {}
)AST" };
		for (auto input : inputs)
		{
			ExpectError(parser, input, { ParserErrorType::DuplicatedSymbolInFile,L"Ast0",L"A" });
		}
	});

	TEST_CASE(L"DuplicatedSymbolInFileGroup")
	{
		const wchar_t* inputs[] = {
LR"AST(
			enum A {}
)AST",
LR"AST(
			class A {}
)AST" };
		for (auto input1 : inputs)
		{
			for (auto input2 : inputs)
			{
				const wchar_t* combinedInputs[] = { input1,input2 };
				ExpectError(parser, combinedInputs, { ParserErrorType::DuplicatedSymbolInFileGroup,L"Ast1",L"A",L"Ast0" });
			}
		}
	});

	TEST_CASE(L"DuplicatedClassProp")
	{
		const wchar_t* input =
LR"AST(
			class A
			{
				var a : token;
				var a : token;
			}
)AST";
		ExpectError(parser, input, { ParserErrorType::DuplicatedClassProp,L"Ast0",L"A",L"a" });
	});

	TEST_CASE(L"DuplicatedEnumItem")
	{
		const wchar_t* input =
LR"AST(
			enum A
			{
				a,
				a,
			}
)AST";
		ExpectError(parser, input, { ParserErrorType::DuplicatedEnumItem,L"Ast0",L"A",L"a" });
	});

	TEST_CASE(L"BaseClassNotExists")
	{
		const wchar_t* input =
LR"AST(
			class A : B {}
)AST";
		ExpectError(parser, input, { ParserErrorType::BaseClassNotExists,L"Ast0",L"A",L"B" });
	});

	TEST_CASE(L"BaseClassNotClass")
	{
		const wchar_t* input =
LR"AST(
			enum A {}
			class B : A {}
)AST";
		ExpectError(parser, input, { ParserErrorType::BaseClassNotClass,L"Ast0",L"B",L"A" });
	});

	TEST_CASE(L"BaseClassNotPublic")
	{
		const wchar_t* inputs[] = {
LR"AST(
			class A {}
)AST",
LR"AST(
			class B : A {}
)AST" };
		ExpectError(parser, inputs, { ParserErrorType::BaseClassNotPublic,L"Ast1",L"B",L"A" });
	});

	TEST_CASE(L"BaseClassCyclicDependency")
	{
		const wchar_t* input =
LR"AST(
			class A : B {}
			class B : A {}
)AST";
		ExpectError(parser, input, { ParserErrorType::BaseClassCyclicDependency,L"Ast0",L"B" });
	});

	TEST_CASE(L"FieldTypeNotExists")
	{
		const wchar_t* input =
LR"AST(
			class A
			{
				var b : B;
			}
)AST";
		ExpectError(parser, input, { ParserErrorType::FieldTypeNotExists,L"Ast0",L"A",L"b" });
	});

	TEST_CASE(L"FieldTypeNotClass")
	{
		const wchar_t* input =
LR"AST(
			enum A {}
			class B
			{
				var a : A[];
			}
)AST";
		ExpectError(parser, input, { ParserErrorType::FieldTypeNotClass,L"Ast0",L"B",L"a" });
	});

	TEST_CASE(L"FieldTypeNotPublic")
	{
		const wchar_t* inputs[] = {
LR"AST(
			class A {}
)AST",
LR"AST(
			class B
			{
				var f : A;
			}
)AST" };
		ExpectError(parser, inputs, { ParserErrorType::FieldTypeNotPublic,L"Ast1",L"B",L"f" });
	});

	TEST_CATEGORY(L"AST Rewriting (single file)")
	{
		const wchar_t* inputs[] = {
LR"AST(
			@public	@ambiguous	class Expr							{							}
			@public	@ambiguous	class Decl							{ var name : token;			}
)AST",
LR"AST(
								class IdExpr		: Expr			{ var id : token;			}
								class CompExpr		: Expr			{ var expr : Expr;			}
								class NsDecl		: Decl			{ var decls : Decl[];		}
								class ExprDecl		: Decl			{ var expr : Expr;			}
)AST",
LR"AST(
								class File							{ var delcs : Decl[];		}
)AST" };

		const wchar_t* outputOrigin =
LR"AST(
			@public	@ambiguous	class Expr							{							}
			@public	@ambiguous	class Decl							{ var name : token;			}
								class IdExpr		: Expr			{ var id : token;			}
								class CompExpr		: Expr			{ var expr : Expr;			}
								class NsDecl		: Decl			{ var decls : Decl[];		}
								class ExprDecl		: Decl			{ var expr : Expr;			}
								class File							{ var delcs : Decl[];		}
)AST";

		const wchar_t* outputGenerated =
LR"AST(
			@public	@ambiguous	class Expr							{							}
								class ExprToResolve	: Expr			{ var candidates : Expr[];	}
			@public	@ambiguous	class Decl							{							}
								class DeclToResolve	: Decl			{ var candidates : Decl[];	}
			@public				class DeclCommon	: Decl			{ var name : token;			}
								class IdExpr		: Expr			{ var id : token;			}
								class CompExpr		: Expr			{ var expr : Expr;			}
								class NsDecl		: DeclCommon	{ var decls : Decl[];		}
								class ExprDecl		: DeclCommon	{ var expr : Expr;			}
								class File							{ var delcs : Decl[];		}
)AST";

		auto assertResult = [&]<typename TCallback>(TCallback&& callback)
		{
			ParserSymbolManager global;
			AstSymbolManager astManager(global);
			callback(astManager);
			TEST_ASSERT(global.Errors().Count() == 0);
			{
				auto astActual = TypeSymbolToAst(astManager, false);
				auto astExpected = parser.ParseFile(WString::Unmanaged(outputOrigin));
				auto formattedActual = GenerateToStream([&](TextWriter& writer) { TypeAstToCode(astActual, writer); });
				auto formattedExpected = GenerateToStream([&](TextWriter& writer) { TypeAstToCode(astExpected, writer); });
				TEST_ASSERT(formattedActual == formattedExpected);
			}
			{
				auto astActual = TypeSymbolToAst(astManager, true);
				auto astExpected = parser.ParseFile(WString::Unmanaged(outputGenerated));
				auto formattedActual = GenerateToStream([&](TextWriter& writer) { TypeAstToCode(astActual, writer); });
				auto formattedExpected = GenerateToStream([&](TextWriter& writer) { TypeAstToCode(astExpected, writer); });
				TEST_ASSERT(formattedActual == formattedExpected);
			}
		};

		TEST_CASE(L"Single File")
		{
			assertResult([&](AstSymbolManager& astManager)
			{
				auto astFile = parser.ParseFile(
					WString::Unmanaged(inputs[0]) +
					WString::Unmanaged(inputs[1]) +
					WString::Unmanaged(inputs[2])
				);
				auto astDefFileGroup = astManager.CreateFileGroup(WString::Unmanaged(L"FileGroup"));
				auto astDefFile = astDefFileGroup->CreateFile(WString::Unmanaged(L"Ast"));
				CompileAst(astManager, astDefFile, astFile);
			});
		});

		TEST_CASE(L"Multiple Files")
		{
			assertResult([&](AstSymbolManager& astManager)
			{
				List<Pair<AstDefFile*, Ptr<GlrAstFile>>> astFiles;
				auto astDefFileGroup = astManager.CreateFileGroup(WString::Unmanaged(L"FileGroup"));
				for (auto [input, index] : indexed(From(inputs)))
				{
					auto astFile = parser.ParseFile(WString::Unmanaged(input));
					auto astDefFile = astDefFileGroup->CreateFile(WString::Unmanaged(L"Ast") + itow(index));
					astFiles.Add({ astDefFile,astFile });
				}
				CompileAst(astManager, astFiles);
			});
		});
	});
}