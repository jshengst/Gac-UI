/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/NewEmptyInterface.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_NEWEMPTYINTERFACE
#define VCZH_WORKFLOW_COMPILER_GENERATED_NEWEMPTYINTERFACE

#include "../Source/CppTypes.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

namespace vl_workflow_global
{
	class __vwsnc1_NewEmptyInterface_main__IMyEmptyInterface;
}

class IMyEmptyInterface;

class IMyEmptyInterface : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<IMyEmptyInterface>
{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<IMyEmptyInterface>;
#endif
public:
	static ::vl::vint Get50();
};

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class NewEmptyInterface
	{
	public:

		::vl::WString main();

		static NewEmptyInterface& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	class __vwsnc1_NewEmptyInterface_main__IMyEmptyInterface : public ::vl::Object, public virtual ::IMyEmptyInterface
	{
	public:
		__vwsnc1_NewEmptyInterface_main__IMyEmptyInterface();

	};
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#endif