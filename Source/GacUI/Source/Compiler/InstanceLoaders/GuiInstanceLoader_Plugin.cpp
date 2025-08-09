/*
GuiInstanceLoader_Plugin.cpp
	GuiControl
		default: GuiControl*, GuiGraphicsComposition*
	GuiInstanceRootObject
		default: GuiComponent*
	GuiRawElement
GuiInstanceLoader_TemplateControl.h
	GuiControl
GuiInstanceLoader_Compositions.cpp
	GuiAxis
		ctor: AxisDirection
	GuiComposition
		default: GuiControl*, GuiGraphicsComposition*, Ptr<IGuiGraphicsElement>
	GuiTableComposition
		Rows, Columns: array(GuiCellOption)
	GuiCellComposition
		Site: SiteValue
GuiInstanceLoader_Document.cpp
	GuiDocumentItem
		default: GuiControl*, GuiGraphicsComposition*
	GuiDocumentViewer, GuiDocumentLable
		default: Ptr<GuiDocumentItem>
GuiInstanceLoader_List.cpp
	GuiComboBox
		ctor: ListControl(GuiListControl*)
	GuiTreeView
		Nodes: array(Ptr<tree::MemoryNodeProvider>)
	GuiBindableTreeView
		ctor: ReverseMappingProperty(WritableItemProperty<Value>)
	tree::TreeNode
		ctor: Text, Image
		Tag
GuiInstanceLoader_Templates.cpp
	GuiCommonDatePickerLook
		ctor: BackgroundColor, PrimaryTextColor, SecondaryTextColor
	GuiCommonScrollViewLook
		ctor: DefaultScrollSize
GuiInstanceLoader_Toolstrip.cpp
	GuiToolstripMenu, GuiToolstripMenuBar, GuiToolstripToolBar, GuiBindableRibbonGalleryMenu
		default: collection(GuiControl*)
	GuiToolstripButton
		SubMenu-set: GuiToolstripMenu*
	GuiRibbonButtons
		ctor: MaxSize, MinSize
*/

#include "GuiInstanceLoader_TemplateControl.h"

namespace vl
{
	namespace presentation
	{
		namespace instance_loaders
		{

#ifndef VCZH_DEBUG_NO_REFLECTION

/***********************************************************************
GuiControlInstanceLoader
***********************************************************************/

			class GuiControlInstanceLoader : public Object, public IGuiInstanceLoader
			{
			protected:
				GlobalStringKey					typeName;

			public:
				GuiControlInstanceLoader()
				{
					typeName = GlobalStringKey::Get(description::TypeInfo<GuiControl>::content.typeName);
				}

				GlobalStringKey GetTypeName()override
				{
					return typeName;
				}

				void GetPropertyNames(GuiResourcePrecompileContext& precompileContext, const TypeInfo& typeInfo, collections::List<GlobalStringKey>& propertyNames)override
				{
					propertyNames.Add(GlobalStringKey::Empty);
				}

				Ptr<GuiInstancePropertyInfo> GetPropertyType(GuiResourcePrecompileContext& precompileContext, const PropertyInfo& propertyInfo)override
				{
					if (propertyInfo.propertyName == GlobalStringKey::Empty)
					{
						auto info = GuiInstancePropertyInfo::Collection(nullptr);
						info->acceptableTypes.Add(TypeInfoRetriver<GuiControl*>::CreateTypeInfo());
						info->acceptableTypes.Add(TypeInfoRetriver<GuiGraphicsComposition*>::CreateTypeInfo());
						if (propertyInfo.typeInfo.typeInfo->GetTypeDescriptor()->CanConvertTo(description::GetTypeDescriptor<GuiInstanceRootObject>()))
						{
							info->acceptableTypes.Add(TypeInfoRetriver<GuiComponent*>::CreateTypeInfo());
						}
						return info;
					}
					return IGuiInstanceLoader::GetPropertyType(precompileContext, propertyInfo);
				}

				Ptr<workflow::WfStatement> AssignParameters(GuiResourcePrecompileContext& precompileContext, types::ResolvingResult& resolvingResult, const TypeInfo& typeInfo, GlobalStringKey variableName, ArgumentMap& arguments, GuiResourceTextPos attPosition, GuiResourceError::List& errors)override
				{
					auto block = Ptr(new WfBlockStatement);

					// TODO: (enumerable) foreach on group
					for (auto [prop, index] : indexed(arguments.Keys()))
					{
						const auto& values = arguments.GetByIndex(index);
						if (prop == GlobalStringKey::Empty)
						{
							auto value = values[0].expression;
							auto td = values[0].typeInfo->GetTypeDescriptor();

							Ptr<WfExpression> expr;
							if (td->CanConvertTo(description::GetTypeDescriptor<GuiComponent>()))
							{
								auto refControl = Ptr(new WfReferenceExpression);
								refControl->name.value = variableName.ToString();

								auto refAddComponent = Ptr(new WfMemberExpression);
								refAddComponent->parent = refControl;
								refAddComponent->name.value = L"AddComponent";

								auto call = Ptr(new WfCallExpression);
								call->function = refAddComponent;
								call->arguments.Add(value);

								expr = call;
							}
							else if (td->CanConvertTo(description::GetTypeDescriptor<GuiControlHost>()))
							{
								auto refControl = Ptr(new WfReferenceExpression);
								refControl->name.value = variableName.ToString();

								auto refAddControlHostComponent = Ptr(new WfMemberExpression);
								refAddControlHostComponent->parent = refControl;
								refAddControlHostComponent->name.value = L"AddControlHostComponent";

								auto call = Ptr(new WfCallExpression);
								call->function = refAddControlHostComponent;
								call->arguments.Add(value);

								expr = call;
							}
							else if (td->CanConvertTo(description::GetTypeDescriptor<GuiControl>()))
							{
								auto refControl = Ptr(new WfReferenceExpression);
								refControl->name.value = variableName.ToString();

								auto refAddChild = Ptr(new WfMemberExpression);
								refAddChild->parent = refControl;
								refAddChild->name.value = L"AddChild";

								auto call = Ptr(new WfCallExpression);
								call->function = refAddChild;
								call->arguments.Add(value);

								expr = call;
							}
							else if (td->CanConvertTo(description::GetTypeDescriptor<GuiGraphicsComposition>()))
							{
								auto refControl = Ptr(new WfReferenceExpression);
								refControl->name.value = variableName.ToString();

								auto refContainerComposition = Ptr(new WfMemberExpression);
								refContainerComposition->parent = refControl;
								refContainerComposition->name.value = L"ContainerComposition";

								auto refAddChild = Ptr(new WfMemberExpression);
								refAddChild->parent = refContainerComposition;
								refAddChild->name.value = L"AddChild";

								auto call = Ptr(new WfCallExpression);
								call->function = refAddChild;
								call->arguments.Add(value);

								expr = call;
							}

							if (expr)
							{
								auto stat = Ptr(new WfExpressionStatement);
								stat->expression = expr;
								block->statements.Add(stat);
							}
						}
					}

					if (block->statements.Count() > 0)
					{
						return block;
					}
					return nullptr;
				}
			};

/***********************************************************************
GuiRawElementInstanceLoader
***********************************************************************/

			class GuiRawElementInstanceLoader : public Object, public IGuiInstanceLoader
			{
			protected:
				GlobalStringKey							typeName;

			public:
				GuiRawElementInstanceLoader()
				{
					typeName = GlobalStringKey::Get(L"presentation::elements::GuiRawElement");
				}

				GlobalStringKey GetTypeName()override
				{
					return typeName;
				}

				bool CanCreate(const TypeInfo& typeInfo) override
				{
					return typeName == typeInfo.typeName;
				}

				Ptr<workflow::WfStatement> CreateInstance(GuiResourcePrecompileContext& precompileContext, types::ResolvingResult& resolvingResult, const TypeInfo& typeInfo, GlobalStringKey variableName, ArgumentMap& arguments, GuiResourceTextPos tagPosition, GuiResourceError::List& errors)override
				{
					if (CanCreate(typeInfo))
					{
						auto refCreateRawElement = Ptr(new WfChildExpression);
						refCreateRawElement->parent = GetExpressionFromTypeDescriptor(description::GetTypeDescriptor<IGuiGraphicsElement>());
						refCreateRawElement->name.value = L"CreateRawElement";

						auto call = Ptr(new WfCallExpression);
						call->function = refCreateRawElement;

						auto refVariable = Ptr(new WfReferenceExpression);
						refVariable->name.value = variableName.ToString();

						auto assign = Ptr(new WfBinaryExpression);
						assign->op = WfBinaryOperator::Assign;
						assign->first = refVariable;
						assign->second = call;

						auto stat = Ptr(new WfExpressionStatement);
						stat->expression = assign;
						return stat;
					}
					return nullptr;
				}
			};

#endif
			
/***********************************************************************
GuiPredefinedInstanceLoadersPlugin
***********************************************************************/

			void InitializeTrackerProgressBar(const WString& variableName, Ptr<WfBlockStatement> block)
			{
				auto refVariable = Ptr(new WfReferenceExpression);
				refVariable->name.value = variableName;

				auto refSetPageSize = Ptr(new WfMemberExpression);
				refSetPageSize->parent = refVariable;
				refSetPageSize->name.value = L"SetPageSize";

				auto refZero = Ptr(new WfIntegerExpression);
				refZero->value.value = L"0";

				auto call = Ptr(new WfCallExpression);
				call->function = refSetPageSize;
				call->arguments.Add(refZero);

				auto stat = Ptr(new WfExpressionStatement);
				stat->expression = call;
				block->statements.Add(stat);
			}

			extern void LoadToolstripControls(IGuiInstanceLoaderManager* manager);
			extern void LoadListControls(IGuiInstanceLoaderManager* manager);
			extern void LoadDocumentControls(IGuiInstanceLoaderManager* manager);
			extern void LoadCompositions(IGuiInstanceLoaderManager* manager);
			extern void LoadTemplates(IGuiInstanceLoaderManager* manager);

			class GuiPredefinedInstanceLoadersPlugin : public Object, public IGuiPlugin
			{
			public:

				GUI_PLUGIN_NAME(GacUI_Instance_TypeLoaders)
				{
					GUI_PLUGIN_DEPEND(GacUI_Res_ResourceResolver);
					GUI_PLUGIN_DEPEND(GacUI_Instance);
					GUI_PLUGIN_DEPEND(GacUI_Instance_Reflection);
				}

				void Load(bool controllerUnrelatedPlugins, bool controllerRelatedPlugins)override
				{
#ifndef VCZH_DEBUG_NO_REFLECTION
					if (controllerUnrelatedPlugins)
					{
						IGuiInstanceLoaderManager* manager=GetInstanceLoaderManager();

#define ADD_TEMPLATE_CONTROL(TYPENAME, THEME_NAME)\
						manager->SetLoader(\
							Ptr(new GuiTemplateControlInstanceLoader<TYPENAME>(\
								L"presentation::controls::" L ## #TYPENAME,\
								theme::ThemeName::THEME_NAME\
								)\
							))

#define ADD_VIRTUAL_CONTROL(VIRTUALTYPENAME, TYPENAME, THEME_NAME)\
						manager->CreateVirtualType(GlobalStringKey::Get(description::TypeInfo<TYPENAME>::content.typeName),\
							Ptr(new GuiTemplateControlInstanceLoader<TYPENAME>(\
								L"presentation::controls::Gui" L ## #VIRTUALTYPENAME,\
								theme::ThemeName::THEME_NAME\
								)\
							))

#define ADD_VIRTUAL_CONTROL_F(VIRTUALTYPENAME, TYPENAME, THEME_NAME, INIT_FUNCTION)\
						manager->CreateVirtualType(GlobalStringKey::Get(description::TypeInfo<TYPENAME>::content.typeName),\
							Ptr(new GuiTemplateControlInstanceLoader<TYPENAME>(\
								L"presentation::controls::Gui" L ## #VIRTUALTYPENAME,\
								theme::ThemeName::THEME_NAME,\
								nullptr,\
								INIT_FUNCTION\
								)\
							))

						manager->CreateVirtualType(
							GlobalStringKey::Get(description::TypeInfo<IGuiGraphicsElement>::content.typeName),
							Ptr(new GuiRawElementInstanceLoader)
							);

						manager->SetLoader(Ptr(new GuiControlInstanceLoader));

						/*													REAL-CONTROL-TYPE				THEME-NAME											*/
						ADD_TEMPLATE_CONTROL	(							GuiCustomControl,				CustomControl										);
						ADD_TEMPLATE_CONTROL	(							GuiLabel,						Label												);
						ADD_TEMPLATE_CONTROL	(							GuiButton,						Button												);
						ADD_TEMPLATE_CONTROL	(							GuiTabPage,						CustomControl										);
						ADD_TEMPLATE_CONTROL	(							GuiTab,							Tab													);
						ADD_TEMPLATE_CONTROL	(							GuiScrollContainer,				ScrollView											);
						ADD_TEMPLATE_CONTROL	(							GuiWindow,						Window												);
						ADD_TEMPLATE_CONTROL	(							GuiTextList,					TextList											);
						ADD_TEMPLATE_CONTROL	(							GuiBindableTextList,			TextList											);
						ADD_TEMPLATE_CONTROL	(							GuiListView,					ListView											);
						ADD_TEMPLATE_CONTROL	(							GuiBindableListView,			ListView											);
						ADD_TEMPLATE_CONTROL	(							GuiBindableDataGrid,			ListView											);
						ADD_TEMPLATE_CONTROL	(							GuiMultilineTextBox,			MultilineTextBox									);
						ADD_TEMPLATE_CONTROL	(							GuiSinglelineTextBox,			SinglelineTextBox									);
						ADD_TEMPLATE_CONTROL	(							GuiDatePicker,					DatePicker											);
						ADD_TEMPLATE_CONTROL	(							GuiDateComboBox,				DateComboBox										);
						ADD_TEMPLATE_CONTROL	(							GuiRibbonTab,					RibbonTab											);
						ADD_TEMPLATE_CONTROL	(							GuiRibbonTabPage,				CustomControl										);
						ADD_TEMPLATE_CONTROL	(							GuiRibbonGroup,					RibbonGroup											);
						ADD_TEMPLATE_CONTROL	(							GuiRibbonIconLabel,				RibbonIconLabel										);
						ADD_TEMPLATE_CONTROL	(							GuiRibbonToolstrips,			RibbonToolstrips									);
						ADD_TEMPLATE_CONTROL	(							GuiRibbonGallery,				RibbonGallery										);
						ADD_TEMPLATE_CONTROL	(							GuiBindableRibbonGalleryList,	RibbonGalleryList									);

						/*						VIRTUAL-CONTROL-TYPE		REAL-CONTROL-TYPE				THEME-NAME											*/
						ADD_VIRTUAL_CONTROL		(GroupBox,					GuiControl,						GroupBox											);
						ADD_VIRTUAL_CONTROL		(MenuSplitter,				GuiControl,						MenuSplitter										);
						ADD_VIRTUAL_CONTROL		(MenuBarButton,				GuiToolstripButton,				MenuBarButton										);
						ADD_VIRTUAL_CONTROL		(MenuItemButton,			GuiToolstripButton,				MenuItemButton										);
						ADD_VIRTUAL_CONTROL		(ToolstripToolBarInMenu,	GuiToolstripToolBar,			ToolstripToolBarInMenu								);
						ADD_VIRTUAL_CONTROL		(ToolstripDropdownButton,	GuiToolstripButton,				ToolstripDropdownButton								);
						ADD_VIRTUAL_CONTROL		(ToolstripSplitButton,		GuiToolstripButton,				ToolstripSplitButton								);
						ADD_VIRTUAL_CONTROL		(ToolstripSplitter,			GuiControl,						ToolstripSplitter									);
						ADD_VIRTUAL_CONTROL		(ToolstripSplitterInMenu,	GuiControl,						ToolstripSplitterInMenu								);
						ADD_VIRTUAL_CONTROL		(RibbonSmallButton,			GuiToolstripButton,				RibbonSmallButton									);
						ADD_VIRTUAL_CONTROL		(RibbonSmallDropdownButton,	GuiToolstripButton,				RibbonSmallDropdownButton							);
						ADD_VIRTUAL_CONTROL		(RibbonSmallSplitButton,	GuiToolstripButton,				RibbonSmallSplitButton								);
						ADD_VIRTUAL_CONTROL		(RibbonLargeButton,			GuiToolstripButton,				RibbonLargeButton									);
						ADD_VIRTUAL_CONTROL		(RibbonLargeDropdownButton,	GuiToolstripButton,				RibbonLargeDropdownButton							);
						ADD_VIRTUAL_CONTROL		(RibbonLargeSplitButton,	GuiToolstripButton,				RibbonLargeSplitButton								);
						ADD_VIRTUAL_CONTROL		(RibbonSmallIconLabel,		GuiRibbonIconLabel,				RibbonSmallIconLabel								);
						ADD_VIRTUAL_CONTROL		(RibbonSplitter,			GuiControl,						RibbonSplitter										);
						ADD_VIRTUAL_CONTROL		(RibbonToolstripHeader,		GuiControl,						RibbonToolstripHeader								);
						ADD_VIRTUAL_CONTROL		(CheckBox,					GuiSelectableButton,			CheckBox											);
						ADD_VIRTUAL_CONTROL		(RadioButton,				GuiSelectableButton,			RadioButton											);
						ADD_VIRTUAL_CONTROL		(HScroll,					GuiScroll,						HScroll												);
						ADD_VIRTUAL_CONTROL		(VScroll,					GuiScroll,						VScroll												);
						ADD_VIRTUAL_CONTROL		(DocumentTextBox,			GuiDocumentLabel,				DocumentTextBox										);
						ADD_VIRTUAL_CONTROL_F	(HTracker,					GuiScroll,						HTracker,				InitializeTrackerProgressBar);
						ADD_VIRTUAL_CONTROL_F	(VTracker,					GuiScroll,						VTracker,				InitializeTrackerProgressBar);
						ADD_VIRTUAL_CONTROL_F	(ProgressBar,				GuiScroll,						ProgressBar,			InitializeTrackerProgressBar);

						LoadToolstripControls(manager);
						LoadListControls(manager);
						LoadDocumentControls(manager);
						LoadCompositions(manager);
						LoadTemplates(manager);
					}
#undef ADD_TEMPLATE_CONTROL
#undef ADD_VIRTUAL_CONTROL
#undef ADD_VIRTUAL_CONTROL_F
#endif
				}

				void Unload(bool controllerUnrelatedPlugins, bool controllerRelatedPlugins)override
				{
				}
			};
			GUI_REGISTER_PLUGIN(GuiPredefinedInstanceLoadersPlugin)
		}
	}
}