﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe ResourceRibbon.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "EditorRibbonReflection.h"

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
			IMPL_CPP_TYPE_INFO(demo::DocumentEditorRibbon)
			IMPL_CPP_TYPE_INFO(demo::DocumentEditorRibbonConstructor)
			IMPL_CPP_TYPE_INFO(demo::MainWindow)
			IMPL_CPP_TYPE_INFO(demo::MainWindowConstructor)
			IMPL_CPP_TYPE_INFO(demo::StyleGroup)
			IMPL_CPP_TYPE_INFO(demo::StyleItem)
			IMPL_CPP_TYPE_INFO(demo::StyleItemTemplate)
			IMPL_CPP_TYPE_INFO(demo::StyleItemTemplateConstructor)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
#define _ ,
			BEGIN_CLASS_MEMBER(::demo::DocumentEditorRibbon)
				CLASS_MEMBER_BASE(::demo::DocumentEditorBase)
				CLASS_MEMBER_BASE(::demo::DocumentEditorRibbonConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::demo::DocumentEditorRibbon*(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_instance_ctor_, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GenerateStyleGroups, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetAlignCenterSelected, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetAlignLeftSelected, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetAlignRightSelected, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetStyleGroups, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SelectStyleName, { L"styleName" })
				CLASS_MEMBER_METHOD(SetAlignCenterSelected, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetAlignLeftSelected, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetAlignRightSelected, { L"__vwsn_value_" })
				CLASS_MEMBER_METHOD(SetStyleGroups, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(AlignCenterSelectedChanged)
				CLASS_MEMBER_EVENT(AlignLeftSelectedChanged)
				CLASS_MEMBER_EVENT(AlignRightSelectedChanged)
				CLASS_MEMBER_EVENT(StyleGroupsChanged)
				CLASS_MEMBER_FIELD(__vwsn_prop_AlignCenterSelected)
				CLASS_MEMBER_FIELD(__vwsn_prop_AlignLeftSelected)
				CLASS_MEMBER_FIELD(__vwsn_prop_AlignRightSelected)
				CLASS_MEMBER_FIELD(__vwsn_prop_StyleGroups)
				CLASS_MEMBER_PROPERTY_EVENT(AlignCenterSelected, GetAlignCenterSelected, SetAlignCenterSelected, AlignCenterSelectedChanged)
				CLASS_MEMBER_PROPERTY_EVENT(AlignLeftSelected, GetAlignLeftSelected, SetAlignLeftSelected, AlignLeftSelectedChanged)
				CLASS_MEMBER_PROPERTY_EVENT(AlignRightSelected, GetAlignRightSelected, SetAlignRightSelected, AlignRightSelectedChanged)
				CLASS_MEMBER_PROPERTY_EVENT(StyleGroups, GetStyleGroups, SetStyleGroups, StyleGroupsChanged)
			END_CLASS_MEMBER(::demo::DocumentEditorRibbon)

			BEGIN_CLASS_MEMBER(::demo::DocumentEditorRibbonConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::DocumentEditorRibbonConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_demo_DocumentEditorRibbon_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_15)
				CLASS_MEMBER_FIELD(__vwsn_precompile_16)
				CLASS_MEMBER_FIELD(__vwsn_precompile_17)
				CLASS_MEMBER_FIELD(__vwsn_precompile_18)
				CLASS_MEMBER_FIELD(__vwsn_precompile_19)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_20)
				CLASS_MEMBER_FIELD(__vwsn_precompile_21)
				CLASS_MEMBER_FIELD(__vwsn_precompile_22)
				CLASS_MEMBER_FIELD(__vwsn_precompile_23)
				CLASS_MEMBER_FIELD(__vwsn_precompile_24)
				CLASS_MEMBER_FIELD(__vwsn_precompile_25)
				CLASS_MEMBER_FIELD(__vwsn_precompile_26)
				CLASS_MEMBER_FIELD(__vwsn_precompile_27)
				CLASS_MEMBER_FIELD(__vwsn_precompile_28)
				CLASS_MEMBER_FIELD(__vwsn_precompile_29)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_30)
				CLASS_MEMBER_FIELD(__vwsn_precompile_31)
				CLASS_MEMBER_FIELD(__vwsn_precompile_32)
				CLASS_MEMBER_FIELD(__vwsn_precompile_33)
				CLASS_MEMBER_FIELD(__vwsn_precompile_34)
				CLASS_MEMBER_FIELD(__vwsn_precompile_35)
				CLASS_MEMBER_FIELD(__vwsn_precompile_36)
				CLASS_MEMBER_FIELD(__vwsn_precompile_37)
				CLASS_MEMBER_FIELD(__vwsn_precompile_38)
				CLASS_MEMBER_FIELD(__vwsn_precompile_39)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_40)
				CLASS_MEMBER_FIELD(__vwsn_precompile_41)
				CLASS_MEMBER_FIELD(__vwsn_precompile_42)
				CLASS_MEMBER_FIELD(__vwsn_precompile_43)
				CLASS_MEMBER_FIELD(__vwsn_precompile_44)
				CLASS_MEMBER_FIELD(__vwsn_precompile_45)
				CLASS_MEMBER_FIELD(__vwsn_precompile_46)
				CLASS_MEMBER_FIELD(__vwsn_precompile_47)
				CLASS_MEMBER_FIELD(__vwsn_precompile_48)
				CLASS_MEMBER_FIELD(__vwsn_precompile_49)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_50)
				CLASS_MEMBER_FIELD(__vwsn_precompile_51)
				CLASS_MEMBER_FIELD(__vwsn_precompile_52)
				CLASS_MEMBER_FIELD(__vwsn_precompile_53)
				CLASS_MEMBER_FIELD(__vwsn_precompile_54)
				CLASS_MEMBER_FIELD(__vwsn_precompile_55)
				CLASS_MEMBER_FIELD(__vwsn_precompile_56)
				CLASS_MEMBER_FIELD(__vwsn_precompile_57)
				CLASS_MEMBER_FIELD(__vwsn_precompile_58)
				CLASS_MEMBER_FIELD(__vwsn_precompile_59)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_60)
				CLASS_MEMBER_FIELD(__vwsn_precompile_61)
				CLASS_MEMBER_FIELD(__vwsn_precompile_62)
				CLASS_MEMBER_FIELD(__vwsn_precompile_63)
				CLASS_MEMBER_FIELD(__vwsn_precompile_64)
				CLASS_MEMBER_FIELD(__vwsn_precompile_65)
				CLASS_MEMBER_FIELD(__vwsn_precompile_66)
				CLASS_MEMBER_FIELD(__vwsn_precompile_67)
				CLASS_MEMBER_FIELD(__vwsn_precompile_68)
				CLASS_MEMBER_FIELD(__vwsn_precompile_69)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_70)
				CLASS_MEMBER_FIELD(__vwsn_precompile_71)
				CLASS_MEMBER_FIELD(__vwsn_precompile_72)
				CLASS_MEMBER_FIELD(__vwsn_precompile_73)
				CLASS_MEMBER_FIELD(__vwsn_precompile_74)
				CLASS_MEMBER_FIELD(__vwsn_precompile_75)
				CLASS_MEMBER_FIELD(__vwsn_precompile_76)
				CLASS_MEMBER_FIELD(__vwsn_precompile_77)
				CLASS_MEMBER_FIELD(__vwsn_precompile_78)
				CLASS_MEMBER_FIELD(__vwsn_precompile_79)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_80)
				CLASS_MEMBER_FIELD(__vwsn_precompile_81)
				CLASS_MEMBER_FIELD(__vwsn_precompile_82)
				CLASS_MEMBER_FIELD(__vwsn_precompile_83)
				CLASS_MEMBER_FIELD(__vwsn_precompile_84)
				CLASS_MEMBER_FIELD(__vwsn_precompile_85)
				CLASS_MEMBER_FIELD(__vwsn_precompile_86)
				CLASS_MEMBER_FIELD(__vwsn_precompile_87)
				CLASS_MEMBER_FIELD(__vwsn_precompile_88)
				CLASS_MEMBER_FIELD(__vwsn_precompile_89)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(__vwsn_precompile_90)
				CLASS_MEMBER_FIELD(__vwsn_precompile_91)
				CLASS_MEMBER_FIELD(__vwsn_precompile_92)
				CLASS_MEMBER_FIELD(__vwsn_precompile_93)
				CLASS_MEMBER_FIELD(__vwsn_precompile_94)
				CLASS_MEMBER_FIELD(__vwsn_precompile_95)
				CLASS_MEMBER_FIELD(buttonHome)
				CLASS_MEMBER_FIELD(dialogMessage)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(styleGallery)
				CLASS_MEMBER_FIELD(toolstripHome)
			END_CLASS_MEMBER(::demo::DocumentEditorRibbonConstructor)

			BEGIN_CLASS_MEMBER(::demo::MainWindow)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiWindow)
				CLASS_MEMBER_BASE(::demo::MainWindowConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::demo::MainWindow*(), NO_PARAMETER)
			END_CLASS_MEMBER(::demo::MainWindow)

			BEGIN_CLASS_MEMBER(::demo::MainWindowConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::MainWindowConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_demo_MainWindow_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(editor)
			END_CLASS_MEMBER(::demo::MainWindowConstructor)

			BEGIN_CLASS_MEMBER(::demo::StyleGroup)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::StyleGroup>(), NO_PARAMETER)
				CLASS_MEMBER_FIELD(Items)
				CLASS_MEMBER_FIELD(Name)
			END_CLASS_MEMBER(::demo::StyleGroup)

			BEGIN_CLASS_MEMBER(::demo::StyleItem)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::StyleItem>(const ::vl::WString&, ::vl::Nullable<::vl::presentation::DocumentFontSize>, ::vl::Nullable<::vl::presentation::Color>, ::vl::Nullable<bool>, ::vl::Nullable<bool>, ::vl::Nullable<bool>, ::vl::Nullable<bool>), { L"name" _ L"size" _ L"color" _ L"bold" _ L"italic" _ L"underline" _ L"strikeline" })
				CLASS_MEMBER_FIELD(Name)
				CLASS_MEMBER_FIELD(Style)
			END_CLASS_MEMBER(::demo::StyleItem)

			BEGIN_CLASS_MEMBER(::demo::StyleItemTemplate)
				CLASS_MEMBER_BASE(::vl::presentation::templates::GuiTextListItemTemplate)
				CLASS_MEMBER_BASE(::demo::StyleItemTemplateConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::demo::StyleItemTemplate*(::vl::Ptr<::demo::StyleItem>), { L"__vwsn_ctor_parameter_ViewModel" })
				CLASS_MEMBER_METHOD(__vwsn_instance_ctor_, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetViewModel, NO_PARAMETER)
				CLASS_MEMBER_FIELD(__vwsn_parameter_ViewModel)
				CLASS_MEMBER_PROPERTY_READONLY(ViewModel, GetViewModel)
			END_CLASS_MEMBER(::demo::StyleItemTemplate)

			BEGIN_CLASS_MEMBER(::demo::StyleItemTemplateConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::demo::StyleItemTemplateConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_demo_StyleItemTemplate_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(ViewModel)
				CLASS_MEMBER_FIELD(containerControl)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(styleLabel)
			END_CLASS_MEMBER(::demo::StyleItemTemplateConstructor)

#undef _
			class EditorRibbonTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::demo::DocumentEditorRibbon)
					ADD_TYPE_INFO(::demo::DocumentEditorRibbonConstructor)
					ADD_TYPE_INFO(::demo::MainWindow)
					ADD_TYPE_INFO(::demo::MainWindowConstructor)
					ADD_TYPE_INFO(::demo::StyleGroup)
					ADD_TYPE_INFO(::demo::StyleItem)
					ADD_TYPE_INFO(::demo::StyleItemTemplate)
					ADD_TYPE_INFO(::demo::StyleItemTemplateConstructor)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif
#endif

			bool LoadEditorRibbonTypes()
			{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(Ptr(new EditorRibbonTypeLoader));
				}
#endif
				return false;
			}
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