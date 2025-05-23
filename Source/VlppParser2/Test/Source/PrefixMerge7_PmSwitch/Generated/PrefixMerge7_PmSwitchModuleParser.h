/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:PrefixMerge7_PmSwitch
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_MODULEPARSER_SYNTAX
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_MODULEPARSER_SYNTAX

#include "PrefixMerge7_PmSwitch_Assembler.h"
#include "PrefixMerge7_PmSwitch_Lexer.h"

namespace prefixmerge7_pmswitch
{
	enum class ModuleParserStates
	{
		_GenericArguments = 0,
		_Name = 6,
		_PrimitiveShared = 18,
		_PrimitiveTypeOnly = 21,
		_PrimitiveExprOnly = 27,
		_LongType = 32,
		_Expr0 = 38,
		_Expr1 = 45,
		_Expr2 = 53,
		_Expr_NoComma = 61,
		_Expr_NoGT_NoComma = 70,
		_Expr = 79,
		Module = 89,
		Module_NoGT_NoComma = 105,
		ExprModule = 120,
		TypeModule = 123,
		_Expr3_SWITCH_COMBINED = 126,
		_Expr3_SWITCH_0allow_gt = 134,
		_Expr3_SWITCH_1allow_gt = 142,
		_Expr4_SWITCH_0allow_gt = 150,
		_Expr4_SWITCH_1allow_gt = 159,
		_Expr4_SWITCH_0allow_gt_LRI_Isolated_1 = 168,
		_Expr4_SWITCH_1allow_gt_LRI_Isolated_1 = 172,
		_LongType_LRI_Original = 176,
		_Expr0_LRI_Original = 190,
		_Expr1_LRI_Original = 200,
		_Expr2_LRI_Original = 208,
		_Expr3_SWITCH_COMBINED_LRI_Original = 214,
		_Expr3_SWITCH_0allow_gt_LRI_Original = 217,
		_Expr3_SWITCH_1allow_gt_LRI_Original = 223,
		_Expr4_SWITCH_0allow_gt_LRI_Original = 232,
		_Expr4_SWITCH_1allow_gt_LRI_Original = 237,
		_Expr_NoComma_LRI_Original = 242,
		_Expr_NoGT_NoComma_LRI_Original = 245,
		_Expr_LRI_Original = 248,
		Module_LRI_Original = 254,
		Module_NoGT_NoComma_LRI_Original = 258,
		_Expr0__LongType_LRI_Prefix = 262,
	};

	const wchar_t* ModuleParserRuleName(vl::vint index);
	const wchar_t* ModuleParserStateLabel(vl::vint index);
	extern void PrefixMerge7_PmSwitchModuleParserData(vl::stream::IStream& outputStream);

	class ModuleParser
		: public vl::glr::ParserBase<PrefixMerge7_PmSwitchTokens, ModuleParserStates, PrefixMerge7_PmSwitchAstInsReceiver>
		, protected vl::glr::automaton::IExecutor::ITypeCallback
	{
	protected:
		vl::WString GetClassName(vl::vint32_t classIndex) const override;
		vl::vint32_t FindCommonBaseClass(vl::vint32_t class1, vl::vint32_t class2) const override;
	public:
		ModuleParser();

		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseModule(const vl::WString& input, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseModule(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseExprModule(const vl::WString& input, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseExprModule(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseTypeModule(const vl::WString& input, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseTypeModule(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseModule_LRI_Original(const vl::WString& input, vl::vint codeIndex = -1) const;
		vl::Ptr<prefixmerge7_pmswitch::TypeOrExpr> ParseModule_LRI_Original(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
	};
}
#endif