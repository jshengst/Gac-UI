/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/OpCompareStruct1.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "OpCompareStruct1.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::OpCompareStruct1::
#define GLOBAL_NAME ::vl_workflow_global::OpCompareStruct1::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::OpCompareStruct1::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_OpCompareStruct1)
	vl_workflow_global::OpCompareStruct1 instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_OpCompareStruct1)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString OpCompareStruct1::main()
	{
		auto p0 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.x = static_cast<::vl::vint>(0); return __vwsn_temp__; }();
		auto p1 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.y = static_cast<::vl::vint>(0); return __vwsn_temp__; }();
		auto p2 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.y = static_cast<::vl::vint>(0); __vwsn_temp__.x = static_cast<::vl::vint>(0); return __vwsn_temp__; }();
		auto p3 = ::test::Point{};
		auto p4 = [&](){ ::test::Point __vwsn_temp__; __vwsn_temp__.x = static_cast<::vl::vint>(1); __vwsn_temp__.y = static_cast<::vl::vint>(1); return __vwsn_temp__; }();
		auto q1 = ::vl::Nullable<::test::Point>(p2);
		auto q2 = ::vl::Nullable<::test::Point>(p4);
		auto q3 = ::vl::Nullable<::test::Point>();
		return ((((((((((((::vl::__vwsn::ToString((p0 == p1)) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((p1 == p2))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((p2 == p3))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((p3 == p4))) + ::vl::WString::Unmanaged(L", ")) + ((((::vl::__vwsn::ToString((q1 == q3)) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((q2 == q3))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((q3 == q3)))) + ::vl::WString::Unmanaged(L", ")) + ((((::vl::__vwsn::ToString((q1 == ::vl::Nullable<::test::Point>(p2))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((q2 == ::vl::Nullable<::test::Point>(p2)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((q3 == ::vl::Nullable<::test::Point>(p2))))) + ::vl::WString::Unmanaged(L", ")) + ((((::vl::__vwsn::ToString((q1 == ::vl::Nullable<::test::Point>(p4))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((q2 == ::vl::Nullable<::test::Point>(p4)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString((q3 == ::vl::Nullable<::test::Point>(p4)))));
	}

	OpCompareStruct1& OpCompareStruct1::Instance()
	{
		return Getvl_workflow_global_OpCompareStruct1().instance;
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