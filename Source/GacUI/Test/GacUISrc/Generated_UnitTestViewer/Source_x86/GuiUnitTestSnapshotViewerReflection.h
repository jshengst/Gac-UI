﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: GacUI UnitTestSnapshotViewer

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_GUIUNITTESTSNAPSHOTVIEWERREFLECTION
#define VCZH_WORKFLOW_COMPILER_GENERATED_GUIUNITTESTSNAPSHOTVIEWERREFLECTION

#include "GuiUnitTestSnapshotViewerIncludes.h"
#ifndef VCZH_DEBUG_NO_REFLECTION
#include "../../../Reflection/TypeDescriptors/GuiReflectionPlugin.h"
#endif

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			DECL_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotFileNode)
			DECL_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotFrame)
			DECL_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotViewerStringsStrings)
			DECL_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotViewerViewModel)
			DECL_TYPE_INFO(::gaclib_controls::UnitTestSnapshotFileNodeType)
			DECL_TYPE_INFO(::gaclib_controls::UnitTestSnapshotViewerStrings)
			DECL_TYPE_INFO(::gaclib_controls::UnitTestSnapshotViewerWindow)
			DECL_TYPE_INFO(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gaclib_controls::IUnitTestSnapshotFileNode)
				::vl::collections::LazyList<::vl::Ptr<::gaclib_controls::IUnitTestSnapshotFileNode>> GetChildren() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetChildren);
				}
				::vl::collections::LazyList<::vl::Ptr<::gaclib_controls::IUnitTestSnapshotFrame>> GetFrames() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetFrames);
				}
				::vl::WString GetName() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetName);
				}
				::gaclib_controls::UnitTestSnapshotFileNodeType GetNodeType() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetNodeType);
				}
				void Refresh() override
				{
					INVOKE_INTERFACE_PROXY_NOPARAMS(Refresh);
				}
			END_INTERFACE_PROXY(::gaclib_controls::IUnitTestSnapshotFileNode)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gaclib_controls::IUnitTestSnapshotFrame)
				::vl::WString GetCommandsAsJsonText() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetCommandsAsJsonText);
				}
				::vl::WString GetDomAsJsonText() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetDomAsJsonText);
				}
				::vl::WString GetElementsAsJsonText() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetElementsAsJsonText);
				}
				::vl::WString GetName() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetName);
				}
			END_INTERFACE_PROXY(::gaclib_controls::IUnitTestSnapshotFrame)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gaclib_controls::IUnitTestSnapshotViewerStringsStrings)
				::vl::WString WindowTitle() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(WindowTitle);
				}
			END_INTERFACE_PROXY(::gaclib_controls::IUnitTestSnapshotViewerStringsStrings)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::gaclib_controls::IUnitTestSnapshotViewerViewModel)
				::vl::Ptr<::gaclib_controls::IUnitTestSnapshotFileNode> GetRootNode() override
				{
					INVOKEGET_INTERFACE_PROXY_NOPARAMS(GetRootNode);
				}
			END_INTERFACE_PROXY(::gaclib_controls::IUnitTestSnapshotViewerViewModel)
#endif
#endif

			extern bool LoadGuiUnitTestSnapshotViewerTypes();
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#endif