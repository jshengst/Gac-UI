/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:IfElseSwitch
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_IFELSESWITCH_MODULEPARSER_SYNTAX
#define VCZH_PARSER2_UNITTEST_IFELSESWITCH_MODULEPARSER_SYNTAX

#include "IfElseSwitch_Assembler.h"
#include "IfElseSwitch_Lexer.h"

namespace ifelseswitch
{
	enum class ModuleParserStates
	{
		Do = 0,
		Block = 4,
		OtherStat = 9,
		Stat = 13,
		Module = 17,
		IfTail_SWITCH_COMBINED = 20,
		If_SWITCH_1allow_half_if = 25,
		If_SWITCH_0allow_half_if = 31,
		IfTail_SWITCH_1allow_half_if = 37,
		IfTail_SWITCH_0allow_half_if = 44,
	};

	const wchar_t* ModuleParserRuleName(vl::vint index);
	const wchar_t* ModuleParserStateLabel(vl::vint index);
	extern void IfElseSwitchModuleParserData(vl::stream::IStream& outputStream);

	class ModuleParser
		: public vl::glr::ParserBase<IfElseSwitchTokens, ModuleParserStates, IfElseSwitchAstInsReceiver>
		, protected vl::glr::automaton::IExecutor::ITypeCallback
	{
	protected:
		vl::WString GetClassName(vl::vint32_t classIndex) const override;
		vl::vint32_t FindCommonBaseClass(vl::vint32_t class1, vl::vint32_t class2) const override;
	public:
		ModuleParser();

		vl::Ptr<ifelseswitch::Module> ParseModule(const vl::WString& input, vl::vint codeIndex = -1) const;
		vl::Ptr<ifelseswitch::Module> ParseModule(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
	};
}
#endif