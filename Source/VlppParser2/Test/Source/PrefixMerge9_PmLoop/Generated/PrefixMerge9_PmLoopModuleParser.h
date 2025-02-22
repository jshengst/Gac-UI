/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:PrefixMerge9_PmLoop
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE9_PMLOOP_MODULEPARSER_SYNTAX
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE9_PMLOOP_MODULEPARSER_SYNTAX

#include "PrefixMerge9_PmLoop_Assembler.h"
#include "PrefixMerge9_PmLoop_Lexer.h"

namespace prefixmerge9_pmloop
{
	enum class ModuleParserStates
	{
		_Int = 0,
		_IntItem = 3,
		_Item = 6,
		Module = 14,
		_Item_LRI_Isolated_4 = 18,
		_Item_LRI_Isolated_5 = 21,
		_IntItem_LRI_Original = 25,
		_Item_LRI_Original = 29,
	};

	const wchar_t* ModuleParserRuleName(vl::vint index);
	const wchar_t* ModuleParserStateLabel(vl::vint index);
	extern void PrefixMerge9_PmLoopModuleParserData(vl::stream::IStream& outputStream);

	class ModuleParser
		: public vl::glr::ParserBase<PrefixMerge9_PmLoopTokens, ModuleParserStates, PrefixMerge9_PmLoopAstInsReceiver>
		, protected vl::glr::automaton::IExecutor::ITypeCallback
	{
	protected:
		vl::WString GetClassName(vl::vint32_t classIndex) const override;
		vl::vint32_t FindCommonBaseClass(vl::vint32_t class1, vl::vint32_t class2) const override;
	public:
		ModuleParser();

		vl::Ptr<prefixmerge9_pmloop::File> ParseModule(const vl::WString& input, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge9_pmloop::File> ParseModule(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
	};
}
#endif