/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:ExprAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "BinaryOpExprAst.h"

namespace binaryop
{
/***********************************************************************
Visitor Pattern Implementation
***********************************************************************/

	void RefExpr::Accept(Expr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void BinaryExpr::Accept(Expr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}
}
namespace vl::reflection::description
{
#ifndef VCZH_DEBUG_NO_REFLECTION

	IMPL_TYPE_INFO_RENAME(binaryop::Expr, binaryop::Expr)
	IMPL_TYPE_INFO_RENAME(binaryop::Expr::IVisitor, binaryop::Expr::IVisitor)
	IMPL_TYPE_INFO_RENAME(binaryop::RefExpr, binaryop::RefExpr)
	IMPL_TYPE_INFO_RENAME(binaryop::BinaryOp, binaryop::BinaryOp)
	IMPL_TYPE_INFO_RENAME(binaryop::BinaryExpr, binaryop::BinaryExpr)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA

	BEGIN_CLASS_MEMBER(binaryop::Expr)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

	END_CLASS_MEMBER(binaryop::Expr)

	BEGIN_CLASS_MEMBER(binaryop::RefExpr)
		CLASS_MEMBER_BASE(binaryop::Expr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<binaryop::RefExpr>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(name)
	END_CLASS_MEMBER(binaryop::RefExpr)

	BEGIN_ENUM_ITEM(binaryop::BinaryOp)
		ENUM_ITEM_NAMESPACE(binaryop::BinaryOp)
		ENUM_NAMESPACE_ITEM(Add)
		ENUM_NAMESPACE_ITEM(Mul)
		ENUM_NAMESPACE_ITEM(Exp)
		ENUM_NAMESPACE_ITEM(Assign)
		ENUM_NAMESPACE_ITEM(Try)
		ENUM_NAMESPACE_ITEM(Dollar)
	END_ENUM_ITEM(binaryop::BinaryOp)

	BEGIN_CLASS_MEMBER(binaryop::BinaryExpr)
		CLASS_MEMBER_BASE(binaryop::Expr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<binaryop::BinaryExpr>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(op)
		CLASS_MEMBER_FIELD(left)
		CLASS_MEMBER_FIELD(right)
	END_CLASS_MEMBER(binaryop::BinaryExpr)

	BEGIN_INTERFACE_MEMBER(binaryop::Expr::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(binaryop::Expr::IVisitor::*)(binaryop::RefExpr* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(binaryop::Expr::IVisitor::*)(binaryop::BinaryExpr* node))
	END_INTERFACE_MEMBER(binaryop::Expr)

#endif

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	class BinaryOpExprAstTypeLoader : public vl::Object, public ITypeLoader
	{
	public:
		void Load(ITypeManager* manager)
		{
			ADD_TYPE_INFO(binaryop::Expr)
			ADD_TYPE_INFO(binaryop::Expr::IVisitor)
			ADD_TYPE_INFO(binaryop::RefExpr)
			ADD_TYPE_INFO(binaryop::BinaryOp)
			ADD_TYPE_INFO(binaryop::BinaryExpr)
		}

		void Unload(ITypeManager* manager)
		{
		}
	};
#endif
#endif

	bool BinaryOpExprAstLoadTypes()
	{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		if (auto manager = GetGlobalTypeManager())
		{
			auto loader = Ptr(new BinaryOpExprAstTypeLoader);
			return manager->AddTypeLoader(loader);
		}
#endif
		return false;
	}
}