/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST_EMPTY_VISITOR
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST_EMPTY_VISITOR

#include "PrefixMerge7_PmSwitchTypeOrExpr.h"

namespace prefixmerge7_pmswitch::empty_visitor
{
	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class TypeOrExprVisitor : public vl::Object, public TypeOrExpr::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------
		virtual void Dispatch(QualifiedName* node) = 0;

	public:
		// Visitor Members -----------------------------------
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
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class QualifiedNameVisitor : public vl::Object, public QualifiedName::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------
		virtual void Dispatch(GenericQualifiedName* node) = 0;

	public:
		// Visitor Members -----------------------------------
		void Visit(Name* node) override;
		void Visit(MemberName* node) override;
		void Visit(GenericQualifiedName* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class GenericQualifiedNameVisitor : public vl::Object, public GenericQualifiedName::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(GenericName* node) override;
		void Visit(GenericMemberName* node) override;
	};

}
#endif