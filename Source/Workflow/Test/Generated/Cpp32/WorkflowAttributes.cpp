/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/WorkflowAttributes.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "WorkflowAttributesIncludes.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, WorkflowAttributesReflection.h) */
#include "WorkflowAttributesReflection.h"
#endif
/* CodePack:EndIgnore() */

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::WorkflowAttributes::
#define GLOBAL_NAME ::vl_workflow_global::WorkflowAttributes::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::WorkflowAttributes::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_WorkflowAttributes)
	vl_workflow_global::WorkflowAttributes instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_WorkflowAttributes)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString WorkflowAttributes::Print(::vl::Ptr<::calculator::Expression> expr)
	{
		if (auto ne = ::vl::__vwsn::SharedPtrCast<::calculator::NumberExpression>(expr.Obj()))
		{
			return ::vl::__vwsn::ToString(::vl::__vwsn::This(ne.Obj())->GetValue());
		}
		else if (auto be = ::vl::__vwsn::SharedPtrCast<::calculator::BinaryExpression>(expr.Obj()))
		{
			auto op = ::vl::WString::Unmanaged(L"");
			{
				auto __vwsn_switch_0 = ::vl::__vwsn::This(be.Obj())->GetOperator();
				if ((__vwsn_switch_0 == ::calculator::BinaryExpression::BinaryOperator::Add))
				{
					(op = ::vl::WString::Unmanaged(L"+"));
				}
				else if ((__vwsn_switch_0 == ::calculator::BinaryExpression::BinaryOperator::Sub))
				{
					(op = ::vl::WString::Unmanaged(L"-"));
				}
				else if ((__vwsn_switch_0 == ::calculator::BinaryExpression::BinaryOperator::Mul))
				{
					(op = ::vl::WString::Unmanaged(L"*"));
				}
				else if ((__vwsn_switch_0 == ::calculator::BinaryExpression::BinaryOperator::Div))
				{
					(op = ::vl::WString::Unmanaged(L"/"));
				}
			}
			return ((((((::vl::WString::Unmanaged(L"(") + GLOBAL_NAME Print(::vl::__vwsn::This(be.Obj())->GetLeft())) + ::vl::WString::Unmanaged(L" ")) + op) + ::vl::WString::Unmanaged(L" ")) + GLOBAL_NAME Print(::vl::__vwsn::This(be.Obj())->GetRight())) + ::vl::WString::Unmanaged(L")"));
		}
		else
		{
			throw ::vl::Exception(::vl::WString::Unmanaged(L"Unrecognized expression type."));
		}
	}

	::vl::vint32_t WorkflowAttributes::Evaluate(::vl::Ptr<::calculator::Expression> expr)
	{
		if (auto ne = ::vl::__vwsn::SharedPtrCast<::calculator::NumberExpression>(expr.Obj()))
		{
			return ::vl::__vwsn::This(ne.Obj())->GetValue();
		}
		else if (auto be = ::vl::__vwsn::SharedPtrCast<::calculator::BinaryExpression>(expr.Obj()))
		{
			auto left = GLOBAL_NAME Evaluate(::vl::__vwsn::This(be.Obj())->GetLeft());
			auto right = GLOBAL_NAME Evaluate(::vl::__vwsn::This(be.Obj())->GetRight());
			{
				auto __vwsn_switch_1 = ::vl::__vwsn::This(be.Obj())->GetOperator();
				if ((__vwsn_switch_1 == ::calculator::BinaryExpression::BinaryOperator::Add))
				{
					return (left + right);
				}
				else if ((__vwsn_switch_1 == ::calculator::BinaryExpression::BinaryOperator::Sub))
				{
					return (left - right);
				}
				else if ((__vwsn_switch_1 == ::calculator::BinaryExpression::BinaryOperator::Mul))
				{
					return (left * right);
				}
				else if ((__vwsn_switch_1 == ::calculator::BinaryExpression::BinaryOperator::Div))
				{
					return (left / right);
				}
			}
			throw ::vl::Exception(::vl::WString::Unmanaged(L"Unrecognized binary operator."));
		}
		else
		{
			throw ::vl::Exception(::vl::WString::Unmanaged(L"Unrecognized expression type."));
		}
	}

	::vl::WString WorkflowAttributes::main()
	{
		auto expr = ::vl::Ptr<::calculator::BinaryExpression>(new ::calculator::BinaryExpression(::vl::Ptr<::calculator::Expression>(::vl::Ptr<::calculator::BinaryExpression>(new ::calculator::BinaryExpression(::vl::Ptr<::calculator::Expression>(::vl::Ptr<::calculator::NumberExpression>(new ::calculator::NumberExpression(static_cast<::vl::vint32_t>(1)))), ::calculator::BinaryExpression::BinaryOperator::Add, ::vl::Ptr<::calculator::Expression>(::vl::Ptr<::calculator::NumberExpression>(new ::calculator::NumberExpression(static_cast<::vl::vint32_t>(2))))))), ::calculator::BinaryExpression::BinaryOperator::Mul, ::vl::Ptr<::calculator::Expression>(::vl::Ptr<::calculator::BinaryExpression>(new ::calculator::BinaryExpression(::vl::Ptr<::calculator::Expression>(::vl::Ptr<::calculator::NumberExpression>(new ::calculator::NumberExpression(static_cast<::vl::vint32_t>(3)))), ::calculator::BinaryExpression::BinaryOperator::Add, ::vl::Ptr<::calculator::Expression>(::vl::Ptr<::calculator::NumberExpression>(new ::calculator::NumberExpression(static_cast<::vl::vint32_t>(4)))))))));
		return (((::vl::WString::Unmanaged(L"") + ::vl::__vwsn::This(expr.Obj())->Print()) + ::vl::WString::Unmanaged(L" = ")) + ::vl::__vwsn::ToString(::vl::__vwsn::This(expr.Obj())->Evaluate()));
	}

	WorkflowAttributes& WorkflowAttributes::Instance()
	{
		return Getvl_workflow_global_WorkflowAttributes().instance;
	}
}

/***********************************************************************
Class (::calculator::BinaryExpression)
***********************************************************************/

namespace calculator
{
	::calculator::BinaryExpression::BinaryOperator BinaryExpression::GetOperator()
	{
		return this->__vwsn_prop_Operator;
	}
	void BinaryExpression::SetOperator(::calculator::BinaryExpression::BinaryOperator __vwsn_value_)
	{
		(this->__vwsn_prop_Operator = __vwsn_value_);
	}

	::vl::Ptr<::calculator::Expression> BinaryExpression::GetLeft()
	{
		return this->__vwsn_prop_Left;
	}
	void BinaryExpression::SetLeft(::vl::Ptr<::calculator::Expression> __vwsn_value_)
	{
		(this->__vwsn_prop_Left = __vwsn_value_);
	}

	::vl::Ptr<::calculator::Expression> BinaryExpression::GetRight()
	{
		return this->__vwsn_prop_Right;
	}
	void BinaryExpression::SetRight(::vl::Ptr<::calculator::Expression> __vwsn_value_)
	{
		(this->__vwsn_prop_Right = __vwsn_value_);
	}

	BinaryExpression::BinaryExpression(::vl::Ptr<::calculator::Expression> _left, ::calculator::BinaryExpression::BinaryOperator _op, ::vl::Ptr<::calculator::Expression> _right)
		: __vwsn_prop_Operator(::calculator::BinaryExpression::BinaryOperator::Add)
		, __vwsn_prop_Left(::vl::Ptr<::calculator::Expression>())
		, __vwsn_prop_Right(::vl::Ptr<::calculator::Expression>())
	{
		this->SetLeft(_left);
		this->SetOperator(_op);
		this->SetRight(_right);
	}

/***********************************************************************
Class (::calculator::NumberExpression)
***********************************************************************/

	::vl::vint32_t NumberExpression::GetValue()
	{
		return this->__vwsn_prop_Value;
	}
	void NumberExpression::SetValue(::vl::vint32_t __vwsn_value_)
	{
		(this->__vwsn_prop_Value = __vwsn_value_);
	}

	NumberExpression::NumberExpression(::vl::vint32_t _value)
		: __vwsn_prop_Value(static_cast<::vl::vint32_t>(0))
	{
		this->SetValue(_value);
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