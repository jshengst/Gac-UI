/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Control Styles::Windows8 Styles

Clases:
***********************************************************************/

#ifndef VCZH_PRESENTATION_CONTROLS_WIN8STYLES_GUIWin8LISTSTYLES
#define VCZH_PRESENTATION_CONTROLS_WIN8STYLES_GUIWin8LISTSTYLES

#include "GuiWin8StylesCommon.h"
#include "GuiWin8ButtonStyles.h"
#include "GuiWin8ScrollableStyles.h"
#include "GuiWin8ControlStyles.h"
#include "GuiWin8MenuStyles.h"

namespace vl
{
	namespace presentation
	{
		namespace win8
		{

/***********************************************************************
List Control Buttons
***********************************************************************/
			
			/// <summary>Selectable item style (Windows 8). Generally for list box item background.</summary>
			class Win8SelectableItemStyle : public Win8ButtonStyleBase, public Description<Win8SelectableItemStyle>
			{
			protected:
				void										TransferInternal(controls::ButtonState value, bool enabled, bool selected)override;
			public:
				/// <summary>Create the style.</summary>
				Win8SelectableItemStyle();
				~Win8SelectableItemStyle();
			};

/***********************************************************************
ComboBox
***********************************************************************/
			
#pragma warning(push)
#pragma warning(disable:4250)
			/// <summary>Drop down combo box style (Windows 8).</summary>
			class Win8DropDownComboBoxStyle : public Win8ButtonStyle, public virtual controls::GuiComboBoxListControl::IStyleController, public Description<Win8DropDownComboBoxStyle>
			{
			protected:
				controls::IComboBoxCommandExecutor*				commandExecutor;
				compositions::GuiTableComposition*				table;
				compositions::GuiCellComposition*				textComposition;
				compositions::GuiCellComposition*				dropDownComposition;
				elements::GuiPolygonElement*					dropDownElement;
				WString											text;
				bool											textVisible;

				void											TransferInternal(controls::ButtonState value, bool enabled, bool selected)override;
				void											AfterApplyColors(const Win8ButtonColors& colors)override;
			public:
				/// <summary>Create the style.</summary>
				Win8DropDownComboBoxStyle();
				~Win8DropDownComboBoxStyle();
				
				compositions::GuiGraphicsComposition*						GetContainerComposition()override;
				
				controls::GuiMenu::IStyleController*						CreateSubMenuStyleController()override;
				void														SetSubMenuExisting(bool value)override;
				void														SetSubMenuOpening(bool value)override;
				controls::GuiButton*										GetSubMenuHost()override;
				void														SetImage(Ptr<GuiImageData> value)override;
				void														SetShortcutText(const WString& value)override;
				void														SetCommandExecutor(controls::IComboBoxCommandExecutor* value)override;
				void														OnItemSelected()override;
				void														SetText(const WString& value)override;
				void														SetTextVisible(bool value)override;
			};
#pragma warning(pop)

/***********************************************************************
List
***********************************************************************/

#pragma warning(push)
#pragma warning(disable:4250)
			
			/// <summary>Multiline text box style (Windows 7).</summary>
			class Win8TextListProvider : public Win8MultilineTextBoxProvider, public virtual controls::GuiVirtualTextList::IStyleProvider, public Description<Win8TextListProvider>
			{
			public:
				/// <summary>Create the style.</summary>
				Win8TextListProvider();
				~Win8TextListProvider();

				virtual Color												GetTextColor()override;
				controls::GuiSelectableButton::IStyleController*			CreateItemBackground()override;
				controls::GuiSelectableButton::IStyleController*			CreateCheckBulletStyle()override;
				controls::GuiSelectableButton::IStyleController*			CreateRadioBulletStyle()override;
			};

			/// <summary>List view style (Windows 8).</summary>
			class Win8ListViewProvider : public Win8MultilineTextBoxProvider, public virtual controls::GuiListView::IStyleProvider, public Description<Win8ListViewProvider>
			{
			public:
				/// <summary>Create the style.</summary>
				Win8ListViewProvider();
				~Win8ListViewProvider();

				controls::GuiSelectableButton::IStyleController*		CreateItemBackground()override;
				controls::GuiListViewColumnHeader::IStyleController*	CreateColumnStyle()override;
				Color													GetPrimaryTextColor()override;
				Color													GetSecondaryTextColor()override;
				Color													GetItemSeparatorColor()override;
			};
			
			/// <summary>Tree view style (Windows 8).</summary>
			class Win8TreeViewProvider : public Win8MultilineTextBoxProvider, public virtual controls::GuiTreeView::IStyleProvider, public Description<Win8TreeViewProvider>
			{
			public:
				/// <summary>Create the style.</summary>
				Win8TreeViewProvider();
				~Win8TreeViewProvider();

				controls::GuiSelectableButton::IStyleController*		CreateItemBackground()override;
				controls::GuiSelectableButton::IStyleController*		CreateItemExpandingDecorator()override;
				Color													GetTextColor()override;
			};
#pragma warning(pop)
		}
	}
}

#endif