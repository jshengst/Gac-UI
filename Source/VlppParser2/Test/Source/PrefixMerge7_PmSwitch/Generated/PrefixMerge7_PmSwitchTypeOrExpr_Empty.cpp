/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "PrefixMerge7_PmSwitchTypeOrExpr_Empty.h"

namespace prefixmerge7_pmswitch::empty_visitor
{

/***********************************************************************
TypeOrExprVisitor
***********************************************************************/

	// Visitor Members -----------------------------------

	void TypeOrExprVisitor::Visit(TypeOrExprToResolve* node)
	{
	}

	void TypeOrExprVisitor::Visit(QualifiedName* node)
	{
		Dispatch(node);
	}

	void TypeOrExprVisitor::Visit(CallExpr* node)
	{
	}

	void TypeOrExprVisitor::Visit(CtorExpr* node)
	{
	}

	void TypeOrExprVisitor::Visit(MulExpr* node)
	{
	}

	void TypeOrExprVisitor::Visit(LtExpr* node)
	{
	}

	void TypeOrExprVisitor::Visit(GtExpr* node)
	{
	}

	void TypeOrExprVisitor::Visit(ThrowExpr* node)
	{
	}

	void TypeOrExprVisitor::Visit(CommaExpr* node)
	{
	}

	void TypeOrExprVisitor::Visit(ConstType* node)
	{
	}

	void TypeOrExprVisitor::Visit(PointerType* node)
	{
	}

	void TypeOrExprVisitor::Visit(FunctionType* node)
	{
	}

/***********************************************************************
QualifiedNameVisitor
***********************************************************************/

	// Visitor Members -----------------------------------

	void QualifiedNameVisitor::Visit(Name* node)
	{
	}

	void QualifiedNameVisitor::Visit(MemberName* node)
	{
	}

	void QualifiedNameVisitor::Visit(GenericQualifiedName* node)
	{
		Dispatch(node);
	}

/***********************************************************************
GenericQualifiedNameVisitor
***********************************************************************/

	// Visitor Members -----------------------------------

	void GenericQualifiedNameVisitor::Visit(GenericName* node)
	{
	}

	void GenericQualifiedNameVisitor::Visit(GenericMemberName* node)
	{
	}
}