/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:IfElseAmbiguityOnStat
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_IFELSEAMBIGUITYONSTAT_AST_ASSEMBLER
#define VCZH_PARSER2_UNITTEST_IFELSEAMBIGUITYONSTAT_AST_ASSEMBLER

#include "IfElseAmbiguityOnStatStatAst.h"

namespace ifelseambiguityonstat
{
	enum class IfElseAmbiguityOnStatClasses : vl::vint32_t
	{
		BlockStat = 0,
		DoStat = 1,
		IfStat = 2,
		Module = 3,
		Stat = 4,
		StatToResolve = 5,
	};

	enum class IfElseAmbiguityOnStatFields : vl::vint32_t
	{
		BlockStat_stats = 0,
		IfStat_elseBranch = 1,
		IfStat_thenBranch = 2,
		Module_stat = 3,
		StatToResolve_candidates = 4,
	};

	extern const wchar_t* IfElseAmbiguityOnStatTypeName(IfElseAmbiguityOnStatClasses type);
	extern const wchar_t* IfElseAmbiguityOnStatCppTypeName(IfElseAmbiguityOnStatClasses type);
	extern const wchar_t* IfElseAmbiguityOnStatFieldName(IfElseAmbiguityOnStatFields field);
	extern const wchar_t* IfElseAmbiguityOnStatCppFieldName(IfElseAmbiguityOnStatFields field);

	class IfElseAmbiguityOnStatAstInsReceiver : public vl::glr::AstInsReceiverBase
	{
	protected:
		vl::Ptr<vl::glr::ParsingAstBase> CreateAstNode(vl::vint32_t type) override;
		void SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, vl::Ptr<vl::glr::ParsingAstBase> value) override;
		void SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, const vl::regex::RegexToken& token, vl::vint32_t tokenIndex) override;
		void SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, vl::vint32_t enumItem, bool weakAssignment) override;
		vl::Ptr<vl::glr::ParsingAstBase> ResolveAmbiguity(vl::vint32_t type, vl::collections::Array<vl::Ptr<vl::glr::ParsingAstBase>>& candidates) override;
	};
}
#endif