/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Workflow::Runtime

Interfaces:
**********************************************************************/

#ifndef VCZH_WORKFLOW_RUNTIME_WFRUNTIMEINSTRUCTION
#define VCZH_WORKFLOW_RUNTIME_WFRUNTIMEINSTRUCTION

#include <VlppReflection.h>

namespace vl
{
	namespace workflow
	{
		namespace runtime
		{

/***********************************************************************
Instruction
***********************************************************************/

			enum class WfInsCode
			{
				// Instruction			// param				: <Stack-Pattern> -> <Stack-Pattern> in the order of <bottom ---- top>
				Nop,					//						: () -> ()															;
				LoadValue,				// value				: () -> Value														;
				LoadFunction,			// function				: () -> Value														; push the function index
				LoadException,			// 						: () -> Value														;
				LoadLocalVar,			// variable				: () -> Value														;
				LoadCapturedVar,		// variable				: () -> Value														;
				LoadGlobalVar,			// variable				: () -> Value														;
				LoadMethodInfo,			// IMethodInfo*			: () -> IMethodInfo*												;
				LoadMethodClosure,		// IMethodInfo*			: Value-this -> <function>											;
				LoadClosureContext,		//						: () -> <closure-context>											; load the current closure context
				StoreLocalVar,			// variable				: Value -> ()														;
				StoreCapturedVar,		// variable				: Value -> ()														;
				StoreGlobalVar,			// variable				: Value -> ()														;
				Duplicate,				// count				: () -> Value														; copy stack[stack.Count()-1-count]
				Pop,					//						: Value -> ()														;
				Return,					//						: Value -> Value													; (exit function)
				NewArray,				// count				: Value-count, ..., Value-1 -> <array>								; {1 2 3} -> <3 2 1>
				NewList,				// count				: Value-count, ..., Value-1 -> <array>								; {1 2 3} -> <3 2 1>
				NewObservableList,		// count				: Value-count, ..., Value-1 -> <observable-list>					; {1 2 3} -> <3 2 1>
				NewDictionary,			// count				: Value-count*2, ..., Value-1 -> <map>								; {1:2 3:4} -> <3 4 1 2>
				CreateClosureContext,	// count				: Value-1, ..., Value-count -> <closure-context>					;
				CreateClosure,			//						: <closure-context>, Value-function-index -> <closure>				;
				CreateInterface,		// IMethodInfo*, count	: <closure-context>, Value-count, ..., Value-1 -> <map>				; {"Get":a "Set":b} -> new TInterface(InterfaceProxy^)
				CreateRange,			// I1248/U1248			: Value-begin, Value-end -> <enumerable>							;
				CreateStruct,			// flag, typeDescriptor	: () -> Value														;
				DeleteRawPtr,			//						: Value -> ()														;
				ConvertToType,			// flag, typeDescriptor	: Value -> Value													;
				TryConvertToType,		// flag, typeDescriptor	: Value -> Value													;
				TestType,				// flag, typeDescriptor	: Value -> <bool>													;
				GetType,				//						: Value -> <ITypeDescriptor*>										;
				Jump,					// label				: () -> ()															;
				JumpIf,					// label				: <bool> -> ()														;
				Invoke,					// function, count		: Value-1, ..., Value-n -> Value									;
				InvokeWithContext,		// function, count		: Value-1, ..., Value-n -> Value									;
				GetProperty,			// IPropertyInfo*		: Value-this -> Value												;
				SetProperty,			// IPropertyInfo*		: Value, Value-this -> ()											;
				UpdateProperty,			// IPropertyInfo*		: Value-this, Value -> Value-this									;
				InvokeProxy,			// count				: Value-1, ..., Value-n, Value-this -> Value						;
				InvokeMethod,			// IMethodInfo*, count	: Value-1, ..., Value-n, Value-this -> Value						;
				InvokeEvent,			// IEventInfo*, count	: Value-1, ..., Value-n, Value-this -> <null>						;
				InvokeBaseCtor,			// IMethodInfo*, count	: Value-1, ..., Value-n, Value-this -> <null>						;
				AttachEvent,			// IEventInfo*			: Value-this, <function> -> <Listener>								;
				DetachEvent,			// IEventInfo*			: Value-this, <Listener> -> bool									;
				InstallTry,				// label				: () -> ()															;
				UninstallTry,			// count				: () -> ()															;
				RaiseException,			// 						: Value -> ()														; (trap)
				TestElementInSet,		//						: Value-element, Value-set -> bool									;
				CompareLiteral,			// I48/U48/F48/S		: Value, Value -> <int>												;
				CompareReference,		// 						: Value, Value -> <bool>											;
				CompareValue,			// 						: Value, Value -> <bool>											;
				OpNot,					// B/I1248/U1248		: Value -> Value													;
				OpPositive,				// I1248/U1248			: Value -> Value													;
				OpNegative,				// I1248				: Value -> Value													;
				OpConcat,				// 						: <string>, <string> -> <string>									;
				OpExp,					// I48/U48/F48			: Value, Value -> Value												;
				OpAdd,					// I48/U48/F48			: Value, Value -> Value												;
				OpSub,					// I48/U48/F48			: Value, Value -> Value												;
				OpMul,					// I48/U48/F48			: Value, Value -> Value												;
				OpDiv,					// I48/U48/F48			: Value, Value -> Value												;
				OpMod,					// I48/U48				: Value, Value -> Value												;
				OpShl,					// I48/U48				: Value, Value -> Value												;
				OpShr,					// I48/U48				: Value, Value -> Value												;
				OpXor,					// B/I1248/U1248		: <bool>, <bool> -> <bool>											;
				OpAnd,					// B/I1248/U1248		: <bool>, <bool> -> <bool>											;
				OpOr,					// B/I1248/U1248		: <bool>, <bool> -> <bool>											;
				OpLT,					// 						: <int> -> <bool>													;
				OpGT,					// 						: <int> -> <bool>													;
				OpLE,					// 						: <int> -> <bool>													;
				OpGE,					// 						: <int> -> <bool>													;
				OpEQ,					// 						: <int> -> <bool>													;
				OpNE,					// 						: <int> -> <bool>													;
			};

#define INSTRUCTION_CASES(APPLY, APPLY_VALUE, APPLY_FUNCTION, APPLY_FUNCTION_COUNT, APPLY_VARIABLE, APPLY_COUNT, APPLY_FLAG_TYPEDESCRIPTOR, APPLY_PROPERTY, APPLY_METHOD, APPLY_METHOD_COUNT, APPLY_EVENT, APPLY_EVENT_COUNT, APPLY_LABEL, APPLY_TYPE)\
			APPLY(Nop)\
			APPLY_VALUE(LoadValue)\
			APPLY_FUNCTION(LoadFunction)\
			APPLY(LoadException)\
			APPLY_VARIABLE(LoadLocalVar)\
			APPLY_VARIABLE(LoadCapturedVar)\
			APPLY_VARIABLE(LoadGlobalVar)\
			APPLY_METHOD(LoadMethodInfo)\
			APPLY_METHOD(LoadMethodClosure)\
			APPLY(LoadClosureContext)\
			APPLY_VARIABLE(StoreLocalVar)\
			APPLY_VARIABLE(StoreCapturedVar)\
			APPLY_VARIABLE(StoreGlobalVar)\
			APPLY_COUNT(Duplicate)\
			APPLY(Pop)\
			APPLY(Return)\
			APPLY_COUNT(NewArray)\
			APPLY_COUNT(NewList)\
			APPLY_COUNT(NewObservableList)\
			APPLY_COUNT(NewDictionary)\
			APPLY_COUNT(CreateClosureContext)\
			APPLY(CreateClosure)\
			APPLY_METHOD_COUNT(CreateInterface)\
			APPLY_TYPE(CreateRange)\
			APPLY_FLAG_TYPEDESCRIPTOR(CreateStruct)\
			APPLY(DeleteRawPtr)\
			APPLY_FLAG_TYPEDESCRIPTOR(ConvertToType)\
			APPLY_FLAG_TYPEDESCRIPTOR(TryConvertToType)\
			APPLY_FLAG_TYPEDESCRIPTOR(TestType)\
			APPLY(GetType)\
			APPLY_LABEL(Jump)\
			APPLY_LABEL(JumpIf)\
			APPLY_FUNCTION_COUNT(Invoke)\
			APPLY_FUNCTION_COUNT(InvokeWithContext)\
			APPLY_PROPERTY(GetProperty)\
			APPLY_PROPERTY(SetProperty)\
			APPLY_PROPERTY(UpdateProperty)\
			APPLY_COUNT(InvokeProxy)\
			APPLY_METHOD_COUNT(InvokeMethod)\
			APPLY_EVENT_COUNT(InvokeEvent)\
			APPLY_METHOD_COUNT(InvokeBaseCtor)\
			APPLY_EVENT(AttachEvent)\
			APPLY_EVENT(DetachEvent)\
			APPLY_LABEL(InstallTry)\
			APPLY_COUNT(UninstallTry)\
			APPLY(RaiseException)\
			APPLY(TestElementInSet)\
			APPLY_TYPE(CompareLiteral)\
			APPLY(CompareReference)\
			APPLY(CompareValue)\
			APPLY_TYPE(OpNot)\
			APPLY_TYPE(OpPositive)\
			APPLY_TYPE(OpNegative)\
			APPLY(OpConcat)\
			APPLY_TYPE(OpExp)\
			APPLY_TYPE(OpAdd)\
			APPLY_TYPE(OpSub)\
			APPLY_TYPE(OpMul)\
			APPLY_TYPE(OpDiv)\
			APPLY_TYPE(OpMod)\
			APPLY_TYPE(OpShl)\
			APPLY_TYPE(OpShr)\
			APPLY_TYPE(OpXor)\
			APPLY_TYPE(OpAnd)\
			APPLY_TYPE(OpOr)\
			APPLY(OpLT)\
			APPLY(OpGT)\
			APPLY(OpLE)\
			APPLY(OpGE)\
			APPLY(OpEQ)\
			APPLY(OpNE)\

			enum class WfInsType
			{
				Bool,
				I1,
				I2,
				I4,
				I8,
				U1,
				U2,
				U4,
				U8,
				F4,
				F8,
				String,
				Unknown,
			};

			struct WfRuntimeValue
			{
				// U8 with ITypeDescriptor* -> enum
				// Unknown with ITypeDescriptor* -> type
				// Unknown -> Null
				WfInsType											type = WfInsType::Unknown;
				reflection::description::ITypeDescriptor*			typeDescriptor = nullptr;
				WString												stringValue;
				union
				{
					bool											boolValue;
					vint8_t											i1Value;
					vint16_t										i2Value;
					vint32_t										i4Value;
					vint64_t										i8Value;
					vuint8_t										u1Value;
					vuint16_t										u2Value;
					vuint32_t										u4Value;
					vuint64_t										u8Value = 0;
					float											f4Value;
					double											f8Value;
				};

				WfRuntimeValue() {}
				WfRuntimeValue(bool value) : type(WfInsType::Bool), boolValue(value) {}
				WfRuntimeValue(vint8_t value) : type(WfInsType::I1), i1Value(value) {}
				WfRuntimeValue(vint16_t value) : type(WfInsType::I2), i2Value(value) {}
				WfRuntimeValue(vint32_t value) : type(WfInsType::I4), i4Value(value) {}
				WfRuntimeValue(vint64_t value) : type(WfInsType::I8), i8Value(value) {}
				WfRuntimeValue(vuint8_t value) : type(WfInsType::U1), u1Value(value) {}
				WfRuntimeValue(vuint16_t value) : type(WfInsType::U2), u2Value(value) {}
				WfRuntimeValue(vuint32_t value) : type(WfInsType::U4), u4Value(value) {}
				WfRuntimeValue(vuint64_t value) : type(WfInsType::U8), u8Value(value) {}
				WfRuntimeValue(float value) : type(WfInsType::F4), f4Value(value) {}
				WfRuntimeValue(double value) : type(WfInsType::F8), f8Value(value) {}
				WfRuntimeValue(WString value) : type(WfInsType::String), stringValue(value) {}
				WfRuntimeValue(vuint64_t value, reflection::description::ITypeDescriptor* enumType)
					: type(WfInsType::U8), typeDescriptor(enumType), u8Value(value) {}
				WfRuntimeValue(reflection::description::ITypeDescriptor* td)
					: type(WfInsType::Unknown), typeDescriptor(td) {}
			};

			struct WfInstruction
			{
				WfInsCode											code = WfInsCode::Nop;
				WfRuntimeValue										valueParameter;
				vint												countParameter = 0;
				union
				{
					struct
					{
						reflection::description::Value::ValueType		flagParameter;
						reflection::description::ITypeDescriptor*		typeDescriptorParameter;
					};
					WfInsType											typeParameter;
					vint												indexParameter;
					reflection::description::IPropertyInfo*				propertyParameter;
					reflection::description::IMethodInfo*				methodParameter;
					reflection::description::IEventInfo*				eventParameter;
				};

				WfInstruction();

				#define CTOR(NAME)						static WfInstruction NAME();
				#define CTOR_VALUE(NAME)				static WfInstruction NAME(const WfRuntimeValue& value);
				#define CTOR_FUNCTION(NAME)				static WfInstruction NAME(vint function);
				#define CTOR_FUNCTION_COUNT(NAME)		static WfInstruction NAME(vint function, vint count);
				#define CTOR_VARIABLE(NAME)				static WfInstruction NAME(vint variable);
				#define CTOR_COUNT(NAME)				static WfInstruction NAME(vint count);
				#define CTOR_FLAG_TYPEDESCRIPTOR(NAME)	static WfInstruction NAME(reflection::description::Value::ValueType flag, reflection::description::ITypeDescriptor* typeDescriptor);
				#define CTOR_PROPERTY(NAME)				static WfInstruction NAME(reflection::description::IPropertyInfo* propertyInfo);
				#define CTOR_METHOD(NAME)				static WfInstruction NAME(reflection::description::IMethodInfo* methodInfo);
				#define CTOR_METHOD_COUNT(NAME)			static WfInstruction NAME(reflection::description::IMethodInfo* methodInfo, vint count);
				#define CTOR_EVENT(NAME)				static WfInstruction NAME(reflection::description::IEventInfo* eventInfo);
				#define CTOR_EVENT_COUNT(NAME)			static WfInstruction NAME(reflection::description::IEventInfo* eventInfo, vint count);
				#define CTOR_LABEL(NAME)				static WfInstruction NAME(vint label);
				#define CTOR_TYPE(NAME)					static WfInstruction NAME(WfInsType type);

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
			};
		}
	}
}

#endif
