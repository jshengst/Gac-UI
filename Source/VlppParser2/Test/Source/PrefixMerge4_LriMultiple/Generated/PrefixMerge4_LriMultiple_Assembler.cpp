/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:PrefixMerge4_LriMultiple
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "PrefixMerge4_LriMultiple_Assembler.h"

namespace prefixmerge4_lrimultiple
{

/***********************************************************************
PrefixMerge4_LriMultipleAstInsReceiver : public vl::glr::AstInsReceiverBase
***********************************************************************/

	vl::Ptr<vl::glr::ParsingAstBase> PrefixMerge4_LriMultipleAstInsReceiver::CreateAstNode(vl::vint32_t type)
	{
		auto cppTypeName = PrefixMerge4_LriMultipleCppTypeName((PrefixMerge4_LriMultipleClasses)type);
		switch((PrefixMerge4_LriMultipleClasses)type)
		{
		case PrefixMerge4_LriMultipleClasses::CallExpr:
			return vl::Ptr(new prefixmerge4_lrimultiple::CallExpr);
		case PrefixMerge4_LriMultipleClasses::ConstType:
			return vl::Ptr(new prefixmerge4_lrimultiple::ConstType);
		case PrefixMerge4_LriMultipleClasses::CtorExpr:
			return vl::Ptr(new prefixmerge4_lrimultiple::CtorExpr);
		case PrefixMerge4_LriMultipleClasses::FunctionType:
			return vl::Ptr(new prefixmerge4_lrimultiple::FunctionType);
		case PrefixMerge4_LriMultipleClasses::MemberName:
			return vl::Ptr(new prefixmerge4_lrimultiple::MemberName);
		case PrefixMerge4_LriMultipleClasses::MulExpr:
			return vl::Ptr(new prefixmerge4_lrimultiple::MulExpr);
		case PrefixMerge4_LriMultipleClasses::Name:
			return vl::Ptr(new prefixmerge4_lrimultiple::Name);
		case PrefixMerge4_LriMultipleClasses::PointerType:
			return vl::Ptr(new prefixmerge4_lrimultiple::PointerType);
		case PrefixMerge4_LriMultipleClasses::TypeOrExprToResolve:
			return vl::Ptr(new prefixmerge4_lrimultiple::TypeOrExprToResolve);
		default:
			return vl::glr::AssemblyThrowCannotCreateAbstractType(type, cppTypeName);
		}
	}

	void PrefixMerge4_LriMultipleAstInsReceiver::SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, vl::Ptr<vl::glr::ParsingAstBase> value)
	{
		auto cppFieldName = PrefixMerge4_LriMultipleCppFieldName((PrefixMerge4_LriMultipleFields)field);
		switch((PrefixMerge4_LriMultipleFields)field)
		{
		case PrefixMerge4_LriMultipleFields::CallExpr_args:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::CallExpr::args, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::CallExpr_func:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::CallExpr::func, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::ConstType_type:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::ConstType::type, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::CtorExpr_args:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::CtorExpr::args, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::CtorExpr_type:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::CtorExpr::type, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::FunctionType_args:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::FunctionType::args, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::FunctionType_returnType:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::FunctionType::returnType, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::MemberName_parent:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::MemberName::parent, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::MulExpr_first:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::MulExpr::first, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::MulExpr_second:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::MulExpr::second, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::PointerType_type:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::PointerType::type, object, field, value, cppFieldName);
		case PrefixMerge4_LriMultipleFields::TypeOrExprToResolve_candidates:
			return vl::glr::AssemblerSetObjectField(&prefixmerge4_lrimultiple::TypeOrExprToResolve::candidates, object, field, value, cppFieldName);
		default:
			return vl::glr::AssemblyThrowFieldNotObject(field, cppFieldName);
		}
	}

	void PrefixMerge4_LriMultipleAstInsReceiver::SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, const vl::regex::RegexToken& token, vl::vint32_t tokenIndex)
	{
		auto cppFieldName = PrefixMerge4_LriMultipleCppFieldName((PrefixMerge4_LriMultipleFields)field);
		switch((PrefixMerge4_LriMultipleFields)field)
		{
		case PrefixMerge4_LriMultipleFields::MemberName_member:
			return vl::glr::AssemblerSetTokenField(&prefixmerge4_lrimultiple::MemberName::member, object, field, token, tokenIndex, cppFieldName);
		case PrefixMerge4_LriMultipleFields::Name_name:
			return vl::glr::AssemblerSetTokenField(&prefixmerge4_lrimultiple::Name::name, object, field, token, tokenIndex, cppFieldName);
		default:
			return vl::glr::AssemblyThrowFieldNotToken(field, cppFieldName);
		}
	}

	void PrefixMerge4_LriMultipleAstInsReceiver::SetField(vl::glr::ParsingAstBase* object, vl::vint32_t field, vl::vint32_t enumItem, bool weakAssignment)
	{
		auto cppFieldName = PrefixMerge4_LriMultipleCppFieldName((PrefixMerge4_LriMultipleFields)field);
		return vl::glr::AssemblyThrowFieldNotEnum(field, cppFieldName);
	}

	const wchar_t* PrefixMerge4_LriMultipleTypeName(PrefixMerge4_LriMultipleClasses type)
	{
		const wchar_t* results[] = {
			L"CallExpr",
			L"ConstType",
			L"CtorExpr",
			L"FunctionType",
			L"MemberName",
			L"MulExpr",
			L"Name",
			L"PointerType",
			L"QualifiedName",
			L"TypeOrExpr",
			L"TypeOrExprToResolve",
		};
		vl::vint index = (vl::vint)type;
		return 0 <= index && index < 11 ? results[index] : nullptr;
	}

	const wchar_t* PrefixMerge4_LriMultipleCppTypeName(PrefixMerge4_LriMultipleClasses type)
	{
		const wchar_t* results[] = {
			L"prefixmerge4_lrimultiple::CallExpr",
			L"prefixmerge4_lrimultiple::ConstType",
			L"prefixmerge4_lrimultiple::CtorExpr",
			L"prefixmerge4_lrimultiple::FunctionType",
			L"prefixmerge4_lrimultiple::MemberName",
			L"prefixmerge4_lrimultiple::MulExpr",
			L"prefixmerge4_lrimultiple::Name",
			L"prefixmerge4_lrimultiple::PointerType",
			L"prefixmerge4_lrimultiple::QualifiedName",
			L"prefixmerge4_lrimultiple::TypeOrExpr",
			L"prefixmerge4_lrimultiple::TypeOrExprToResolve",
		};
		vl::vint index = (vl::vint)type;
		return 0 <= index && index < 11 ? results[index] : nullptr;
	}

	const wchar_t* PrefixMerge4_LriMultipleFieldName(PrefixMerge4_LriMultipleFields field)
	{
		const wchar_t* results[] = {
			L"CallExpr::args",
			L"CallExpr::func",
			L"ConstType::type",
			L"CtorExpr::args",
			L"CtorExpr::type",
			L"FunctionType::args",
			L"FunctionType::returnType",
			L"MemberName::member",
			L"MemberName::parent",
			L"MulExpr::first",
			L"MulExpr::second",
			L"Name::name",
			L"PointerType::type",
			L"TypeOrExprToResolve::candidates",
		};
		vl::vint index = (vl::vint)field;
		return 0 <= index && index < 14 ? results[index] : nullptr;
	}

	const wchar_t* PrefixMerge4_LriMultipleCppFieldName(PrefixMerge4_LriMultipleFields field)
	{
		const wchar_t* results[] = {
			L"prefixmerge4_lrimultiple::CallExpr::args",
			L"prefixmerge4_lrimultiple::CallExpr::func",
			L"prefixmerge4_lrimultiple::ConstType::type",
			L"prefixmerge4_lrimultiple::CtorExpr::args",
			L"prefixmerge4_lrimultiple::CtorExpr::type",
			L"prefixmerge4_lrimultiple::FunctionType::args",
			L"prefixmerge4_lrimultiple::FunctionType::returnType",
			L"prefixmerge4_lrimultiple::MemberName::member",
			L"prefixmerge4_lrimultiple::MemberName::parent",
			L"prefixmerge4_lrimultiple::MulExpr::first",
			L"prefixmerge4_lrimultiple::MulExpr::second",
			L"prefixmerge4_lrimultiple::Name::name",
			L"prefixmerge4_lrimultiple::PointerType::type",
			L"prefixmerge4_lrimultiple::TypeOrExprToResolve::candidates",
		};
		vl::vint index = (vl::vint)field;
		return 0 <= index && index < 14 ? results[index] : nullptr;
	}

	vl::Ptr<vl::glr::ParsingAstBase> PrefixMerge4_LriMultipleAstInsReceiver::ResolveAmbiguity(vl::vint32_t type, vl::collections::Array<vl::Ptr<vl::glr::ParsingAstBase>>& candidates)
	{
		auto cppTypeName = PrefixMerge4_LriMultipleCppTypeName((PrefixMerge4_LriMultipleClasses)type);
		switch((PrefixMerge4_LriMultipleClasses)type)
		{
		case PrefixMerge4_LriMultipleClasses::CallExpr:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::CallExpr, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::ConstType:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::ConstType, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::CtorExpr:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::CtorExpr, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::FunctionType:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::FunctionType, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::MemberName:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::MemberName, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::MulExpr:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::MulExpr, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::Name:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::Name, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::PointerType:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::PointerType, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::QualifiedName:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::QualifiedName, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::TypeOrExpr:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::TypeOrExpr, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		case PrefixMerge4_LriMultipleClasses::TypeOrExprToResolve:
			return vl::glr::AssemblerResolveAmbiguity<prefixmerge4_lrimultiple::TypeOrExprToResolve, prefixmerge4_lrimultiple::TypeOrExprToResolve>(type, candidates, cppTypeName);
		default:
			return vl::glr::AssemblyThrowTypeNotAllowAmbiguity(type, cppTypeName);
		}
	}
}