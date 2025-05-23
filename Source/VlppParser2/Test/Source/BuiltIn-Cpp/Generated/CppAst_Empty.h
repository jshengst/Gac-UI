/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Ast
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_BUILTIN_CPP_AST_AST_EMPTY_VISITOR
#define VCZH_PARSER2_BUILTIN_CPP_AST_AST_EMPTY_VISITOR

#include "CppAst.h"

namespace cpp_parser::empty_visitor
{
	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class TypeOrExprOrOthersVisitor : public vl::Object, public CppTypeOrExprOrOthers::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------
		virtual void Dispatch(CppDeclaration* node) = 0;
		virtual void Dispatch(CppTypeOrExpr* node) = 0;

	public:
		// Visitor Members -----------------------------------
		void Visit(CppTypeOrExprOrOthersToResolve* node) override;
		void Visit(CppDeclaration* node) override;
		void Visit(CppTypeOrExpr* node) override;
		void Visit(CppOrdinaryGenericParameter* node) override;
		void Visit(CppGenericArgument* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class DeclarationVisitor : public vl::Object, public CppDeclaration::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------
		virtual void Dispatch(CppDeclarationCommon* node) = 0;

	public:
		// Visitor Members -----------------------------------
		void Visit(CppDeclarationToResolve* node) override;
		void Visit(CppDeclarationCommon* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class DeclarationCommonVisitor : public vl::Object, public CppDeclarationCommon::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppVariablesDeclaration* node) override;
		void Visit(CppClassDeclaration* node) override;
		void Visit(CppEnumDeclaration* node) override;
		void Visit(CppTemplateDeclaration* node) override;
		void Visit(CppStaticAssertDeclaration* node) override;
		void Visit(CppTypedefDeclaration* node) override;
		void Visit(CppExternDeclaration* node) override;
		void Visit(CppNamespaceDeclaration* node) override;
		void Visit(CppUsingNamespaceDeclaration* node) override;
		void Visit(CppUsingValueDeclaration* node) override;
		void Visit(CppUsingTypeDeclaration* node) override;
		void Visit(CppFriendTypeDeclaration* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class TypeOrExprVisitor : public vl::Object, public CppTypeOrExpr::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------
		virtual void Dispatch(CppExprOnly* node) = 0;
		virtual void Dispatch(CppTypeOnly* node) = 0;

	public:
		// Visitor Members -----------------------------------
		void Visit(CppTypeOrExprToResolve* node) override;
		void Visit(CppExprOnly* node) override;
		void Visit(CppTypeOnly* node) override;
		void Visit(CppQualifiedName* node) override;
		void Visit(CppDeclaratorType* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class ExprOnlyVisitor : public vl::Object, public CppExprOnly::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppPrimitiveExprLiteral* node) override;
		void Visit(CppNumericExprLiteral* node) override;
		void Visit(CppStringLiteral* node) override;
		void Visit(CppLambdaExpr* node) override;
		void Visit(CppParenthesisExpr* node) override;
		void Visit(CppBraceExpr* node) override;
		void Visit(CppCastExpr* node) override;
		void Visit(CppSysFuncExpr* node) override;
		void Visit(CppSizeofExpr* node) override;
		void Visit(CppDeleteExpr* node) override;
		void Visit(CppNewExpr* node) override;
		void Visit(CppPrefixUnaryExpr* node) override;
		void Visit(CppPostfixUnaryExpr* node) override;
		void Visit(CppIndexExpr* node) override;
		void Visit(CppCallExpr* node) override;
		void Visit(CppBinaryExpr* node) override;
		void Visit(CppIfExpr* node) override;
		void Visit(CppThrowExpr* node) override;
		void Visit(CppVariadicExpr* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class TypeOnlyVisitor : public vl::Object, public CppTypeOnly::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppPrimitiveType* node) override;
		void Visit(CppConstType* node) override;
		void Visit(CppVolatileType* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class StatementVisitor : public vl::Object, public CppStatement::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppStatementToResolve* node) override;
		void Visit(CppEmptyStat* node) override;
		void Visit(CppBlockStat* node) override;
		void Visit(CppExprStat* node) override;
		void Visit(CppDeclStat* node) override;
		void Visit(CppBreakStat* node) override;
		void Visit(CppContinueStat* node) override;
		void Visit(CppReturnStat* node) override;
		void Visit(CppLabelStat* node) override;
		void Visit(CppGotoStat* node) override;
		void Visit(CppCaseStat* node) override;
		void Visit(CppDefaultStat* node) override;
		void Visit(Cpp__LeaveStat* node) override;
		void Visit(CppWhileStat* node) override;
		void Visit(CppDoWhileStat* node) override;
		void Visit(CppIfElseStat* node) override;
		void Visit(CppForStat* node) override;
		void Visit(CppSwitchStat* node) override;
		void Visit(CppTryStat* node) override;
		void Visit(Cpp__TryStat* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class IdentifierVisitor : public vl::Object, public CppIdentifier::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppNameIdentifier* node) override;
		void Visit(CppOperatorIdentifier* node) override;
		void Visit(CppOperatorTypeIdentifier* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class DeclaratorFunctionPartVisitor : public vl::Object, public CppDeclaratorFunctionPart::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppDeclaratorFunctionPartToResolve* node) override;
		void Visit(CppDeclaratorFunctionPartCommon* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class VarInitVisitor : public vl::Object, public CppVarInit::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppVarValueInit* node) override;
		void Visit(CppVarParanthesisInit* node) override;
		void Visit(CppVarBraceInit* node) override;
		void Visit(CppVarStatInit* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class DeclaratorVariablePartVisitor : public vl::Object, public CppDeclaratorVariablePart::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppDeclaratorVariablePartToResolve* node) override;
		void Visit(CppDeclaratorVariablePartCommon* node) override;
	};

	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class ForStatConditionPartVisitor : public vl::Object, public CppForStatConditionPart::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(CppForStatLoopCondition* node) override;
		void Visit(CppForStatIterateCondition* node) override;
	};

}
#endif