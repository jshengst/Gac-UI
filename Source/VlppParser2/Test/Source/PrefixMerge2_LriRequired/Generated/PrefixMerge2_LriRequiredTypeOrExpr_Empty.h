/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE2_LRIREQUIRED_TYPEOREXPR_AST_EMPTY_VISITOR
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE2_LRIREQUIRED_TYPEOREXPR_AST_EMPTY_VISITOR

#include "PrefixMerge2_LriRequiredTypeOrExpr.h"

namespace prefixmerge2_lrirequired::empty_visitor
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
		void Visit(MulExpr* node) override;
		void Visit(ConstType* node) override;
		void Visit(PointerType* node) override;
		void Visit(FunctionType* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class QualifiedNameVisitor : public vl::Object, public QualifiedName::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(Name* node) override;
		void Visit(MemberName* node) override;
	};

}
#endif