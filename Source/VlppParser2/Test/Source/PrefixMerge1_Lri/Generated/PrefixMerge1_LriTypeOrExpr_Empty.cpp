/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "PrefixMerge1_LriTypeOrExpr_Empty.h"

namespace prefixmerge1_lri::empty_visitor
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

	void TypeOrExprVisitor::Visit(MulExpr* node)
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
}
