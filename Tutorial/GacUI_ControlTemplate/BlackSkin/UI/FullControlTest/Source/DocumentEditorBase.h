﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_DOCUMENTEDITORBASE
#define VCZH_WORKFLOW_COMPILER_GENERATED_DOCUMENTEDITORBASE

#include "DemoPartialClasses.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

namespace demo
{
	class DocumentEditorBase : public ::vl::presentation::controls::GuiCustomControl, public ::demo::DocumentEditorBaseConstructor, public ::vl::reflection::Description<DocumentEditorBase>
	{
		friend class ::demo::DocumentEditorBaseConstructor;
		friend class ::vl_workflow_global::__vwsnc68_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc69_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc70_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc71_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc72_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc73_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc74_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc75_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc76_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc77_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize____vl_reflection_description_ICoroutine;
		friend class ::vl_workflow_global::__vwsnc78_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc79_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc80_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc81_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc82_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc83_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc84_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc85_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc86_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc87_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc88_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc89_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc90_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc91_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc92_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc93_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc94_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc95_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc96_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc97_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__vl_reflection_description_IValueSubscription;
		friend struct ::vl_workflow_global::__vwsnf142_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf143_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf144_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf145_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf146_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf147_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf148_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf149_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf150_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf151_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf152_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf153_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf154_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf155_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf156_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf157_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf158_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf159_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf160_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf161_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf162_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf163_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf164_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf165_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize__;
		friend struct ::vl_workflow_global::__vwsnf166_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf167_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf168_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf169_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf170_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf171_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf172_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf173_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf174_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf175_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf176_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf177_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf178_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf179_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf180_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf181_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf182_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf183_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf184_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf185_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf186_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf187_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf188_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf189_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf190_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf191_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf192_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf193_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf194_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf195_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf196_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf197_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf198_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf199_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf200_Demo_demo_DocumentEditorBaseConstructor___vwsn_demo_DocumentEditorBase_Initialize_;
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<DocumentEditorBase>;
#endif
	protected:
		::vl::presentation::controls::GuiToolstripCommand* __vwsn_prop_EditModeCommand;
		::vl::presentation::controls::GuiToolstripCommand* GetEditModeCommand();
		void SetEditModeCommand(::vl::presentation::controls::GuiToolstripCommand* __vwsn_value_);
		::vl::Event<void()> EditModeCommandChanged;
	private:
		void SetEditMode(::vl::presentation::controls::GuiDocumentCommonInterface::EditMode editMode);
	protected:
		::vl::presentation::controls::GuiToolstripCommand* SelectAlignmentCommand();
	private:
		void SetAlignment(::vl::Nullable<::vl::presentation::Alignment> alignment);
		bool __vwsn_prop_HasEditableSelection;
		bool GetHasEditableSelection();
		void SetHasEditableSelection(bool __vwsn_value_);
		::vl::Event<void()> HasEditableSelectionChanged;
		bool __vwsn_prop_HasEditableSelectionInSingleParagraph;
		bool GetHasEditableSelectionInSingleParagraph();
		void SetHasEditableSelectionInSingleParagraph(bool __vwsn_value_);
		::vl::Event<void()> HasEditableSelectionInSingleParagraphChanged;
		bool HasEditableCursor();
		bool HasEditableHyperlink(bool forEdit);
	protected:
		::vl::presentation::compositions::GuiGraphicsComposition* GetMenuContainer();
		::vl::presentation::compositions::GuiGraphicsComposition* GetToolstripContainer();
	public:
		void LoadAsPrivateFormat(const ::vl::WString& fileName);
		void SaveAsPrivateFormat(const ::vl::WString& fileName);
		void SaveAsRTF(const ::vl::WString& fileName);
		void SaveAsHTML(const ::vl::WString& fileName);
	private:
		void SaveDocument();
	public:
		bool CancelWindowClose();
		DocumentEditorBase();
		void __vwsn_instance_ctor_();
		~DocumentEditorBase();

	/* USER_CONTENT_BEGIN(custom members of ::demo::DocumentEditorBase) */
	/* USER_CONTENT_END() */
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