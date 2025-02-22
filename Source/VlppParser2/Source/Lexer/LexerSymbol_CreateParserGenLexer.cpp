#include "LexerSymbol.h"

namespace vl
{
	namespace glr
	{
		namespace parsergen
		{
			using namespace collections;

/***********************************************************************
CreateParserGenAst
***********************************************************************/

			void CreateParserGenLexer(LexerSymbolManager& manager)
			{
				manager.CreateToken(L"ATT_AMBIGUOUS", L"@ambiguous");
				manager.CreateToken(L"ATT_PUBLIC", L"@public");
				manager.CreateToken(L"ATT_PARSER", L"@parser");

				manager.CreateToken(L"CLASS", L"class");
				manager.CreateToken(L"ENUM", L"enum");
				manager.CreateToken(L"VAR", L"var");
				manager.CreateToken(L"SWITCH", L"switch");
				manager.CreateToken(L"TOKEN", L"token");
				manager.CreateToken(L"AS", L"as");
				manager.CreateToken(L"PARTIAL", L"partial");

				manager.CreateToken(L"OPEN_ROUND", L"/(");
				manager.CreateToken(L"CLOSE_ROUND", L"/)");
				manager.CreateToken(L"OPEN_SQUARE", L"/[");
				manager.CreateToken(L"CLOSE_SQUARE", L"/]");
				manager.CreateToken(L"OPEN_CURLY", L"/{");
				manager.CreateToken(L"CLOSE_CURLY", L"/}");

				manager.CreateToken(L"OPEN_PUSH", L"!/(");
				manager.CreateToken(L"OPEN_TEST", L"/?/(");
				manager.CreateToken(L"AND", L"&&");
				manager.CreateToken(L"OR", L"/|/|");

				manager.CreateToken(L"COMMA", L",");
				manager.CreateToken(L"COLON", L":");
				manager.CreateToken(L"SEMICOLON", L";");

				manager.CreateToken(L"INFER", L"::=");
				manager.CreateToken(L"ALTERNATIVE", L"/|");
				manager.CreateToken(L"USE", L"!");
				manager.CreateToken(L"ASSIGN", L"=");
				manager.CreateToken(L"WEAK_ASSIGN", L"/?=");
				manager.CreateToken(L"POSITIVE", L"/+");
				manager.CreateToken(L"NEGATIVE", L"-");

				manager.CreateToken(L"LS_PH", L"left_recursion_placeholder");
				manager.CreateToken(L"LS_I", L"left_recursion_inject");
				manager.CreateToken(L"LS_IM", L"left_recursion_inject_multiple");
				manager.CreateToken(L"LS_PM", L"prefix_merge");
				manager.CreateToken(L"ID", L"[a-zA-Z_][a-zA-Z0-9_]*");
				manager.CreateToken(L"STRING", L"(\"[^\"]*\")+");
				manager.CreateToken(L"CONDITIONAL_LITERAL", L"(\'[^\']*\')+");

				manager.CreateDiscardedToken(L"SPACE", L"/s+");
				manager.CreateDiscardedToken(L"COMMENT", L"////[^/r/n]*");
			}
		}
	}
}