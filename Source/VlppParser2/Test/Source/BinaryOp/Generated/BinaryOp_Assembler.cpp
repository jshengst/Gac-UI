/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:BinaryOp
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "BinaryOp_Assembler.h"

namespace binaryop
{

/***********************************************************************
BinaryOpAstInsReceiver : public vl::glr::AstInsReceiverBase
***********************************************************************/

	vl::Ptr<vl::glr::ParsingAstBase> BinaryOpAstInsReceiver::CreateAstNode(vl::vint32_t type)
	{
		auto cppTypeName = BinaryOpCppTypeName((BinaryOpClasses)type);
		switch((BinaryOpClasses)type)
		{
		case BinaryOpClasses::BinaryExpr:
			return vl::Ptr(new binaryop::BinaryExpr);
		case BinaryOpClasses::RefExpr:
			return vl::Ptr(new binaryop::RefExpr);
		default:
			return vl::glr::AssemblyThrowCannotCreateAbstractType(type, cppTypeName);
		}
	}

	void BinaryOpAstInsReceiver::SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, vl::Ptr<vl::glr::ParsingAstBase> value)
	{
		auto cppFieldName = BinaryOpCppFieldName((BinaryOpFields)field);
		switch((BinaryOpFields)field)
		{
		case BinaryOpFields::BinaryExpr_left:
			return vl::glr::AssemblerSetObjectField(&binaryop::BinaryExpr::left, object, field, value, cppFieldName);
		case BinaryOpFields::BinaryExpr_right:
			return vl::glr::AssemblerSetObjectField(&binaryop::BinaryExpr::right, object, field, value, cppFieldName);
		default:
			return vl::glr::AssemblyThrowFieldNotObject(field, cppFieldName);
		}
	}

	void BinaryOpAstInsReceiver::SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, const vl::regex::RegexToken& token, vl::vint32_t tokenIndex)
	{
		auto cppFieldName = BinaryOpCppFieldName((BinaryOpFields)field);
		switch((BinaryOpFields)field)
		{
		case BinaryOpFields::RefExpr_name:
			return vl::glr::AssemblerSetTokenField(&binaryop::RefExpr::name, object, field, token, tokenIndex, cppFieldName);
		default:
			return vl::glr::AssemblyThrowFieldNotToken(field, cppFieldName);
		}
	}

	void BinaryOpAstInsReceiver::SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, vl::vint32_t enumItem, bool weakAssignment)
	{
		auto cppFieldName = BinaryOpCppFieldName((BinaryOpFields)field);
		switch((BinaryOpFields)field)
		{
		case BinaryOpFields::BinaryExpr_op:
			return vl::glr::AssemblerSetEnumField(&binaryop::BinaryExpr::op, object, field, enumItem, weakAssignment, cppFieldName);
		default:
			return vl::glr::AssemblyThrowFieldNotEnum(field, cppFieldName);
		}
	}

	const wchar_t* BinaryOpTypeName(BinaryOpClasses type)
	{
		const wchar_t* results[] = {
			L"BinaryExpr",
			L"Expr",
			L"RefExpr",
		};
		vl::vint index = (vl::vint)type;
		return 0 <= index && index < 3 ? results[index] : nullptr;
	}

	const wchar_t* BinaryOpCppTypeName(BinaryOpClasses type)
	{
		const wchar_t* results[] = {
			L"binaryop::BinaryExpr",
			L"binaryop::Expr",
			L"binaryop::RefExpr",
		};
		vl::vint index = (vl::vint)type;
		return 0 <= index && index < 3 ? results[index] : nullptr;
	}

	const wchar_t* BinaryOpFieldName(BinaryOpFields field)
	{
		const wchar_t* results[] = {
			L"BinaryExpr::left",
			L"BinaryExpr::op",
			L"BinaryExpr::right",
			L"RefExpr::name",
		};
		vl::vint index = (vl::vint)field;
		return 0 <= index && index < 4 ? results[index] : nullptr;
	}

	const wchar_t* BinaryOpCppFieldName(BinaryOpFields field)
	{
		const wchar_t* results[] = {
			L"binaryop::BinaryExpr::left",
			L"binaryop::BinaryExpr::op",
			L"binaryop::BinaryExpr::right",
			L"binaryop::RefExpr::name",
		};
		vl::vint index = (vl::vint)field;
		return 0 <= index && index < 4 ? results[index] : nullptr;
	}

	vl::Ptr<vl::glr::ParsingAstBase> BinaryOpAstInsReceiver::ResolveAmbiguity(vl::vint32_t type, vl::collections::Array<vl::Ptr<vl::glr::ParsingAstBase>>& candidates)
	{
		auto cppTypeName = BinaryOpCppTypeName((BinaryOpClasses)type);
		return vl::glr::AssemblyThrowTypeNotAllowAmbiguity(type, cppTypeName);
	}
}
