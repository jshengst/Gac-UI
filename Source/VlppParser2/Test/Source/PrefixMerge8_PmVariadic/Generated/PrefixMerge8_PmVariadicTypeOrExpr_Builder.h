/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE8_PMVARIADIC_TYPEOREXPR_AST_BUILDER
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE8_PMVARIADIC_TYPEOREXPR_AST_BUILDER

#include "PrefixMerge8_PmVariadicTypeOrExpr.h"

namespace prefixmerge8_pmvariadic::builder
{
	class MakeCallExpr : public vl::glr::ParsingAstBuilder<CallExpr>
	{
	public:
		MakeCallExpr& args(const vl::Ptr<TypeOrExprOrOthers>& value);
		MakeCallExpr& func(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeConstType : public vl::glr::ParsingAstBuilder<ConstType>
	{
	public:
		MakeConstType& type(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeCtorExpr : public vl::glr::ParsingAstBuilder<CtorExpr>
	{
	public:
		MakeCtorExpr& args(const vl::Ptr<TypeOrExprOrOthers>& value);
		MakeCtorExpr& type(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeFunctionType : public vl::glr::ParsingAstBuilder<FunctionType>
	{
	public:
		MakeFunctionType& args(const vl::Ptr<TypeOrExprOrOthers>& value);
		MakeFunctionType& returnType(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeGenericMemberName : public vl::glr::ParsingAstBuilder<GenericMemberName>
	{
	public:
		MakeGenericMemberName& member(const vl::WString& value);
		MakeGenericMemberName& parent(const vl::Ptr<QualifiedName>& value);
		MakeGenericMemberName& args(const vl::Ptr<TypeOrExprOrOthers>& value);
	};

	class MakeGenericName : public vl::glr::ParsingAstBuilder<GenericName>
	{
	public:
		MakeGenericName& name(const vl::WString& value);
		MakeGenericName& args(const vl::Ptr<TypeOrExprOrOthers>& value);
	};

	class MakeGenericQualifiedName : public vl::glr::ParsingAstBuilder<GenericQualifiedName>
	{
	public:
		MakeGenericQualifiedName& args(const vl::Ptr<TypeOrExprOrOthers>& value);
	};

	class MakeMemberName : public vl::glr::ParsingAstBuilder<MemberName>
	{
	public:
		MakeMemberName& member(const vl::WString& value);
		MakeMemberName& parent(const vl::Ptr<QualifiedName>& value);
	};

	class MakeMulExpr : public vl::glr::ParsingAstBuilder<MulExpr>
	{
	public:
		MakeMulExpr& first(const vl::Ptr<TypeOrExpr>& value);
		MakeMulExpr& second(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeName : public vl::glr::ParsingAstBuilder<Name>
	{
	public:
		MakeName& name(const vl::WString& value);
	};

	class MakePointerType : public vl::glr::ParsingAstBuilder<PointerType>
	{
	public:
		MakePointerType& type(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeTypeOrExprOrOthersToResolve : public vl::glr::ParsingAstBuilder<TypeOrExprOrOthersToResolve>
	{
	public:
		MakeTypeOrExprOrOthersToResolve& candidates(const vl::Ptr<TypeOrExprOrOthers>& value);
	};

	class MakeTypeOrExprToResolve : public vl::glr::ParsingAstBuilder<TypeOrExprToResolve>
	{
	public:
		MakeTypeOrExprToResolve& candidates(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeVariadicArgument : public vl::glr::ParsingAstBuilder<VariadicArgument>
	{
	public:
		MakeVariadicArgument& operand(const vl::Ptr<TypeOrExpr>& value);
	};

}
#endif