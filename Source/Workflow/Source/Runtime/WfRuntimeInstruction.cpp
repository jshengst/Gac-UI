#include "WfRuntimeInstruction.h"

namespace vl
{
	namespace workflow
	{
		namespace runtime
		{
			using namespace reflection::description;

/***********************************************************************
WfInstruction
***********************************************************************/

			WfInstruction::WfInstruction()
				:flagParameter(Value::Null)
				, typeDescriptorParameter(0)
			{

			}

#define CTOR(NAME)\
			WfInstruction WfInstruction::NAME()\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				return ins; \
			}\

#define CTOR_VALUE(NAME)\
			WfInstruction WfInstruction::NAME(const WfRuntimeValue& value)\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.valueParameter = value; \
				return ins; \
			}\

#define CTOR_FUNCTION(NAME)\
			WfInstruction WfInstruction::NAME(vint function)\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.indexParameter = function; \
				return ins; \
			}\

#define CTOR_FUNCTION_COUNT(NAME)\
			WfInstruction WfInstruction::NAME(vint function, vint count)\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.indexParameter = function; \
				ins.countParameter = count; \
				return ins; \
			}\

#define CTOR_VARIABLE(NAME)\
			WfInstruction WfInstruction::NAME(vint variable)\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.indexParameter = variable; \
				return ins; \
			}\

#define CTOR_COUNT(NAME)\
			WfInstruction WfInstruction::NAME(vint count)\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.countParameter = count; \
				return ins; \
			}\

#define CTOR_FLAG_TYPEDESCRIPTOR(NAME)\
			WfInstruction WfInstruction::NAME(reflection::description::Value::ValueType flag, reflection::description::ITypeDescriptor* typeDescriptor)\
			{\
				CHECK_ERROR(typeDescriptor != nullptr, L"vl::workflow::runtime::WfInstruction::" L ## #NAME L"(Value::ValueType, ITypeDescriptor*)#Internal error, argument null.");\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.flagParameter = flag; \
				ins.typeDescriptorParameter = typeDescriptor; \
				return ins; \
			}\

#define CTOR_PROPERTY(NAME)\
			WfInstruction WfInstruction::NAME(reflection::description::IPropertyInfo* propertyInfo)\
			{\
				CHECK_ERROR(propertyInfo != nullptr, L"vl::workflow::runtime::WfInstruction::" L ## #NAME L"(propertyInfo*)#Internal error, argument null.");\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.propertyParameter = propertyInfo; \
				return ins; \
			}\

#define CTOR_METHOD(NAME)\
			WfInstruction WfInstruction::NAME(reflection::description::IMethodInfo* methodInfo)\
			{\
				CHECK_ERROR(methodInfo != nullptr, L"vl::workflow::runtime::WfInstruction::" L ## #NAME L"(methodInfo*)#Internal error, argument null.");\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.methodParameter = methodInfo; \
				return ins; \
			}\

#define CTOR_METHOD_COUNT(NAME)\
			WfInstruction WfInstruction::NAME(reflection::description::IMethodInfo* methodInfo, vint count)\
			{\
				CHECK_ERROR(methodInfo != nullptr, L"vl::workflow::runtime::WfInstruction::" L ## #NAME L"(methodInfo*, vint)#Internal error, argument null.");\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.methodParameter = methodInfo; \
				ins.countParameter = count; \
				return ins; \
			}\

#define CTOR_EVENT(NAME)\
			WfInstruction WfInstruction::NAME(reflection::description::IEventInfo* eventInfo)\
			{\
				CHECK_ERROR(eventInfo != nullptr, L"vl::workflow::runtime::WfInstruction::" L ## #NAME L"(IEventInfo*)#Internal error, argument null.");\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.eventParameter = eventInfo; \
				return ins; \
			}\

#define CTOR_EVENT_COUNT(NAME)\
			WfInstruction WfInstruction::NAME(reflection::description::IEventInfo* eventInfo, vint count)\
			{\
				CHECK_ERROR(eventInfo != nullptr, L"vl::workflow::runtime::WfInstruction::" L ## #NAME L"(IEventInfo*, vint)#Internal error, argument null.");\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.eventParameter = eventInfo; \
				ins.countParameter = count; \
				return ins; \
			}\

#define CTOR_LABEL(NAME)\
			WfInstruction WfInstruction::NAME(vint label)\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.indexParameter = label; \
				return ins; \
			}\

#define CTOR_TYPE(NAME)\
			WfInstruction WfInstruction::NAME(WfInsType type)\
			{\
				WfInstruction ins; \
				ins.code = WfInsCode::NAME; \
				ins.typeParameter = type; \
				return ins; \
			}\

			INSTRUCTION_CASES(
				CTOR,
				CTOR_VALUE,
				CTOR_FUNCTION,
				CTOR_FUNCTION_COUNT,
				CTOR_VARIABLE,
				CTOR_COUNT,
				CTOR_FLAG_TYPEDESCRIPTOR,
				CTOR_PROPERTY,
				CTOR_METHOD,
				CTOR_METHOD_COUNT,
				CTOR_EVENT,
				CTOR_EVENT_COUNT,
				CTOR_LABEL,
				CTOR_TYPE)

#undef CTOR
#undef CTOR_VALUE
#undef CTOR_FUNCTION
#undef CTOR_FUNCTION_COUNT
#undef CTOR_VARIABLE
#undef CTOR_COUNT
#undef CTOR_FLAG_TYPEDESCRIPTOR
#undef CTOR_PROPERTY
#undef CTOR_METHOD
#undef CTOR_METHOD_COUNT
#undef CTOR_EVENT
#undef CTOR_EVENT_COUNT
#undef CTOR_LABEL
#undef CTOR_TYPE
		}
	}
}
