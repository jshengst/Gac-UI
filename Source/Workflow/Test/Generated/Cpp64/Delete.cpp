/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/Delete.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "Delete.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::Delete::
#define GLOBAL_NAME ::vl_workflow_global::Delete::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::Delete::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_Delete)
	vl_workflow_global::Delete instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_Delete)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	bool Delete::DoDelete(::test::ObservableValue* value)
	{
		try
		{
			{
				::vl::__vwsn::This(value)->Dispose(true);
				return true;
			}
		}
		catch(const ::vl::Exception& __vwsne_0)
		{
			auto ex = ::vl::reflection::description::IValueException::Create(__vwsne_0.Message());
			{
				return false;
			}
		}
	}

	::vl::WString Delete::main()
	{
		auto raw1 = ::test::ObservableValue::CreatePtr(static_cast<::vl::vint64_t>(0L), ::vl::WString::Unmanaged(L""));
		auto raw2 = ::test::ObservableValue::CreatePtr(static_cast<::vl::vint64_t>(0L), ::vl::WString::Unmanaged(L""));
		auto shared = ::vl::__vwsn::Ensure(::vl::Ptr<::test::ObservableValue>(raw1));
		auto a = (raw1 == nullptr);
		auto b = (raw2 == nullptr);
		auto c = (! static_cast<bool>(shared));
		auto d = GLOBAL_NAME DoDelete(raw1);
		auto e = GLOBAL_NAME DoDelete(raw2);
		return ((((((((::vl::__vwsn::ToString(a) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(b)) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(c)) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(d)) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(e));
	}

	Delete& Delete::Instance()
	{
		return Getvl_workflow_global_Delete().instance;
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