/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/CoRawCoroutine4.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "CoRawCoroutine4.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::CoRawCoroutine4::
#define GLOBAL_NAME ::vl_workflow_global::CoRawCoroutine4::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::CoRawCoroutine4::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_CoRawCoroutine4)
	vl_workflow_global::CoRawCoroutine4 instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Unmanaged(L"");
	FINALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Empty;
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_CoRawCoroutine4)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString CoRawCoroutine4::main()
	{
		auto coroutine = ::vl::Ptr<::vl::reflection::description::ICoroutine>(new ::vl_workflow_global::__vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine());
		{
			auto i = static_cast<::vl::vint32_t>(0);
			while ((::vl::__vwsn::This(coroutine.Obj())->GetStatus() != ::vl::reflection::description::CoroutineStatus::Stopped))
			{
				::vl::__vwsn::This(coroutine.Obj())->Resume(false, ::vl::Ptr<::vl::reflection::description::CoroutineResult>());
				(GLOBAL_NAME s = ((((::vl::WString::Unmanaged(L"") + GLOBAL_NAME s) + ::vl::WString::Unmanaged(L"[-")) + ::vl::__vwsn::ToString(i)) + ::vl::WString::Unmanaged(L"]")));
				(i = (i + static_cast<::vl::vint32_t>(1)));
			}
			(GLOBAL_NAME s = ((((::vl::WString::Unmanaged(L"") + GLOBAL_NAME s) + ::vl::WString::Unmanaged(L"[")) + ::vl::__vwsn::This(::vl::__vwsn::This(coroutine.Obj())->GetFailure().Obj())->GetMessage()) + ::vl::WString::Unmanaged(L"]")));
		}
		return GLOBAL_NAME s;
	}

	CoRawCoroutine4& CoRawCoroutine4::Instance()
	{
		return Getvl_workflow_global_CoRawCoroutine4().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine::__vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine()
	{
		this->__vwsn_co0_for_begin_i = static_cast<::vl::vint32_t>(0);
		this->__vwsn_co1_for_end_i = static_cast<::vl::vint32_t>(0);
		this->__vwsn_co2_i = static_cast<::vl::vint32_t>(0);
		this->__vwsn_co3_o = ::vl::Ptr<::vl::reflection::description::IValueList>();
		this->__vwsn_co_state_ = static_cast<::vl::vint32_t>(0);
		this->__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint32_t>(1));
		this->__vwsn_prop_Failure = ::vl::Ptr<::vl::reflection::description::IValueException>();
		this->__vwsn_prop_Status = ::vl::reflection::description::CoroutineStatus::Waiting;
	}

	::vl::Ptr<::vl::reflection::description::IValueException> __vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine::GetFailure()
	{
		return __vwsn_prop_Failure;
	}
	void __vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine::SetFailure(::vl::Ptr<::vl::reflection::description::IValueException> __vwsn_value_)
	{
		(__vwsn_prop_Failure = __vwsn_value_);
	}

	::vl::reflection::description::CoroutineStatus __vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine::GetStatus()
	{
		return __vwsn_prop_Status;
	}
	void __vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine::SetStatus(::vl::reflection::description::CoroutineStatus __vwsn_value_)
	{
		(__vwsn_prop_Status = __vwsn_value_);
	}

	void __vwsnc1_CoRawCoroutine4_main__vl_reflection_description_ICoroutine::Resume(bool __vwsn_raise_exception_, ::vl::Ptr<::vl::reflection::description::CoroutineResult> __vwsn_coroutine_output_)
	{
		if ((this->GetStatus() != ::vl::reflection::description::CoroutineStatus::Waiting))
		{
			throw ::vl::Exception(::vl::WString::Unmanaged(L"Resume should be called only when the coroutine is in the waiting status."));
		}
		this->SetStatus(::vl::reflection::description::CoroutineStatus::Executing);
		try
		{
			{
				if ((__vwsn_co_state_before_pause_ != (- static_cast<::vl::vint32_t>(1))))
				{
					if ((! static_cast<bool>(__vwsn_coroutine_output_)))
					{
						(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint32_t>(1)));
					}
					else if ((! static_cast<bool>(::vl::__vwsn::This(__vwsn_coroutine_output_.Obj())->GetFailure())))
					{
						(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint32_t>(1)));
					}
					else
					{
						{
							(__vwsn_co_state_before_pause_ = (- static_cast<::vl::vint32_t>(1)));
							throw ::vl::Exception(::vl::__vwsn::This(::vl::__vwsn::This(__vwsn_coroutine_output_.Obj())->GetFailure().Obj())->GetMessage());
						}
					}
				}
				while (true)
				{
					if ((__vwsn_co_state_ == static_cast<::vl::vint32_t>(0)))
					{
						(__vwsn_co0_for_begin_i = static_cast<::vl::vint32_t>(0));
						(__vwsn_co1_for_end_i = (static_cast<::vl::vint32_t>(4) - static_cast<::vl::vint32_t>(1)));
						(__vwsn_co2_i = __vwsn_co0_for_begin_i);
						if ((__vwsn_co2_i <= __vwsn_co1_for_end_i))
						{
							(__vwsn_co_state_ = static_cast<::vl::vint32_t>(3));
							continue;
						}
						(__vwsn_co_state_ = static_cast<::vl::vint32_t>(1));
						continue;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint32_t>(1)))
					{
						this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
						return;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint32_t>(2)))
					{
						(__vwsn_co2_i = (__vwsn_co2_i + static_cast<::vl::vint32_t>(1)));
						if ((__vwsn_co2_i <= __vwsn_co1_for_end_i))
						{
							(__vwsn_co_state_ = static_cast<::vl::vint32_t>(3));
							continue;
						}
						(__vwsn_co_state_ = static_cast<::vl::vint32_t>(1));
						continue;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint32_t>(3)))
					{
						(__vwsn_co3_o = ((__vwsn_co2_i == static_cast<::vl::vint32_t>(2)) ? ::vl::Ptr<::vl::reflection::description::IValueList>() : (::vl::__vwsn::CreateList().Add(static_cast<::vl::vint32_t>(0))).list));
						if (static_cast<bool>(__vwsn_co3_o))
						{
							(GLOBAL_NAME s = ((((::vl::WString::Unmanaged(L"") + GLOBAL_NAME s) + ::vl::WString::Unmanaged(L"[+")) + ::vl::__vwsn::ToString(__vwsn_co2_i)) + ::vl::WString::Unmanaged(L"]")));
							(__vwsn_co_state_ = static_cast<::vl::vint32_t>(4));
							continue;
						}
						(__vwsn_co_state_ = static_cast<::vl::vint32_t>(5));
						continue;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint32_t>(4)))
					{
						this->SetStatus(::vl::reflection::description::CoroutineStatus::Waiting);
						(__vwsn_co_state_before_pause_ = __vwsn_co_state_);
						(__vwsn_co_state_ = static_cast<::vl::vint32_t>(2));
						return;
					}
					if ((__vwsn_co_state_ == static_cast<::vl::vint32_t>(5)))
					{
						{
							throw ::vl::Exception(::vl::WString::Unmanaged(L"*"));
						}
						(__vwsn_co_state_ = static_cast<::vl::vint32_t>(2));
						continue;
					}
				}
			}
		}
		catch(const ::vl::Exception& __vwsne_0)
		{
			auto __vwsn_co_ex_ = ::vl::reflection::description::IValueException::Create(__vwsne_0.Message());
			{
				this->SetFailure(__vwsn_co_ex_);
				this->SetStatus(::vl::reflection::description::CoroutineStatus::Stopped);
				if (__vwsn_raise_exception_)
				{
					throw;
				}
			}
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