/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE6_PM2_TYPEOREXPR_AST_COPY_VISITOR
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE6_PM2_TYPEOREXPR_AST_COPY_VISITOR

#include "PrefixMerge6_Pm2TypeOrExpr.h"

namespace prefixmerge6_pm2::copy_visitor
{
	/// <summary>A copy visitor, overriding all abstract methods with AST copying code.</summary>
	class TypeOrExprVisitor
		: public virtual vl::glr::CopyVisitorBase
		, protected virtual TypeOrExpr::IVisitor
		, protected virtual QualifiedName::IVisitor
	{
	protected:
		void CopyFields(CallExpr* from, CallExpr* to);
		void CopyFields(CommaExpr* from, CommaExpr* to);
		void CopyFields(ConstType* from, ConstType* to);
		void CopyFields(CtorExpr* from, CtorExpr* to);
		void CopyFields(FunctionType* from, FunctionType* to);
		void CopyFields(MemberName* from, MemberName* to);
		void CopyFields(MulExpr* from, MulExpr* to);
		void CopyFields(Name* from, Name* to);
		void CopyFields(PointerType* from, PointerType* to);
		void CopyFields(QualifiedName* from, QualifiedName* to);
		void CopyFields(ThrowExpr* from, ThrowExpr* to);
		void CopyFields(TypeOrExpr* from, TypeOrExpr* to);
		void CopyFields(TypeOrExprToResolve* from, TypeOrExprToResolve* to);

	protected:

		void Visit(TypeOrExprToResolve* node) override;
		void Visit(QualifiedName* node) override;
		void Visit(CallExpr* node) override;
		void Visit(CtorExpr* node) override;
		void Visit(MulExpr* node) override;
		void Visit(ThrowExpr* node) override;
		void Visit(CommaExpr* node) override;
		void Visit(ConstType* node) override;
		void Visit(PointerType* node) override;
		void Visit(FunctionType* node) override;

		void Visit(Name* node) override;
		void Visit(MemberName* node) override;

	public:
		virtual vl::Ptr<TypeOrExpr> CopyNode(TypeOrExpr* node);

		vl::Ptr<CallExpr> CopyNode(CallExpr* node);
		vl::Ptr<CommaExpr> CopyNode(CommaExpr* node);
		vl::Ptr<ConstType> CopyNode(ConstType* node);
		vl::Ptr<CtorExpr> CopyNode(CtorExpr* node);
		vl::Ptr<FunctionType> CopyNode(FunctionType* node);
		vl::Ptr<MemberName> CopyNode(MemberName* node);
		vl::Ptr<MulExpr> CopyNode(MulExpr* node);
		vl::Ptr<Name> CopyNode(Name* node);
		vl::Ptr<PointerType> CopyNode(PointerType* node);
		vl::Ptr<QualifiedName> CopyNode(QualifiedName* node);
		vl::Ptr<ThrowExpr> CopyNode(ThrowExpr* node);
		vl::Ptr<TypeOrExprToResolve> CopyNode(TypeOrExprToResolve* node);
	};
}
#endif