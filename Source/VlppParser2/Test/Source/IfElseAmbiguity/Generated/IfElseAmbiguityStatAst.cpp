/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:StatAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "IfElseAmbiguityStatAst.h"

namespace ifelseambiguity
{
/***********************************************************************
Visitor Pattern Implementation
***********************************************************************/

	void DoStat::Accept(Stat::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void IfContentToResolve::Accept(IfContent::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void IfContentCandidate::Accept(IfContent::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void IfStat::Accept(Stat::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void BlockStat::Accept(Stat::IVisitor* visitor)
	{
		visitor->Visit(this);
	}
}
namespace vl::reflection::description
{
#ifndef VCZH_DEBUG_NO_REFLECTION

	IMPL_TYPE_INFO_RENAME(ifelseambiguity::Stat, ifelseambiguity::Stat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::Stat::IVisitor, ifelseambiguity::Stat::IVisitor)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::DoStat, ifelseambiguity::DoStat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::IfContent, ifelseambiguity::IfContent)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::IfContent::IVisitor, ifelseambiguity::IfContent::IVisitor)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::IfContentToResolve, ifelseambiguity::IfContentToResolve)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::IfContentCandidate, ifelseambiguity::IfContentCandidate)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::IfStat, ifelseambiguity::IfStat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::BlockStat, ifelseambiguity::BlockStat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguity::Module, ifelseambiguity::Module)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA

	BEGIN_CLASS_MEMBER(ifelseambiguity::Stat)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

	END_CLASS_MEMBER(ifelseambiguity::Stat)

	BEGIN_CLASS_MEMBER(ifelseambiguity::DoStat)
		CLASS_MEMBER_BASE(ifelseambiguity::Stat)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguity::DoStat>(), NO_PARAMETER)

	END_CLASS_MEMBER(ifelseambiguity::DoStat)

	BEGIN_CLASS_MEMBER(ifelseambiguity::IfContent)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

	END_CLASS_MEMBER(ifelseambiguity::IfContent)

	BEGIN_CLASS_MEMBER(ifelseambiguity::IfContentToResolve)
		CLASS_MEMBER_BASE(ifelseambiguity::IfContent)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguity::IfContentToResolve>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(candidates)
	END_CLASS_MEMBER(ifelseambiguity::IfContentToResolve)

	BEGIN_CLASS_MEMBER(ifelseambiguity::IfContentCandidate)
		CLASS_MEMBER_BASE(ifelseambiguity::IfContent)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguity::IfContentCandidate>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(thenBranch)
		CLASS_MEMBER_FIELD(elseBranch)
	END_CLASS_MEMBER(ifelseambiguity::IfContentCandidate)

	BEGIN_CLASS_MEMBER(ifelseambiguity::IfStat)
		CLASS_MEMBER_BASE(ifelseambiguity::Stat)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguity::IfStat>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(content)
	END_CLASS_MEMBER(ifelseambiguity::IfStat)

	BEGIN_CLASS_MEMBER(ifelseambiguity::BlockStat)
		CLASS_MEMBER_BASE(ifelseambiguity::Stat)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguity::BlockStat>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(stats)
	END_CLASS_MEMBER(ifelseambiguity::BlockStat)

	BEGIN_CLASS_MEMBER(ifelseambiguity::Module)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguity::Module>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(stat)
	END_CLASS_MEMBER(ifelseambiguity::Module)

	BEGIN_INTERFACE_MEMBER(ifelseambiguity::Stat::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguity::Stat::IVisitor::*)(ifelseambiguity::DoStat* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguity::Stat::IVisitor::*)(ifelseambiguity::IfStat* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguity::Stat::IVisitor::*)(ifelseambiguity::BlockStat* node))
	END_INTERFACE_MEMBER(ifelseambiguity::Stat)

	BEGIN_INTERFACE_MEMBER(ifelseambiguity::IfContent::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguity::IfContent::IVisitor::*)(ifelseambiguity::IfContentToResolve* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguity::IfContent::IVisitor::*)(ifelseambiguity::IfContentCandidate* node))
	END_INTERFACE_MEMBER(ifelseambiguity::IfContent)

#endif

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	class IfElseAmbiguityStatAstTypeLoader : public vl::Object, public ITypeLoader
	{
	public:
		void Load(ITypeManager* manager)
		{
			ADD_TYPE_INFO(ifelseambiguity::Stat)
			ADD_TYPE_INFO(ifelseambiguity::Stat::IVisitor)
			ADD_TYPE_INFO(ifelseambiguity::DoStat)
			ADD_TYPE_INFO(ifelseambiguity::IfContent)
			ADD_TYPE_INFO(ifelseambiguity::IfContent::IVisitor)
			ADD_TYPE_INFO(ifelseambiguity::IfContentToResolve)
			ADD_TYPE_INFO(ifelseambiguity::IfContentCandidate)
			ADD_TYPE_INFO(ifelseambiguity::IfStat)
			ADD_TYPE_INFO(ifelseambiguity::BlockStat)
			ADD_TYPE_INFO(ifelseambiguity::Module)
		}

		void Unload(ITypeManager* manager)
		{
		}
	};
#endif
#endif

	bool IfElseAmbiguityStatAstLoadTypes()
	{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		if (auto manager = GetGlobalTypeManager())
		{
			auto loader = Ptr(new IfElseAmbiguityStatAstTypeLoader);
			return manager->AddTypeLoader(loader);
		}
#endif
		return false;
	}
}
