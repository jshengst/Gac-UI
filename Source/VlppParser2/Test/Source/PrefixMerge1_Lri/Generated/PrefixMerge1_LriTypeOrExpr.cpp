/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "PrefixMerge1_LriTypeOrExpr.h"

namespace prefixmerge1_lri
{
/***********************************************************************
Visitor Pattern Implementation
***********************************************************************/

	void TypeOrExprToResolve::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void QualifiedName::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void Name::Accept(QualifiedName::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void MemberName::Accept(QualifiedName::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void CallExpr::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void MulExpr::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void ConstType::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void PointerType::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void FunctionType::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}
}
namespace vl::reflection::description
{
#ifndef VCZH_DEBUG_NO_REFLECTION

	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::TypeOrExpr, prefixmerge1_lri::TypeOrExpr)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::TypeOrExpr::IVisitor, prefixmerge1_lri::TypeOrExpr::IVisitor)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::TypeOrExprToResolve, prefixmerge1_lri::TypeOrExprToResolve)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::QualifiedName, prefixmerge1_lri::QualifiedName)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::QualifiedName::IVisitor, prefixmerge1_lri::QualifiedName::IVisitor)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::Name, prefixmerge1_lri::Name)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::MemberName, prefixmerge1_lri::MemberName)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::CallExpr, prefixmerge1_lri::CallExpr)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::MulExpr, prefixmerge1_lri::MulExpr)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::ConstType, prefixmerge1_lri::ConstType)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::PointerType, prefixmerge1_lri::PointerType)
	IMPL_TYPE_INFO_RENAME(prefixmerge1_lri::FunctionType, prefixmerge1_lri::FunctionType)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::TypeOrExpr)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

	END_CLASS_MEMBER(prefixmerge1_lri::TypeOrExpr)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::TypeOrExprToResolve)
		CLASS_MEMBER_BASE(prefixmerge1_lri::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::TypeOrExprToResolve>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(candidates)
	END_CLASS_MEMBER(prefixmerge1_lri::TypeOrExprToResolve)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::QualifiedName)
		CLASS_MEMBER_BASE(prefixmerge1_lri::TypeOrExpr)

	END_CLASS_MEMBER(prefixmerge1_lri::QualifiedName)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::Name)
		CLASS_MEMBER_BASE(prefixmerge1_lri::QualifiedName)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::Name>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(name)
	END_CLASS_MEMBER(prefixmerge1_lri::Name)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::MemberName)
		CLASS_MEMBER_BASE(prefixmerge1_lri::QualifiedName)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::MemberName>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(parent)
		CLASS_MEMBER_FIELD(member)
	END_CLASS_MEMBER(prefixmerge1_lri::MemberName)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::CallExpr)
		CLASS_MEMBER_BASE(prefixmerge1_lri::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::CallExpr>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(func)
		CLASS_MEMBER_FIELD(args)
	END_CLASS_MEMBER(prefixmerge1_lri::CallExpr)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::MulExpr)
		CLASS_MEMBER_BASE(prefixmerge1_lri::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::MulExpr>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(first)
		CLASS_MEMBER_FIELD(second)
	END_CLASS_MEMBER(prefixmerge1_lri::MulExpr)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::ConstType)
		CLASS_MEMBER_BASE(prefixmerge1_lri::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::ConstType>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(type)
	END_CLASS_MEMBER(prefixmerge1_lri::ConstType)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::PointerType)
		CLASS_MEMBER_BASE(prefixmerge1_lri::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::PointerType>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(type)
	END_CLASS_MEMBER(prefixmerge1_lri::PointerType)

	BEGIN_CLASS_MEMBER(prefixmerge1_lri::FunctionType)
		CLASS_MEMBER_BASE(prefixmerge1_lri::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge1_lri::FunctionType>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(returnType)
		CLASS_MEMBER_FIELD(args)
	END_CLASS_MEMBER(prefixmerge1_lri::FunctionType)

	BEGIN_INTERFACE_MEMBER(prefixmerge1_lri::TypeOrExpr::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::TypeOrExpr::IVisitor::*)(prefixmerge1_lri::TypeOrExprToResolve* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::TypeOrExpr::IVisitor::*)(prefixmerge1_lri::QualifiedName* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::TypeOrExpr::IVisitor::*)(prefixmerge1_lri::CallExpr* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::TypeOrExpr::IVisitor::*)(prefixmerge1_lri::MulExpr* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::TypeOrExpr::IVisitor::*)(prefixmerge1_lri::ConstType* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::TypeOrExpr::IVisitor::*)(prefixmerge1_lri::PointerType* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::TypeOrExpr::IVisitor::*)(prefixmerge1_lri::FunctionType* node))
	END_INTERFACE_MEMBER(prefixmerge1_lri::TypeOrExpr)

	BEGIN_INTERFACE_MEMBER(prefixmerge1_lri::QualifiedName::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::QualifiedName::IVisitor::*)(prefixmerge1_lri::Name* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge1_lri::QualifiedName::IVisitor::*)(prefixmerge1_lri::MemberName* node))
	END_INTERFACE_MEMBER(prefixmerge1_lri::QualifiedName)

#endif

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	class PrefixMerge1_LriTypeOrExprTypeLoader : public vl::Object, public ITypeLoader
	{
	public:
		void Load(ITypeManager* manager)
		{
			ADD_TYPE_INFO(prefixmerge1_lri::TypeOrExpr)
			ADD_TYPE_INFO(prefixmerge1_lri::TypeOrExpr::IVisitor)
			ADD_TYPE_INFO(prefixmerge1_lri::TypeOrExprToResolve)
			ADD_TYPE_INFO(prefixmerge1_lri::QualifiedName)
			ADD_TYPE_INFO(prefixmerge1_lri::QualifiedName::IVisitor)
			ADD_TYPE_INFO(prefixmerge1_lri::Name)
			ADD_TYPE_INFO(prefixmerge1_lri::MemberName)
			ADD_TYPE_INFO(prefixmerge1_lri::CallExpr)
			ADD_TYPE_INFO(prefixmerge1_lri::MulExpr)
			ADD_TYPE_INFO(prefixmerge1_lri::ConstType)
			ADD_TYPE_INFO(prefixmerge1_lri::PointerType)
			ADD_TYPE_INFO(prefixmerge1_lri::FunctionType)
		}

		void Unload(ITypeManager* manager)
		{
		}
	};
#endif
#endif

	bool PrefixMerge1_LriTypeOrExprLoadTypes()
	{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		if (auto manager = GetGlobalTypeManager())
		{
			auto loader = Ptr(new PrefixMerge1_LriTypeOrExprTypeLoader);
			return manager->AddTypeLoader(loader);
		}
#endif
		return false;
	}
}