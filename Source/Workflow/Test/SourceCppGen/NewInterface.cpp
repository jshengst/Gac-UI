/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/NewInterface.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "NewInterface.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::NewInterface::
#define GLOBAL_NAME ::vl_workflow_global::NewInterface::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::NewInterface::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_NewInterface)
	vl_workflow_global::NewInterface instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_NewInterface)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString NewInterface::Show1(const ::vl::collections::LazyList<::vl::vint>& xs)
	{
		auto s = ::vl::WString::Unmanaged(L"");
		{
			auto __vwsn_for_enumerable_x = ::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueEnumerable>(xs);
			auto __vwsn_for_enumerator_x = ::vl::__vwsn::This(__vwsn_for_enumerable_x.Obj())->CreateEnumerator();
			while (::vl::__vwsn::This(__vwsn_for_enumerator_x.Obj())->Next())
			{
				auto x = ::vl::__vwsn::Unbox<::vl::vint>(::vl::__vwsn::This(__vwsn_for_enumerator_x.Obj())->GetCurrent());
				{
					if ((s == ::vl::WString::Unmanaged(L"")))
					{
						(s = (s + ::vl::__vwsn::ToString(x)));
					}
					else
					{
						(s = ((s + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(x)));
					}
				}
			}
		}
		return s;
	}

	::vl::WString NewInterface::Show2(const ::vl::collections::LazyList<::vl::vint>& xs)
	{
		auto s = ::vl::WString::Unmanaged(L"");
		{
			auto __vwsn_for_enumerable_x = ::vl::reflection::description::Sys::ReverseEnumerable(::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueEnumerable>(xs));
			auto __vwsn_for_enumerator_x = ::vl::__vwsn::This(__vwsn_for_enumerable_x.Obj())->CreateEnumerator();
			while (::vl::__vwsn::This(__vwsn_for_enumerator_x.Obj())->Next())
			{
				auto x = ::vl::__vwsn::Unbox<::vl::vint>(::vl::__vwsn::This(__vwsn_for_enumerator_x.Obj())->GetCurrent());
				{
					if ((s == ::vl::WString::Unmanaged(L"")))
					{
						(s = (s + ::vl::__vwsn::ToString(x)));
					}
					else
					{
						(s = ((s + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(x)));
					}
				}
			}
		}
		return s;
	}

	::vl::WString NewInterface::main()
	{
		auto begin = static_cast<::vl::vint>(1);
		auto end = static_cast<::vl::vint>(5);
		auto xs = ::vl::reflection::description::GetLazyList<::vl::vint>(::vl::Ptr<::vl::reflection::description::IValueEnumerable>(new ::vl_workflow_global::__vwsnc1_NewInterface_main__vl_reflection_description_IValueEnumerable(begin, end)));
		return ((((::vl::WString::Unmanaged(L"[") + GLOBAL_NAME Show1(xs)) + ::vl::WString::Unmanaged(L"][")) + GLOBAL_NAME Show2(xs)) + ::vl::WString::Unmanaged(L"]"));
	}

	NewInterface& NewInterface::Instance()
	{
		return Getvl_workflow_global_NewInterface().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnc1_NewInterface_main__vl_reflection_description_IValueEnumerable::__vwsnc1_NewInterface_main__vl_reflection_description_IValueEnumerable(::vl::vint __vwsnctor_begin, ::vl::vint __vwsnctor_end)
		:begin(__vwsnctor_begin)
		, end(__vwsnctor_end)
	{
	}

	::vl::Ptr<::vl::reflection::description::IValueEnumerator> __vwsnc1_NewInterface_main__vl_reflection_description_IValueEnumerable::CreateEnumerator()
	{
		return ::vl::Ptr<::vl::reflection::description::IValueEnumerator>(new ::vl_workflow_global::__vwsnc2_NewInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator(this->begin, this->end, this));
	}

	//-------------------------------------------------------------------

	__vwsnc2_NewInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::__vwsnc2_NewInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator(::vl::vint __vwsnctor_begin, ::vl::vint __vwsnctor_end, ::vl::reflection::description::IValueEnumerable* __vwsnctorthis_0)
		:begin(__vwsnctor_begin)
		, end(__vwsnctor_end)
		, __vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
		this->index = (- static_cast<::vl::vint>(1));
	}

	::vl::reflection::description::Value __vwsnc2_NewInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::GetCurrent()
	{
		return ::vl::__vwsn::Box((this->begin + index));
	}

	::vl::vint __vwsnc2_NewInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::GetIndex()
	{
		return index;
	}

	bool __vwsnc2_NewInterface_main_CreateEnumerator__vl_reflection_description_IValueEnumerator::Next()
	{
		if ((index == (this->end - this->begin)))
		{
			return false;
		}
		else
		{
			(index = (index + static_cast<::vl::vint>(1)));
			return true;
		}
	}

}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif