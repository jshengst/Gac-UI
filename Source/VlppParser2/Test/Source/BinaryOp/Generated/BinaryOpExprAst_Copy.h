/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:ExprAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_BINARYOP_EXPRAST_AST_COPY_VISITOR
#define VCZH_PARSER2_UNITTEST_BINARYOP_EXPRAST_AST_COPY_VISITOR

#include "BinaryOpExprAst.h"

namespace binaryop::copy_visitor
{
	/// <summary>A copy visitor, overriding all abstract methods with AST copying code.</summary>
	class ExprAstVisitor
		: public virtual vl::glr::CopyVisitorBase
		, protected virtual Expr::IVisitor
	{
	protected:
		void CopyFields(BinaryExpr* from, BinaryExpr* to);
		void CopyFields(Expr* from, Expr* to);
		void CopyFields(RefExpr* from, RefExpr* to);

	protected:

		void Visit(RefExpr* node) override;
		void Visit(BinaryExpr* node) override;

	public:
		virtual vl::Ptr<Expr> CopyNode(Expr* node);

		vl::Ptr<BinaryExpr> CopyNode(BinaryExpr* node);
		vl::Ptr<RefExpr> CopyNode(RefExpr* node);
	};
}
#endif