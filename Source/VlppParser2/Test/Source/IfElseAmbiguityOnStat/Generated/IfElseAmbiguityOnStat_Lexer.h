/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:IfElseAmbiguityOnStat
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_IFELSEAMBIGUITYONSTAT_LEXER
#define VCZH_PARSER2_UNITTEST_IFELSEAMBIGUITYONSTAT_LEXER

#include "../../../../Source/AstBase.h"
#include "../../../../Source/SyntaxBase.h"

namespace ifelseambiguityonstat
{
	enum class IfElseAmbiguityOnStatTokens : vl::vint32_t
	{
		OPEN_BRACE = 0,
		CLOSE_BRACE = 1,
		SEMICOLON = 2,
		IF = 3,
		CONDITION = 4,
		THEN = 5,
		ELSE = 6,
		DO = 7,
		SPACE = 8,
	};

	constexpr vl::vint IfElseAmbiguityOnStatTokenCount = 9;
	extern bool IfElseAmbiguityOnStatTokenDeleter(vl::vint token);
	extern const wchar_t* IfElseAmbiguityOnStatTokenId(IfElseAmbiguityOnStatTokens token);
	extern const wchar_t* IfElseAmbiguityOnStatTokenDisplayText(IfElseAmbiguityOnStatTokens token);
	extern const wchar_t* IfElseAmbiguityOnStatTokenRegex(IfElseAmbiguityOnStatTokens token);
	extern void IfElseAmbiguityOnStatLexerData(vl::stream::IStream& outputStream);
}
#endif