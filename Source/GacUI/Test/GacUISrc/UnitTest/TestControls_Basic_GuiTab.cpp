#include "TestControls.h"

TEST_FILE
{
	const auto resourceTabWithAlt = LR"GacUISrc(
<Resource>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <Window ref.Name="self" Text="GuiTab" ClientSize="x:320 y:240">
        <Tab ref.Name="tab">
          <att.BoundsComposition-set AlignmentToParent="left:0 top:5 right:0 bottom:0"/>
          <att.Pages>
            <TabPage ref.Name="tabPageOptions" Text="Options" Alt="O">
              <Stack Direction="Vertical" Padding="5" MinSizeLimitation="LimitToElementAndChildren" AlignmentToParent="left:5 top:5 right:5 bottom:5">
                <StackItem>
                  <CheckBox Alt="A" Text="Option 1"/>
                </StackItem>
                <StackItem>
                  <CheckBox Alt="B" Text="Option 2"/>
                </StackItem>
              </Stack>
            </TabPage>
            <TabPage ref.Name="tabPageLabel" Text="Label" Alt="L">
              <Label Text="This is a label!">
                <att.BoundsComposition-set AlignmentToParent="left:5 top:5 right:-1 bottom:-1"/>
              </Label>
            </TabPage>
            <TabPage ref.Name="tabPageNested" Text="Nested">
              <Tab ref.Name="nestedTab">
                <att.BoundsComposition-set AlignmentToParent="left:5 top:5 right:5 bottom:5"/>
                <att.Pages>
                  <TabPage Text="First"/>
                  <TabPage Text="Second"/>
                  <TabPage Text="Third"/>
                </att.Pages>
              </Tab>
            </TabPage>
          </att.Pages>
        </Tab>
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";

	const auto resourceOneTab = LR"GacUISrc(
<Resource>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <Window ref.Name="self" Text="GuiTab" ClientSize="x:320 y:240">
        <Tab ref.Name="tab">
          <att.BoundsComposition-set AlignmentToParent="left:0 top:5 right:0 bottom:0"/>
          <att.Pages>
            <TabPage Text="First" Alt="O"/>
          </att.Pages>
        </Tab>
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";

	TEST_CATEGORY(L"GuiTab")
	{
		TEST_CASE(L"Navigation")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPageOptions = FindObjectByName<GuiTabPage>(window, L"tabPageOptions");
					auto tabPageLabel = FindObjectByName<GuiTabPage>(window, L"tabPageLabel");
					auto tabPageNested = FindObjectByName<GuiTabPage>(window, L"tabPageNested");
					TEST_ASSERT(tab->GetPages().Count() == 3);
					TEST_ASSERT(tab->GetPages()[0] == tabPageOptions);
					TEST_ASSERT(tab->GetPages()[1] == tabPageLabel);
					TEST_ASSERT(tab->GetPages()[2] == tabPageNested);
					TEST_ASSERT(tabPageOptions->GetOwnerTab() == tab);
					TEST_ASSERT(tabPageLabel->GetOwnerTab() == tab);
					TEST_ASSERT(tab->GetSelectedPage() == tabPageOptions);
					tab->SetSelectedPage(tabPageLabel);
					TEST_ASSERT(tab->GetSelectedPage() == tabPageLabel);
				});
				protocol->OnNextIdleFrame(L"Show Label", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPageOptions = FindObjectByName<GuiTabPage>(window, L"tabPageOptions");
					auto tabPageLabel = FindObjectByName<GuiTabPage>(window, L"tabPageLabel");
					TEST_ASSERT(tab->GetSelectedPage() == tabPageLabel);
					tab->SetSelectedPage(tabPageOptions);
					TEST_ASSERT(tab->GetSelectedPage() == tabPageOptions);
				});
				protocol->OnNextIdleFrame(L"Show Options", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->LClick({ { {140}, {50} } });
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPage = FindObjectByName<GuiTabPage>(window, L"tabPageLabel");
					TEST_ASSERT(tab->GetSelectedPage() == tabPage);
				});
				protocol->OnNextIdleFrame(L"Click Label", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->LClick({ { {50}, {50} } });
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPage = FindObjectByName<GuiTabPage>(window, L"tabPageOptions");
					TEST_ASSERT(tab->GetSelectedPage() == tabPage);
				});
				protocol->OnNextIdleFrame(L"Click Options", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/Basic/GuiTab/Navigation"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceTabWithAlt
				);
		});

		TEST_CASE(L"NavigationAlt")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->KeyPress(VKEY::KEY_MENU);
				});
				protocol->OnNextIdleFrame(L"[ALT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->KeyPress(VKEY::KEY_L);
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPage = FindObjectByName<GuiTabPage>(window, L"tabPageLabel");
					TEST_ASSERT(tab->GetSelectedPage() == tabPage);
				});
				protocol->OnNextIdleFrame(L"[L]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->KeyPress(VKEY::KEY_MENU);
				});
				protocol->OnNextIdleFrame(L"[ALT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->KeyPress(VKEY::KEY_O);
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPage = FindObjectByName<GuiTabPage>(window, L"tabPageOptions");
					TEST_ASSERT(tab->GetSelectedPage() == tabPage);
				});
				protocol->OnNextIdleFrame(L"[O]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto button = FindControlByText<GuiSelectableButton>(window, L"Option 1");
					TEST_ASSERT(button->GetSelected() == false);
					protocol->KeyPress(VKEY::KEY_MENU);
					protocol->KeyPress(VKEY::KEY_A);
					TEST_ASSERT(button->GetSelected() == true);
				});
				protocol->OnNextIdleFrame(L"[ALT][A]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto button = FindControlByText<GuiSelectableButton>(window, L"Option 2");
					TEST_ASSERT(button->GetSelected() == false);
					protocol->KeyPress(VKEY::KEY_MENU);
					protocol->KeyPress(VKEY::KEY_B);
					TEST_ASSERT(button->GetSelected() == true);
				});
				protocol->OnNextIdleFrame(L"[ALT][B]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->KeyPress(VKEY::KEY_MENU);
					protocol->KeyPress(VKEY::KEY_L);
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPage = FindObjectByName<GuiTabPage>(window, L"tabPageLabel");
					TEST_ASSERT(tab->GetSelectedPage() == tabPage);
				});
				protocol->OnNextIdleFrame(L"[ALT][L]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					protocol->KeyPress(VKEY::KEY_MENU);
					protocol->KeyPress(VKEY::KEY_O);
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					auto tabPage = FindObjectByName<GuiTabPage>(window, L"tabPageOptions");
					TEST_ASSERT(tab->GetSelectedPage() == tabPage);
				});
				protocol->OnNextIdleFrame(L"[ALT][O]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/Basic/GuiTab/NavigationAlt"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceTabWithAlt
				);
		});

		TEST_CASE(L"NavigationTab")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					protocol->KeyPress(VKEY::KEY_TAB);
					TEST_ASSERT(tab->GetSelectedPage() == tab->GetPages()[0]);
				});
				protocol->OnNextIdleFrame(L"[TAB]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					protocol->KeyPress(VKEY::KEY_RIGHT);
					TEST_ASSERT(tab->GetSelectedPage() == tab->GetPages()[1]);
				});
				protocol->OnNextIdleFrame(L"[RIGHT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					protocol->KeyPress(VKEY::KEY_RIGHT);
					TEST_ASSERT(tab->GetSelectedPage() == tab->GetPages()[2]);
				});
				protocol->OnNextIdleFrame(L"[RIGHT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto nestedTab = FindObjectByName<GuiTab>(window, L"nestedTab");
					protocol->KeyPress(VKEY::KEY_TAB);
					TEST_ASSERT(nestedTab->GetSelectedPage() == nestedTab->GetPages()[0]);
				});
				protocol->OnNextIdleFrame(L"[TAB]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto nestedTab = FindObjectByName<GuiTab>(window, L"nestedTab");
					protocol->KeyPress(VKEY::KEY_RIGHT);
					TEST_ASSERT(nestedTab->GetSelectedPage() == nestedTab->GetPages()[1]);
				});
				protocol->OnNextIdleFrame(L"[RIGHT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto nestedTab = FindObjectByName<GuiTab>(window, L"nestedTab");
					protocol->KeyPress(VKEY::KEY_RIGHT);
					TEST_ASSERT(nestedTab->GetSelectedPage() == nestedTab->GetPages()[2]);
				});
				protocol->OnNextIdleFrame(L"[RIGHT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					protocol->KeyPress(VKEY::KEY_TAB, false, true, false);
					TEST_ASSERT(tab->GetSelectedPage() == tab->GetPages()[2]);
				});
				protocol->OnNextIdleFrame(L"[SHIFT+TAB]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					protocol->KeyPress(VKEY::KEY_LEFT);
					TEST_ASSERT(tab->GetSelectedPage() == tab->GetPages()[1]);
				});
				protocol->OnNextIdleFrame(L"[LEFT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					protocol->KeyPress(VKEY::KEY_LEFT);
					TEST_ASSERT(tab->GetSelectedPage() == tab->GetPages()[0]);
				});
				protocol->OnNextIdleFrame(L"[LEFT]", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/Basic/GuiTab/NavigationTab"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceTabWithAlt
				);
		});

		TEST_CASE(L"ModifyPages")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				auto checkPages = [](vint index, auto ...names)
				{
					constexpr vint tabCount = sizeof...(names);
					const wchar_t* tabNames[] = { names... };
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");

					TEST_ASSERT(tab->GetPages().Count() == tabCount);
					TEST_ASSERT(tab->GetSelectedPage() == tab->GetPages()[index]);
					for(vint i=0; i < sizeof...(names); i++)
					{
						TEST_ASSERT(tab->GetPages()[i]->GetText() == WString::Unmanaged(tabNames[i]));
					}
				};

				auto createPage = [](const WString& name)
				{
					auto tabPage = new GuiTabPage(theme::ThemeName::CustomControl);
					tabPage->SetText(name);

					auto label = new GuiLabel(theme::ThemeName::Label);
					label->SetText(name);
					tabPage->AddChild(label);
					return tabPage;
				};

				protocol->OnNextIdleFrame(L"Ready", [&checkPages, &createPage]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");
					checkPages(0, L"First");

					tab->GetPages().Add(createPage(L"Second"));
					checkPages(0, L"First", L"Second");
				});
				protocol->OnNextIdleFrame(L"Add Second", [&checkPages]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");

					tab->SetSelectedPage(tab->GetPages()[1]);
					checkPages(1, L"First", L"Second");
				});
				protocol->OnNextIdleFrame(L"Select Second", [&checkPages, &createPage]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");

					tab->GetPages().Insert(1, createPage(L"First(2)"));
					tab->GetPages().Add(createPage(L"Third"));
					checkPages(2, L"First", L"First(2)", L"Second", L"Third");
				});
				protocol->OnNextIdleFrame(L"Add First(2) and Third", [&checkPages]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");

					auto tabPage = tab->GetSelectedPage();
					tab->GetPages().Remove(tabPage);
					SafeDeleteControl(tabPage);
					checkPages(2, L"First", L"First(2)", L"Third");
				});
				protocol->OnNextIdleFrame(L"Delete Second", [&checkPages]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto tab = FindObjectByName<GuiTab>(window, L"tab");

					auto tabPage = tab->GetSelectedPage();
					tab->GetPages().Remove(tabPage);
					SafeDeleteControl(tabPage);
					checkPages(1, L"First", L"First(2)");
				});
				protocol->OnNextIdleFrame(L"Delete Third", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/Basic/GuiTab/ModifyPages"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceOneTab
				);
		});
	});
}