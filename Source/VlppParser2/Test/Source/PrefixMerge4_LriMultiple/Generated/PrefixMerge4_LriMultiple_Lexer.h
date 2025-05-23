/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:PrefixMerge4_LriMultiple
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE4_LRIMULTIPLE_LEXER
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE4_LRIMULTIPLE_LEXER

#include "../../../../Source/AstBase.h"
#include "../../../../Source/SyntaxBase.h"

namespace prefixmerge4_lrimultiple
{
	enum class PrefixMerge4_LriMultipleTokens : vl::vint32_t
	{
		OPEN_ROUND = 0,
		CLOSE_ROUND = 1,
		OPEN_BRACE = 2,
		CLOSE_BRACE = 3,
		COMMA = 4,
		DOT = 5,
		CONST = 6,
		ASTERISK = 7,
		ID = 8,
		SPACE = 9,
	};

	constexpr vl::vint PrefixMerge4_LriMultipleTokenCount = 10;
	extern bool PrefixMerge4_LriMultipleTokenDeleter(vl::vint token);
	extern const wchar_t* PrefixMerge4_LriMultipleTokenId(PrefixMerge4_LriMultipleTokens token);
	extern const wchar_t* PrefixMerge4_LriMultipleTokenDisplayText(PrefixMerge4_LriMultipleTokens token);
	extern const wchar_t* PrefixMerge4_LriMultipleTokenRegex(PrefixMerge4_LriMultipleTokens token);
	extern void PrefixMerge4_LriMultipleLexerData(vl::stream::IStream& outputStream);
}
#endif