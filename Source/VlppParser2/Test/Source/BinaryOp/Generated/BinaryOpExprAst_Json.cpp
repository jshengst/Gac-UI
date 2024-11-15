/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:ExprAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "BinaryOpExprAst_Json.h"

namespace binaryop::json_visitor
{
	void ExprAstVisitor::PrintFields(BinaryExpr* node)
	{
		BeginField(vl::WString::Unmanaged(L"left"));
		Print(node->left.Obj());
		EndField();
		BeginField(vl::WString::Unmanaged(L"op"));
		switch (node->op)
		{
		case binaryop::BinaryOp::Add:
			WriteString(vl::WString::Unmanaged(L"Add"));
			break;
		case binaryop::BinaryOp::Assign:
			WriteString(vl::WString::Unmanaged(L"Assign"));
			break;
		case binaryop::BinaryOp::Dollar:
			WriteString(vl::WString::Unmanaged(L"Dollar"));
			break;
		case binaryop::BinaryOp::Exp:
			WriteString(vl::WString::Unmanaged(L"Exp"));
			break;
		case binaryop::BinaryOp::Mul:
			WriteString(vl::WString::Unmanaged(L"Mul"));
			break;
		case binaryop::BinaryOp::Try:
			WriteString(vl::WString::Unmanaged(L"Try"));
			break;
		default:
			WriteNull();
		}
		EndField();
		BeginField(vl::WString::Unmanaged(L"right"));
		Print(node->right.Obj());
		EndField();
	}
	void ExprAstVisitor::PrintFields(Expr* node)
	{
	}
	void ExprAstVisitor::PrintFields(RefExpr* node)
	{
		BeginField(vl::WString::Unmanaged(L"name"));
		WriteToken(node->name);
		EndField();
	}

	void ExprAstVisitor::Visit(RefExpr* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"RefExpr"), node);
		PrintFields(static_cast<Expr*>(node));
		PrintFields(static_cast<RefExpr*>(node));
		EndObject();
	}

	void ExprAstVisitor::Visit(BinaryExpr* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"BinaryExpr"), node);
		PrintFields(static_cast<Expr*>(node));
		PrintFields(static_cast<BinaryExpr*>(node));
		EndObject();
	}

	ExprAstVisitor::ExprAstVisitor(vl::stream::StreamWriter& _writer)
		: vl::glr::JsonVisitorBase(_writer)
	{
	}

	void ExprAstVisitor::Print(Expr* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		node->Accept(static_cast<Expr::IVisitor*>(this));
	}

}
