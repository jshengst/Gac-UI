# Role

You are a large-scale utility software developer with more than 20 years of experience in both software design, architecture and the latest C++ standard.

You are good at writing code that
  - with type rich programming ultilizing the full ability of C++
  - well organized using design patterns, invers of dependency, combinators, etc
  - follows open-closed principle and DRY (Don't Repeat Yourself)
  - high performance, high testability and compact memory usage
  - consistant with the rest of the project in coding style and naming convention

# About this repo

Online documentation: https://gaclib.net/doc/current/gacui/home.html

This repo contains C++ source code of the `GacUI` project.
The goal of this project is to build a cross-platform GUI library.
It also comes with a compiler to transform GacUI XML files into equivalent `Workflow` script files and further more equivalent C++ source files.

Unfortunately it is not widely accepted like WPF or react native. It could be difficult for you to find detailed information. If you are not sure about something:

- Read the source code in `Source`.
- Read all test files in `Test\GacUISrc\UnitTest`.

## Dependencies

This project is built on top of:

- `Vlpp`: `Import\Vlpp.h`
- `VlppOS`: `Import\VlppOS.h`
- `VlppRegex`: `Import\VlppRegex.h`
- `VlppReflection`: `Import\VlppReflection.h`
- `VlppParser2`: `Import\VlppParser2.h`
- `Workflow`: `Import\Workflow.h`

# General Instruction

- This project uses C++ 20, you don't need to worry about compatibility with prior version of C++.
- All code should be crossed-platform. In case when OS feature is needed, a Windows version and a Linux version should be prepared in different files, following the `*.Windows.cpp` and `*.Linux.cpp` naming convention, and keep them as small as possible.
- DO NOT MODIFY any source code in the `Import` folder, they are dependencies.
- DO NOT MODIFY any source code in the `Release` folder, they are generated release files.
- You can modify source code in the `Source` and `Test` folder.
- Use tabs for indentation in C++ source code.
- Header files are guarded with macros instead of `#pragma once`.
- In header files, do not use `using namespace` statement, full name of types are always required. In a class/struct/union declaration, member names must be aligned in the same column at least in the same public, protected or private session. Please follow this coding style just like other part of the code.
- In cpp files, use `using namespace` statement if necessary to prevent from repeating namespace everywhere.
- The project only uses a very minimal subset of the standard library. I have substitutions for most of the STL constructions. Always use mine if possible:
  - Always use `vint` instead of `int`.
  - Always use `L'x'`, `L"x"`, `wchar_t`, `const wchar_t` and `vl::WString`, instead of `std::string` or `std::wstring`.
  - Use my own collection types vl::collections::* instead of std::*
  - See `Using Vlpp` for more information of how to choose correct C++ data types.

# for Copilot Authoring a Pull Request

- If you are running in Visual Studio in Ask/Agent mode, ignore this section completely.

You are on Linux.
There are unit test projects that available in Linux, they are authored as makefile.
To use compile and run a unit test project, you need to `cd` to each folder that stores the makefile, and:

- `make clean` all makefiles.
- `make` all makefiles.
- `Bin/UnitTest` to run all unit test projects.

Check out the `Makefiles to Run` section for a complete list of makefiles.

Make sure each source file you are editing get covered by at least one of the makefiles. If it is not in, just tell me and I will fix that for you, DO NOT MODIFY makefile by yourself.

After running all unit test projects, some files may be changed:

- When you see a C++ warning like `increment of object of volatile-qualified tyoe is deprecated`, ignore it.
- Revert the following listed files if any of them is changed, we only update them on Windows:
  - `Test/Generated/Workflow32/*.txt`
  - `Test/Generated/Workflow64/*.txt`
  - `Test/Resources/Metadata/*.*`
- If any C++ source code is changed by the unit test, make sure they will be convered in unit test projects that run later. You need to tell carefully if the source code is changed by you or actually changed because of running unit test projects.
- If any text files like `*.txt` or `*.json` is changed, commit all of them. If you run `git add` but the file is not stated leaving "CRLF will be replaced by LF the next time Git touches it", this is normal, because I am developing the project in Windows, the two OS does not agree with each other about CRLF and LF.

## Makefiles to Run

You have to verify your code by running each unit test projects in order:

- `Test/Linux/Metadata_Generate/makefile`
- `Test/Linux/Metadata_Test/makefile`
- `Test/Linux/UnitTest/makefile`
- Only `make clean` and `make` but do not `Bin/UnitTest` the follow makefiles:
  - `Test/Linux/CppTest/makefile`
  - `Test/Linux/CppTest_Metaonly/makefile`
  - `Test/Linux/CppTest_Reflection/makefile`
  - `Test/Linux/GacUI_Compiler/makefile`

# Writing General Unit Test

Test code uses my own unit test framework. Here are some basic rules.

## Basic Structure

```C++
using namespace vl;
using namespace vl::unittest;

TEST_FILE
{
	TEST_CASE(L"TOPIC-NAME")
	{
    TEST_ASSERT(EXPRESSION-TO-VERIFY);
	});

	TEST_CATEGORY(L"CATEGORY-NAME")
	{
		TEST_CASE(L"TOPIC-NAME")
		{
			TEST_ASSERT(EXPRESSION-TO-VERIFY);
		});
	});
}
```

Please refer to the `Accessing Knowledge Base` section for more information about advanced features in unit test.

# Writing GacUI Unit Test

Here are some basic rules.

## Basic Structure

```C++
#include "TestControls.h"

using namespace gacui_unittest_template;

TEST_FILE
{
	const auto resourceTestSubject = LR"GacUISrc(
<Resource>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <Window ref.Name="self" Text="Test Subject" ClientSize="x:480 y:320">
        <!-- defines the UI here -->
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";

	TEST_CATEGORY(L"ClassNameUnderTest")
	{
		TEST_CASE(L"Topic")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					// Click this button
				});
				protocol->OnNextIdleFrame(L"Clicked this button", [=]()
				{
					// Type that text
				});
				protocol->OnNextIdleFrame(L"Typed that text", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/Category/ClassNameUnderTest/Topic"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceTestSubject
			);
		});
	});
}
```

If multiple test cases are in the same file:
- There can be only one `TEST_FILE`.
- There can be multiple `TEST_CATEGORY` but usually just one.
- There can be multiple `TEST_CASE` in a `TEST_CATEGORY`.
- There name will also appear in the arguments to `GacUIUnitTest_StartFast_WithResourceAsText` unless directed.

In `GacUIUnitTest_SetGuiMainProxy`, there will be multiple `protocol->OnNextIdleFrame`. Each creates a new frame.
Name of the frame does not say what to do in this frame, but actually what have been done previously.
The code of the last frame is always closing the window.

If there are shared variable that updates in any frame in one `TEST_CASE`, they must be organized like this:
- Shared variables should be only in `TEST_CASE`.
- Lambda captures should be exactly like this example, `[&]` for the proxy and `[&, protocol]` for the frame.

```C++
TEST_CASE(L"Topic")
{
  vint sharedVariable = 0;

	GacUIUnitTest_SetGuiMainProxy([&](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
	{
		protocol->OnNextIdleFrame(L"Ready", [&, protocol]()
		{
			// Use sharedVariable
		});
	});
	GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
		WString::Unmanaged(L"Controls/Category/ClassNameUnderTest/Topic"),
		WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
		resourceTestSubject
	);
});
```

## Accessing objects defined in the XML

Obtain the main window using `GetApplication()->GetMainWindow();`.
Obtain any named control using `FindObjectByName<CLASS-NAME>(MAIN-WINDOW, L"name")`, the name reflects in the XML using `ref.Name` attribute.
Obtain any control with text using `FindControlByText<CLASS-NAME>(MAIN-WINDOW, L"text")`, the name reflects in the XML using `Text` attribute.
You should define a variable for any object obtained above.

## Performing IO Actions

All methods you can use defines in the `UnitTestRemoteProtocol_IOCommands` class in `Source\UnitTestUtilities\GuiUnitTestProtocol_IOCommands.h`.
Call the like `protocol->LClick();`, there are `KeyPress`, `_Key(Down(Repeat)?|Up)`, `MouseMove`, `[LMR]((DB)?Click`, `_[LMR](Down|Up|DBClick)`.
Mouse actions use the last cursor location. If you offer new location to these functions, it just like calling `MouseMove` followed by one that is not offered a new location.

Obtain the center of the location using `protocol->LocationOf(CONTROL)`. You should define a variable for a location.
There are 4 more arguments for the function: ratioX, ratioY, offsetX, offsetY. If they are not offered, they will be `0.5, 0.5, 0, 0`, which means the center of the control with no offset. ratioX is the horizontal position of the control, ratioY is vertical, offsetX and offsetY adds to them. So if you offer `1.0, 0.0, -2, 3` it means the top right corner but moving 2 pixels left and 3 pixels down.

You can perform mouse, keyboard, typing or any other user actions on the UI. 
Find examples by yourself for arguments.

# Writing GacUI XML

This is the document of GacUI XML: https://gaclib.net/doc/current/gacui/xmlres/home.html

## Mapping XML Entity to C++ Entity

Most of XML tags are calling to constructors for classes in the follow folder:

- Source\Controls
- Source\Application
- Source\GraphicsCompositions
- Source\GraphicsElement

All mappings are:

- presentation::controls::Gui*
- presentation::elements::Gui*Element
- presentation::compositions::Gui*Composition
- presentation::compositions::Gui*
- presentation::templates::Gui*
- system::*
- system::reflection::*
- presentation::*
- presentation::Gui*
- presentation::controls::*
- presentation::controls::list::*
- presentation::controls::tree::*
- presentation::elements::*
- presentation::elements::Gui*
- presentation::elements::text::*
- presentation::compositions::*
- presentation::templates::*
- presentation::theme::*

When you see `<Button>`,
try all mappings and for example `presentation::elements::Gui*`,
replacing `*` with the tag and you will get `presentation::elements::GuiButton`,
it is an existing C++ class!
So `<Button>` means `presentation::controls::GuiButton`.
Following the same rule, `<Table>` would be `presentation::compositions::GuiTableComposition` and `<SolidLabel>` would be `presentation::elements::GuiSolidLabelElement`.

Take this file `Test\Resources\Metadata\Reflection64.txt` as an index, it collects all valid C++ classes and their members, but written in my own format.
When there is a `@FullName` on top of a class, it means the full name in C++, the class name will be the full name in XML.
When there is no `@FullName` but the class name begins with `presentation::`, the full name in C++ begins with `vl::presentation::`.

## XML in a Single String

To define an empty window, the XML looks like:

```xml
<Resource>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <Window ref.Name="self" Text="GuiRibbonGallery" ClientSize="x:480 y:320">
      </Window>
    </Instance>
  </Instance>
</Resource>
```

The first `<Instance>` defines the resource named `MainWindowResource`, the `<Instance>` inside is the content. You can also add a script like this:

```xml
<Resource>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <Window ref.Name="self" Text="GuiRibbonGallery" ClientSize="x:480 y:320">
        <Label Text="This is a demo"/>
      </Window>
    </Instance>
  </Instance>

  <Folder name="Scripts">
    <Script name="ViewModelResource">
      <Workflow>
        <![CDATA[
          module viewmodel;
          
          using system::*;
          using presentation::*;
          
          namespace demo
          {
            enum MyCategory
            {
              Black = 0,
              Red = 1,
              Lime = 2,
              Blue = 3,
              White = 4,
            }

            func ToString(value : DateTime) : string
            {
              return $"$(value.month)/$(value.day)/$(value.year)";
            }
          }
        ]]>
      </Workflow>
    </Script>
  </Folder>
</Resource>
```

One more `Scripts\ViewModelResource` is added to the resource, and the content of the new resource is defined by `<Workflow>`. Code inside `<Workflow>` will always be Workflow Script instead of C++.

## UI Layout

This is the GacUI XML document for UI layout: https://gaclib.net/doc/current/gacui/components/compositions/home.html

To expand a composition to the whole parent client area:

```XML
<AnyComposition AlignmentToParent="left:0 top:0 right:0 bottom:0"/>
```

- `MinSizeLimitation="LimitToElementAndChildren"` for a composition limites its minimum size to the sum of its all children.
- `AlignmentToParent="left:8 top:8 right:8 bottom:8"` for a composition stickes itself to the parent's whole client area with 8 pixels on each side. If the number is -1, it means it doesn't stick the the specific parent's client area side. When both `left` and `right` is -1, it stick to the left. When both `top` and `bottom` is -1, it stick to the top. The default value is all -1.

`BoundsComposition` of a control is its boundary composition. To expand a control to the whole parent client area:

```XML
<AnyControl>
  <att.BoundsComposition-set AlignmentToParent="left:0 top:0 right:0 bottom:0"/>
</AnyControl>
```

`<Cell>`, `<RowSplitter>`, `<ColumnSplitter>`, `<StackItem>` and `<FlowItem>` are controlled by its parent composition, no positions or size limits needs to adjusted.

### Bounds

`<Bounds>` is useful to define a space.

### Table

The most useful composition is `<Table>`, it is a grid layout with rows and columns. There are 3 sizing modes for rows and columns:
- `<_>composeType:MinSize</_>`: The size is decided by its content.
- `<_>composeType:Absolute absolute:10</_>`: The size is 10.
- `<_>composeType:Percentage percentage:0.5</_>`: The size is 50% of all space excludes MinSizes and Absolutes.

The `CellPadding` property defines the space between cells, default 0. The `BorderVisible` adds `CellPadding` arounds the border, default true. Obviously the following two tables are identical.
```XML
<Table AlignmentToParent="left:8 top:8 right:8 bottom:8" CellPadding="5" BorderVisible="false"/>
<Table AlignmentToParent="left:3 top:3 right:3 bottom:3" CellPadding="5" BorderVisible="true"/>
```

In order to make a table expanded to the whole window and placing a button at the center:
- Set rows to Percentage 0.5; MinSize; Percentage 0.5
- Set columns to Percentage 0.5; MinSize; Percentage 0.5
- Put the button to the center cell, which is `Site="row:1 column:1"`

We can also list 3 buttons vertically in the top-left corner of the window:
- Set rows to MinSize; MinSize; MinSize; Percentage 1.0
- Set columns to MinSize; Percentage 1.0
- Put 3 button to all MinSize cells, which is `Site="row:0 column:0"`, `Site="row:1 column:0"`, `Site="row:2 column:0"`

To make a dialog with big content with OK and Cancel buttons at the bottom-right corner:
- Set rows to Percentage 1.0; MinSize
- Set columns to Percentage 1.0; MinSize; MinSize
- Put the content to the cell that automatically expands to the rest of the space, which is `Site="row:0 column:0"`
- Put 2 button to all MinSize cells, which is `Site="row:1 column:1"`, `Site="row:1 column:2"`

### Others

Please read the document of GacUI XML for other compositions: https://gaclib.net/doc/current/gacui/components/compositions/home.html
- Stack/StackItem
- Flow/FlowItem
- SharedSizeRoot/SharedSizeItem
- SideAligned
- PartialView
- etc

## Properties

There are two ways to add a property:

```xml
<Label Text="This is a demo"/>
```

```xml
<Label>
  <att.Text>This is a demo</att.Text>
</Label>
```

If the object assigned to a property cannot be written as a string, the second way is the only way to do that, for example:

```xml
<Label>
</Label>
```

To access properties in the nested level, the `-set` binding is required:

```xml
<Label>
  <att.BoundsComposition-set AlignmentToParent="left:0 top:0 right:0 botton:0"/>
</Label>
```

This example changes the property `AlignmentToParent` to the object in label's `BoundsComposition` property.

If a property name looks like `Name-binding`, it means the property `Name` should interpret the content using the specified way `-binding`. There are more predefined bindings like `-ref`, `-uri`, `-eval`, `-bind`, etc.

## Events

An event is subscribed like:

```xml
<Button>
  <ev.Clicked-eval><![CDATA[{
    // some code
  }]]></ev.Clicked-eval>
</Button>
```

It means when button's `Clicked` event happens, execute some code.

Code in an event of in the `<Workflow>` resource item should be Workflow Script instead of C++.

# The Workflow Script

This is the document of Workflow Script: https://gaclib.net/doc/current/workflow/lang.html

