/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:PrefixMerge3_LriNested
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "PrefixMerge3_LriNested_Lexer.h"

namespace prefixmerge3_lrinested
{
	bool PrefixMerge3_LriNestedTokenDeleter(vl::vint token)
	{
		switch((PrefixMerge3_LriNestedTokens)token)
		{
		case PrefixMerge3_LriNestedTokens::SPACE:
			return true;
		default:
			return false;
		}
	}

	const wchar_t* PrefixMerge3_LriNestedTokenId(PrefixMerge3_LriNestedTokens token)
	{
		static const wchar_t* results[] = {
			L"OPEN_ROUND",
			L"CLOSE_ROUND",
			L"OPEN_BRACE",
			L"CLOSE_BRACE",
			L"COMMA",
			L"DOT",
			L"CONST",
			L"ASTERISK",
			L"ID",
			L"SPACE",
		};
		vl::vint index = (vl::vint)token;
		return 0 <= index && index < PrefixMerge3_LriNestedTokenCount ? results[index] : nullptr;
	}

	const wchar_t* PrefixMerge3_LriNestedTokenDisplayText(PrefixMerge3_LriNestedTokens token)
	{
		static const wchar_t* results[] = {
			L"(",
			L")",
			L"{",
			L"}",
			L",",
			L".",
			L"const",
			L"*",
			nullptr,
			nullptr,
		};
		vl::vint index = (vl::vint)token;
		return 0 <= index && index < PrefixMerge3_LriNestedTokenCount ? results[index] : nullptr;
	}

	const wchar_t* PrefixMerge3_LriNestedTokenRegex(PrefixMerge3_LriNestedTokens token)
	{
		static const wchar_t* results[] = {
			L"/(",
			L"/)",
			L"/{",
			L"/}",
			L",",
			L".",
			L"const",
			L"/*",
			L"[a-zA-Z_]/w*",
			L"/s+",
		};
		vl::vint index = (vl::vint)token;
		return 0 <= index && index < PrefixMerge3_LriNestedTokenCount ? results[index] : nullptr;
	}

	void PrefixMerge3_LriNestedLexerData(vl::stream::IStream& outputStream)
	{
		static const vl::vint dataLength = 306; // 1907 bytes before compressing
		static const vl::vint dataBlock = 256;
		static const vl::vint dataRemain = 50;
		static const vl::vint dataSolidRows = 1;
		static const vl::vint dataRows = 2;
		static const char* compressed[] = {
			"\x73\x07\x00\x00\x2A\x01\x00\x00\x11\x00\x01\x98\x01\x84\x81\x83\x0A\x82\x09\x08\x84\x8A\x0B\x84\x81\x06\x87\x04\xA0\x11\x84\x88\x14\x88\x83\x14\x17\x84\xAA\x1A\x84\x84\x15\x8E\x82\x2E\x20\x84\x90\x14\x81\x1C\x83\x20\x04\xDA\x04\x9F\x2B\x94\x81\x30\x82\x62\x04\xA3\x32\x94\x84\x30\x83\x36\x04\xEE\x39\x84\x8F\x34\x9C\x82\x38\x04\xF2\x04\x93\x33\xA4\x80\x3A\xA3\x04\xF5\x04\x9A\x34\x83\x3D\xA6\x82\x7D\x50\x8D\x81\x8C\x84\xAB\xA8\x00\x01\x04\x82\x04\x88\x04\x81\x02\x82\x06\x04\xBF\x63\xBF\x79\x85\x80\xB3\x00\x68\x87\x0A\x87\xB4\xB5\xB4\xB7\x68\xE8\x83\x04\x84\x02\xB0\xB3\xBB\x78\xF9\xBA\xBB\xBC\xBD\xBE\xBF\xBF\x80\x81\xC2\xC3\xC4\xC5\xC2\xC3\xC3\x88\x89\xCA\xCB\xCC\xC5\xC6\xC7\xC7\x90\x91\xD2\xD3\xC4\xCD\xCA\xC4\x06\x04\x98\xC1\x9A\xC0\x04\xCE\xCF\xCC\x04\x8B\x20\xDB\xC3\xD5\xCE\xBA\xCB\xA8\xA9\xD5\xDF\xC4\xD5\xD6\xD2\xD7\xAC\xAF\xF2\xD1\xDF\xBF\x85\x80\xDB\x00\x38\xF8\xCA\xDC\xDC\xDD\xD9\xDF\xA5\x8E\x25\xC0\xEE\xD5\xDF\xBC\xE2\xB3\xC3\xCA\xF0\xD5\xD5\xD8\x89\xDB\xCF\x80\x06\xF3\xE4\xC8\xE6\xEB\xE5\x00\x0F\x18\xF4",
			"\xE8\xBF\xE8\xE7\xEF\xC9\x81\x90\x0D\xEC\xEC\xB2\xEF\xF0\xE8\xE7\xFF\xBE\x7F\x79\x00\x81\x82\xF0\xD8\x9A\xA4\x83\xB9\x81\xBB\x80\x5F\x81\x9D\xA1\x8B\xB2\xFE\xB7\xFD\x00\x00\x88\x58\x80\x00\xA1\x51\x40",
		};
		vl::glr::DecompressSerializedData(compressed, true, dataSolidRows, dataRows, dataBlock, dataRemain, outputStream);
	}
}
