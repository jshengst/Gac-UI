/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/TryFinally2.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "TryFinally2.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::TryFinally2::
#define GLOBAL_NAME ::vl_workflow_global::TryFinally2::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::TryFinally2::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_TryFinally2)
	vl_workflow_global::TryFinally2 instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.sum = static_cast<::vl::vint>(0);
	FINALIZE_GLOBAL_STORAGE_CLASS

END_GLOBAL_STORAGE_CLASS(vl_workflow_global_TryFinally2)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	void TryFinally2::test1()
	{
		{
			auto __vwsn_for_begin_x = static_cast<::vl::vint>(1);
			auto __vwsn_for_end_x = static_cast<::vl::vint>(5);
			auto x = __vwsn_for_begin_x;
			while ((x <= __vwsn_for_end_x))
			{
				{
					{
						{
							auto __vwsnb_0 = [&]()
							{
								(GLOBAL_NAME sum = (GLOBAL_NAME sum + static_cast<::vl::vint>(1)));
							}
							;
							::vl::__vwsn::RunOnExit<::std::remove_cvref_t<decltype(__vwsnb_0)>> __vwsnb_0_dtor(&__vwsnb_0);
							try
							{
								{
									goto __vwsnl_0_CONTINUE;
								}
							}
							catch(const ::vl::Exception&)
							{
							}
						}
					}
					__vwsnl_0_CONTINUE:;
				}
				(x = (x + static_cast<::vl::vint>(1)));
			}
		}
	}

	void TryFinally2::test2()
	{
		{
			{
				auto __vwsn_for_begin_x = static_cast<::vl::vint>(1);
				auto __vwsn_for_end_x = static_cast<::vl::vint>(5);
				auto x = __vwsn_for_begin_x;
				while ((x <= __vwsn_for_end_x))
				{
					{
						{
							auto __vwsnb_0 = [&]()
							{
								(GLOBAL_NAME sum = (GLOBAL_NAME sum + static_cast<::vl::vint>(10)));
							}
							;
							::vl::__vwsn::RunOnExit<::std::remove_cvref_t<decltype(__vwsnb_0)>> __vwsnb_0_dtor(&__vwsnb_0);
							try
							{
								{
									goto __vwsnl_0_BREAK;
								}
							}
							catch(const ::vl::Exception&)
							{
							}
						}
					}
					(x = (x + static_cast<::vl::vint>(1)));
				}
			}
		}
		__vwsnl_0_BREAK:;
	}

	void TryFinally2::test3()
	{
		{
			{
				auto __vwsnb_0 = [&]()
				{
					(GLOBAL_NAME sum = (GLOBAL_NAME sum + static_cast<::vl::vint>(100)));
				}
				;
				::vl::__vwsn::RunOnExit<::std::remove_cvref_t<decltype(__vwsnb_0)>> __vwsnb_0_dtor(&__vwsnb_0);
				try
				{
					{
						goto __vwsnl_0_RETURN;
					}
				}
				catch(const ::vl::Exception&)
				{
				}
			}
		}
		__vwsnl_0_RETURN:;
	}

	void TryFinally2::test4()
	{
		{
			{
				auto __vwsnb_0 = [&]()
				{
					(GLOBAL_NAME sum = (GLOBAL_NAME sum + static_cast<::vl::vint>(1000)));
				}
				;
				::vl::__vwsn::RunOnExit<::std::remove_cvref_t<decltype(__vwsnb_0)>> __vwsnb_0_dtor(&__vwsnb_0);
				try
				{
					{
						{
							auto __vwsnb_1 = [&]()
							{
								(GLOBAL_NAME sum = (GLOBAL_NAME sum + static_cast<::vl::vint>(1000)));
							}
							;
							::vl::__vwsn::RunOnExit<::std::remove_cvref_t<decltype(__vwsnb_1)>> __vwsnb_1_dtor(&__vwsnb_1);
							try
							{
								{
									{
										auto __vwsnb_2 = [&]()
										{
											(GLOBAL_NAME sum = (GLOBAL_NAME sum + static_cast<::vl::vint>(1000)));
										}
										;
										::vl::__vwsn::RunOnExit<::std::remove_cvref_t<decltype(__vwsnb_2)>> __vwsnb_2_dtor(&__vwsnb_2);
										try
										{
											{
												goto __vwsnl_0_RETURN;
											}
										}
										catch(const ::vl::Exception&)
										{
										}
									}
								}
							}
							catch(const ::vl::Exception&)
							{
							}
						}
					}
				}
				catch(const ::vl::Exception&)
				{
				}
			}
		}
		__vwsnl_0_RETURN:;
	}

	::vl::WString TryFinally2::main()
	{
		GLOBAL_NAME test1();
		GLOBAL_NAME test2();
		GLOBAL_NAME test3();
		GLOBAL_NAME test4();
		return ::vl::__vwsn::ToString(GLOBAL_NAME sum);
	}

	TryFinally2& TryFinally2::Instance()
	{
		return Getvl_workflow_global_TryFinally2().instance;
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