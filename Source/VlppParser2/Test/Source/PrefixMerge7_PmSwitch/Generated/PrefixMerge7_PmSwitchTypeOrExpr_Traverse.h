/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST_TRAVERSE_VISITOR
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST_TRAVERSE_VISITOR

#include "PrefixMerge7_PmSwitchTypeOrExpr.h"

namespace prefixmerge7_pmswitch::traverse_visitor
{
	/// <summary>A traverse visitor, overriding all abstract methods with AST visiting code.</summary>
	class TypeOrExprVisitor
		: public vl::Object
		, protected virtual TypeOrExpr::IVisitor
		, protected virtual QualifiedName::IVisitor
		, protected virtual GenericQualifiedName::IVisitor
	{
	protected:
		virtual void Traverse(vl::glr::ParsingToken& token);
		virtual void Traverse(vl::glr::ParsingAstBase* node);
		virtual void Traverse(CallExpr* node);
		virtual void Traverse(CommaExpr* node);
		virtual void Traverse(ConstType* node);
		virtual void Traverse(CtorExpr* node);
		virtual void Traverse(FunctionType* node);
		virtual void Traverse(GenericMemberName* node);
		virtual void Traverse(GenericName* node);
		virtual void Traverse(GenericQualifiedName* node);
		virtual void Traverse(GtExpr* node);
		virtual void Traverse(LtExpr* node);
		virtual void Traverse(MemberName* node);
		virtual void Traverse(MulExpr* node);
		virtual void Traverse(Name* node);
		virtual void Traverse(PointerType* node);
		virtual void Traverse(QualifiedName* node);
		virtual void Traverse(ThrowExpr* node);
		virtual void Traverse(TypeOrExpr* node);
		virtual void Traverse(TypeOrExprToResolve* node);

	protected:
		virtual void Finishing(vl::glr::ParsingAstBase* node);
		virtual void Finishing(CallExpr* node);
		virtual void Finishing(CommaExpr* node);
		virtual void Finishing(ConstType* node);
		virtual void Finishing(CtorExpr* node);
		virtual void Finishing(FunctionType* node);
		virtual void Finishing(GenericMemberName* node);
		virtual void Finishing(GenericName* node);
		virtual void Finishing(GenericQualifiedName* node);
		virtual void Finishing(GtExpr* node);
		virtual void Finishing(LtExpr* node);
		virtual void Finishing(MemberName* node);
		virtual void Finishing(MulExpr* node);
		virtual void Finishing(Name* node);
		virtual void Finishing(PointerType* node);
		virtual void Finishing(QualifiedName* node);
		virtual void Finishing(ThrowExpr* node);
		virtual void Finishing(TypeOrExpr* node);
		virtual void Finishing(TypeOrExprToResolve* node);

	protected:
		void Visit(TypeOrExprToResolve* node) override;
		void Visit(QualifiedName* node) override;
		void Visit(CallExpr* node) override;
		void Visit(CtorExpr* node) override;
		void Visit(MulExpr* node) override;
		void Visit(LtExpr* node) override;
		void Visit(GtExpr* node) override;
		void Visit(ThrowExpr* node) override;
		void Visit(CommaExpr* node) override;
		void Visit(ConstType* node) override;
		void Visit(PointerType* node) override;
		void Visit(FunctionType* node) override;

		void Visit(Name* node) override;
		void Visit(MemberName* node) override;
		void Visit(GenericQualifiedName* node) override;

		void Visit(GenericName* node) override;
		void Visit(GenericMemberName* node) override;

	public:
		void InspectInto(TypeOrExpr* node);
	};
}
#endif