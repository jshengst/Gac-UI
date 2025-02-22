#include "GuiDataGridControls.h"
#include "GuiDataGridExtensions.h"
#include "../../GraphicsComposition/GuiGraphicsTableComposition.h"
#include "../../Application/GraphicsHost/GuiGraphicsHost.h"

namespace vl
{
	namespace presentation
	{
		namespace controls
		{
			namespace list
			{
				using namespace compositions;
				using namespace collections;
				using namespace description;
				using namespace templates;

				const wchar_t* const IDataGridView::Identifier = L"vl::presentation::controls::list::IDataGridView";

/***********************************************************************
DefaultDataGridItemTemplate
***********************************************************************/

				IDataVisualizerFactory* DefaultDataGridItemTemplate::GetDataVisualizerFactory(vint row, vint column)
				{
					if (auto dataGrid = dynamic_cast<GuiVirtualDataGrid*>(listControl))
					{
						if (auto factory = dataGrid->dataGridView->GetCellDataVisualizerFactory(row, column))
						{
							return factory;
						}

						if (column == 0)
						{
							return dataGrid->defaultMainColumnVisualizerFactory.Obj();
						}
						else
						{
							return dataGrid->defaultSubColumnVisualizerFactory.Obj();
						}

					}

					return nullptr;
				}

				IDataEditorFactory* DefaultDataGridItemTemplate::GetDataEditorFactory(vint row, vint column)
				{
					if (auto dataGrid = dynamic_cast<GuiVirtualDataGrid*>(listControl))
					{
						return dataGrid->dataGridView->GetCellDataEditorFactory(row, column);
					}
					return nullptr;
				}

				vint DefaultDataGridItemTemplate::GetCellColumnIndex(compositions::GuiGraphicsComposition* composition)
				{
					for (vint i = 0; i < textTable->GetColumns(); i++)
					{
						auto cell = textTable->GetSitedCell(0, i);
						if (composition == cell)
						{
							return i;
						}
					}
					return -1;
				}

				bool DefaultDataGridItemTemplate::IsInEditor(GuiVirtualDataGrid* dataGrid, compositions::GuiMouseEventArgs& arguments)
				{
					if (!dataGrid->currentEditor) return false;
					auto editorComposition = dataGrid->currentEditor->GetTemplate();
					auto currentComposition = arguments.eventSource;

					while (currentComposition)
					{
						if (currentComposition == editorComposition)
						{
							return true;
						}
						else if (currentComposition == this)
						{
							break;
						}
						else
						{
							currentComposition = currentComposition->GetParent();
						}
					}

					return false;
				}

				void DefaultDataGridItemTemplate::OnCellButtonDown(compositions::GuiGraphicsComposition* sender, compositions::GuiMouseEventArgs& arguments)
				{
					if (auto dataGrid = dynamic_cast<GuiVirtualDataGrid*>(listControl))
					{
						if (IsInEditor(dataGrid, arguments))
						{
							arguments.handled = true;
						}
					}
				}

				void DefaultDataGridItemTemplate::OnCellLeftButtonUp(compositions::GuiGraphicsComposition* sender, compositions::GuiMouseEventArgs& arguments)
				{
					if (auto dataGrid = dynamic_cast<GuiVirtualDataGrid*>(listControl))
					{
						if (IsInEditor(dataGrid, arguments))
						{
							arguments.handled = true;
						}
						else if (dataGrid->GetVisuallyEnabled())
						{
							vint index = GetCellColumnIndex(sender);
							if (index != -1)
							{
								vint currentRow = GetIndex();
								dataGrid->SelectCell({ currentRow,index }, true);
							}
						}
					}
				}

				void DefaultDataGridItemTemplate::OnCellRightButtonUp(compositions::GuiGraphicsComposition* sender, compositions::GuiMouseEventArgs& arguments)
				{
					if (auto dataGrid = dynamic_cast<GuiVirtualDataGrid*>(listControl))
					{
						if (IsInEditor(dataGrid, arguments))
						{
							arguments.handled = true;
						}
						else if (dataGrid->GetVisuallyEnabled())
						{
							vint index = GetCellColumnIndex(sender);
							if (index != -1)
							{
								vint currentRow = GetIndex();
								dataGrid->SelectCell({ currentRow,index }, false);
							}
						}
					}
				}

				void DefaultDataGridItemTemplate::DeleteAllVisualizers()
				{
					for (vint i = 0; i < dataVisualizers.Count(); i++)
					{
						DeleteVisualizer(i);
					}
				}

				void DefaultDataGridItemTemplate::DeleteVisualizer(vint column)
				{
					auto visualizer = dataVisualizers[column];
					auto composition = visualizer->GetTemplate();
					visualizer->NotifyDeletedTemplate();
					if (composition->GetParent())
					{
						composition->GetParent()->RemoveChild(composition);
					}
					SafeDeleteComposition(composition);
					dataVisualizers[column] = nullptr;
				}

				void DefaultDataGridItemTemplate::ResetDataTable(vint columnCount)
				{
					vint itemIndex = GetIndex();

					if (dataVisualizers.Count() == columnCount)
					{
						for (vint i = 0; i < columnCount; i++)
						{
							auto factory = GetDataVisualizerFactory(itemIndex, i);
							if (dataVisualizerFactories[i] != factory)
							{
								DeleteVisualizer(i);
								dataVisualizerFactories[i] = factory;
							}
						}
					}
					else
					{
						DeleteAllVisualizers();
						dataVisualizerFactories.Resize(columnCount);
						dataVisualizers.Resize(columnCount);

						for (auto cell : dataCells)
						{
							SafeDeleteComposition(cell);
						}
						dataCells.Resize(columnCount);
						
						for (vint i = 0; i < columnCount; i++)
						{
							dataVisualizerFactories[i] = GetDataVisualizerFactory(itemIndex, i);
						}

						textTable->SetRowsAndColumns(1, columnCount);
						for (vint i = 0; i < columnCount; i++)
						{
							auto cell = new GuiCellComposition;
							textTable->AddChild(cell);
							cell->SetSite(0, i, 1, 1);
							cell->GetEventReceiver()->leftButtonDown.AttachMethod(this, &DefaultDataGridItemTemplate::OnCellButtonDown);
							cell->GetEventReceiver()->rightButtonDown.AttachMethod(this, &DefaultDataGridItemTemplate::OnCellButtonDown);
							cell->GetEventReceiver()->leftButtonUp.AttachMethod(this, &DefaultDataGridItemTemplate::OnCellLeftButtonUp);
							cell->GetEventReceiver()->rightButtonUp.AttachMethod(this, &DefaultDataGridItemTemplate::OnCellRightButtonUp);
							dataCells[i] = cell;
						}
					}
				}

				void DefaultDataGridItemTemplate::OnInitialize()
				{
					{
						textTable = new GuiTableComposition;
						textTable->SetMinSizeLimitation(GuiGraphicsComposition::LimitToElementAndChildren);
						textTable->SetAlignmentToParent(Margin(0, 0, 0, 0));
						textTable->SetRowsAndColumns(1, 1);
						textTable->SetRowOption(0, GuiCellOption::MinSizeOption());
						textTable->SetColumnOption(0, GuiCellOption::AbsoluteOption(0));
						AddChild(textTable);
					}

					SelectedChanged.AttachMethod(this, &DefaultDataGridItemTemplate::OnSelectedChanged);
					FontChanged.AttachMethod(this, &DefaultDataGridItemTemplate::OnFontChanged);
					ContextChanged.AttachMethod(this, &DefaultDataGridItemTemplate::OnContextChanged);
					VisuallyEnabledChanged.AttachMethod(this, &DefaultDataGridItemTemplate::OnVisuallyEnabledChanged);

					SelectedChanged.Execute(compositions::GuiEventArgs(this));
					FontChanged.Execute(compositions::GuiEventArgs(this));
					ContextChanged.Execute(compositions::GuiEventArgs(this));
					VisuallyEnabledChanged.Execute(compositions::GuiEventArgs(this));
				}

				void DefaultDataGridItemTemplate::OnRefresh()
				{
					if (auto dataGrid = dynamic_cast<GuiVirtualDataGrid*>(listControl))
					{
						vint columnCount = dataGrid->listViewItemView->GetColumnCount();
						vint itemIndex = GetIndex();
						ResetDataTable(columnCount);

						for (vint i = 0; i < columnCount; i++)
						{
							auto& dataVisualizer = dataVisualizers[i];
							if (!dataVisualizer)
							{
								dataVisualizer = dataVisualizerFactories[i]->CreateVisualizer(dataGrid);
								dataVisualizer->GetTemplate()->SetFont(GetFont());
								dataVisualizers[i] = dataVisualizer;

								auto cell = dataCells[i];
								auto composition = dataVisualizer->GetTemplate();
								composition->SetAlignmentToParent(Margin(0, 0, 0, 0));
								cell->AddChild(composition);
							}
							dataVisualizer->BeforeVisualizeCell(dataGrid->GetItemProvider(), itemIndex, i);
						}

						GridPos selectedCell = dataGrid->GetSelectedCell();
						if (selectedCell.row == itemIndex)
						{
							NotifySelectCell(selectedCell.column);
						}
						else
						{
							NotifySelectCell(-1);
						}
					}
					UpdateSubItemSize();
				}

				void DefaultDataGridItemTemplate::OnSelectedChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
				{
					if (!GetSelected())
					{
						NotifySelectCell(-1);
					}
				}

				void DefaultDataGridItemTemplate::OnFontChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
				{
					for (auto visualizer : dataVisualizers)
					{
						visualizer->GetTemplate()->SetFont(GetFont());
					}
					if (currentEditor)
					{
						currentEditor->GetTemplate()->SetFont(GetFont());
					}
				}

				void DefaultDataGridItemTemplate::OnContextChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
				{
					for (auto visualizer : dataVisualizers)
					{
						visualizer->GetTemplate()->SetContext(GetContext());
					}
					if (currentEditor)
					{
						currentEditor->GetTemplate()->SetContext(GetContext());
					}
				}

				void DefaultDataGridItemTemplate::OnVisuallyEnabledChanged(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
				{
					for (auto visualizer : dataVisualizers)
					{
						visualizer->GetTemplate()->SetVisuallyEnabled(GetVisuallyEnabled());
					}
					if (currentEditor)
					{
						currentEditor->GetTemplate()->SetVisuallyEnabled(GetVisuallyEnabled());
					}
				}

				DefaultDataGridItemTemplate::DefaultDataGridItemTemplate()
				{
				}

				DefaultDataGridItemTemplate::~DefaultDataGridItemTemplate()
				{
					for (auto visualizer : dataVisualizers)
					{
						visualizer->NotifyDeletedTemplate();
					}
					if (currentEditor)
					{
						currentEditor->NotifyDeletedTemplate();
					}
				}

				void DefaultDataGridItemTemplate::UpdateSubItemSize()
				{
					if (auto dataGrid = dynamic_cast<GuiVirtualDataGrid*>(listControl))
					{
						vint columnCount = dataGrid->listViewItemView->GetColumnCount();
						if (columnCount > textTable->GetColumns())
						{
							columnCount = textTable->GetColumns();
						}
						for (vint i = 0; i < columnCount; i++)
						{
							textTable->SetColumnOption(i, GuiCellOption::AbsoluteOption(dataGrid->columnItemView->GetColumnSize(i)));
						}
					}
				}

				bool DefaultDataGridItemTemplate::IsEditorOpened()
				{
					return currentEditor != nullptr;
				}

				void DefaultDataGridItemTemplate::NotifyOpenEditor(vint column, IDataEditor* editor)
				{
					currentEditor = editor;
					if (currentEditor)
					{
						auto cell = textTable->GetSitedCell(0, column);
						auto* editorBounds = currentEditor->GetTemplate();
						editorBounds->SetFont(GetFont());
						editorBounds->SetContext(GetContext());
						if (editorBounds->GetParent() && editorBounds->GetParent() != cell)
						{
							editorBounds->GetParent()->RemoveChild(editorBounds);
						}
						editorBounds->SetAlignmentToParent(Margin(0, 0, 0, 0));
						cell->AddChild(editorBounds);
						if (auto focusControl = currentEditor->GetTemplate()->GetFocusControl())
						{
							focusControl->SetFocused();
						}
						dataVisualizers[column]->GetTemplate()->SetVisible(false);
					}
				}

				void DefaultDataGridItemTemplate::NotifyCloseEditor()
				{
					if (currentEditor)
					{
						for (vint i = 0; i < dataVisualizers.Count(); i++)
						{
							dataVisualizers[i]->GetTemplate()->SetVisible(true);
						}
						auto composition = currentEditor->GetTemplate();
						if (composition->GetParent())
						{
							composition->GetParent()->RemoveChild(composition);
						}
						currentEditor = nullptr;
					}
				}

				void DefaultDataGridItemTemplate::NotifySelectCell(vint column)
				{
					for (vint i = 0; i < dataVisualizers.Count(); i++)
					{
						dataVisualizers[i]->SetSelected(i == column);
					}
				}

				void DefaultDataGridItemTemplate::NotifyCellEdited()
				{
					for (vint i = 0; i < dataVisualizers.Count(); i++)
					{
						dataVisualizers[i]->BeforeVisualizeCell(listControl->GetItemProvider(), GetIndex(), i);
					}
				}
			}
				
/***********************************************************************
GuiVirtualDataGrid (Editor)
***********************************************************************/

			using namespace list;

			compositions::IGuiAltActionHost* GuiVirtualDataGrid::GetActivatingAltHost()
			{
				if (currentEditor)
				{
					if (auto focusControl = currentEditor->GetTemplate()->GetFocusControl())
					{
						if (auto action = focusControl->QueryTypedService<IGuiAltAction>())
						{
							if (action->IsAltAvailable() && action->IsAltEnabled())
							{
								SetAltComposition(currentEditor->GetTemplate());
								SetAltControl(focusControl, true);
								return this;
							}
						}
					}
				}
				SetAltComposition(nullptr);
				SetAltControl(nullptr, false);
				return GuiVirtualListView::GetActivatingAltHost();
			}

			void GuiVirtualDataGrid::NotifySelectionChanged(bool triggeredByItemContentModified)
			{
				GuiVirtualListView::NotifySelectionChanged(triggeredByItemContentModified);
				if (!skipOnSelectionChanged && !triggeredByItemContentModified)
				{
					vint row = GetSelectedItemIndex();
					if (row == selectedCell.row)
					{
						// do nothing
					}
					else if (row != -1)
					{
						if (selectedCell.row != row && selectedCell.column != -1)
						{
							SelectCell({ row,selectedCell.column }, false);
						}
						else
						{
							SelectCell({ row,0 }, false);
						}
					}
					else
					{
						StopEdit();
						NotifySelectCell(-1, -1);
					}
				}
			}

			void GuiVirtualDataGrid::OnItemModified(vint start, vint count, vint newCount, bool itemReferenceUpdated)
			{
				GuiVirtualListView::OnItemModified(start, count, newCount, itemReferenceUpdated);
				if (!GetItemProvider()->IsEditing())
				{
					StopEdit();
				}
			}

			void GuiVirtualDataGrid::OnStyleInstalled(vint index, ItemStyle* style, bool refreshPropertiesOnly)
			{
				GuiVirtualListView::OnStyleInstalled(index, style, refreshPropertiesOnly);
				if (auto itemStyle = dynamic_cast<DefaultDataGridItemTemplate*>(style))
				{
					if (selectedCell.row == index && selectedCell.column != -1)
					{
						itemStyle->NotifySelectCell(selectedCell.column);
					}
				}
			}

			void GuiVirtualDataGrid::OnStyleUninstalled(ItemStyle* style)
			{
				GuiVirtualListView::OnStyleUninstalled(style);
				if (auto itemStyle = dynamic_cast<DefaultDataGridItemTemplate*>(style))
				{
					if (itemStyle->IsEditorOpened())
					{
						itemStyle->NotifyCloseEditor();
						currentEditor = nullptr;
						currentEditorPos = { -1,-1 };
					}
				}
			}

			void GuiVirtualDataGrid::NotifyCloseEditor()
			{
				if (currentEditorPos.row != -1 && GetArranger())
				{
					auto style = GetArranger()->GetVisibleStyle(currentEditorPos.row);
					if (auto itemStyle = dynamic_cast<DefaultDataGridItemTemplate*>(style))
					{
						itemStyle->NotifyCloseEditor();
					}
				}
			}

			void GuiVirtualDataGrid::NotifySelectCell(vint row, vint column)
			{
				if (selectedCell.row != row || selectedCell.column != column)
				{
					selectedCell = { row, column };
					SelectedCellChanged.Execute(GetNotifyEventArguments());

					auto style = GetArranger()->GetVisibleStyle(row);
					if (auto itemStyle = dynamic_cast<DefaultDataGridItemTemplate*>(style))
					{
						itemStyle->NotifySelectCell(column);
					}
				}
			}

			bool GuiVirtualDataGrid::StartEdit(vint row, vint column)
			{
				StopEdit();
				NotifySelectCell(row, column);

				auto style = GetArranger()->GetVisibleStyle(row);
				if (auto itemStyle = dynamic_cast<DefaultDataGridItemTemplate*>(style))
				{
					if (auto factory = dataGridView->GetCellDataEditorFactory(row, column))
					{
						currentEditorOpeningEditor = true;
						currentEditorPos = { row,column };
						currentEditor = factory->CreateEditor(this);
						if (auto focusControl = currentEditor->GetTemplate()->GetFocusControl())
						{
							focusControl->SetAlt(L"E");
						}
						currentEditor->BeforeEditCell(GetItemProvider(), row, column);
						itemStyle->NotifyOpenEditor(column, currentEditor.Obj());
						currentEditorOpeningEditor = false;
						return true;
					}
				}
				return false;
			}

			void GuiVirtualDataGrid::StopEdit()
			{
				if (GetItemProvider()->IsEditing())
				{
					NotifyCloseEditor();
				}
				else
				{
					if (currentEditorPos != GridPos{-1, -1})
					{
						if (currentEditor)
						{
							NotifyCloseEditor();
						}
					}
				}
				SetAltComposition(nullptr);
				SetAltControl(nullptr, false);
				currentEditor = nullptr;
				currentEditorPos = { -1,-1 };
			}

/***********************************************************************
GuiVirtualDataGrid (IDataGridContext)
***********************************************************************/

			templates::GuiListViewTemplate* GuiVirtualDataGrid::GetListViewControlTemplate()
			{
				return TypedControlTemplateObject(true);
			}

			void GuiVirtualDataGrid::RequestSaveData()
			{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::controls::list::DefaultTextListItemTemplate::OnBulletSelectedChanged(GuiGraphicsComposition*, GuiEventArgs&)#"
				if (currentEditor && !currentEditorOpeningEditor)
				{
					GuiControl* focusedControl = nullptr;
					if (auto controlHost = GetRelatedControlHost())
					{
						if (auto graphicsHost = controlHost->GetGraphicsHost())
						{
							if (auto focusComposition = graphicsHost->GetFocusedComposition())
							{
								focusedControl = focusComposition->GetRelatedControl();
							}
						}
					}

					GetItemProvider()->PushEditing();
					dataGridView->SetBindingCellValue(currentEditorPos.row, currentEditorPos.column, currentEditor->GetTemplate()->GetCellValue());
					CHECK_ERROR(GetItemProvider()->PopEditing(), ERROR_MESSAGE_PREFIX L"BeginEditListItem and EndEditListItem calls are not paired.");

					auto style = GetArranger()->GetVisibleStyle(currentEditorPos.row);
					if (auto itemStyle = dynamic_cast<DefaultDataGridItemTemplate*>(style))
					{
						itemStyle->NotifyCellEdited();
					}

					if (currentEditor && focusedControl)
					{
						focusedControl->SetFocused();
					}
				}
#undef ERROR_MESSAGE_PREFIX
			}

/***********************************************************************
GuiVirtualDataGrid
***********************************************************************/

			void GuiVirtualDataGrid::OnColumnClicked(compositions::GuiGraphicsComposition* sender, compositions::GuiItemEventArgs& arguments)
			{
				if(dataGridView->IsColumnSortable(arguments.itemIndex))
				{
					switch(columnItemView->GetSortingState(arguments.itemIndex))
					{
					case ColumnSortingState::NotSorted:
						dataGridView->SortByColumn(arguments.itemIndex, true);
						break;
					case ColumnSortingState::Ascending:
						dataGridView->SortByColumn(arguments.itemIndex, false);
						break;
					case ColumnSortingState::Descending:
						dataGridView->SortByColumn(-1, false);
						break;
					}
				}
			}

			void GuiVirtualDataGrid::OnKeyDown(compositions::GuiGraphicsComposition* sender, compositions::GuiKeyEventArgs& arguments)
			{
				if (selectedCell.row != -1)
				{
					if (arguments.code == VKEY::KEY_RETURN)
					{
						RequestSaveData();
						SelectCell(selectedCell, !currentEditor);
						arguments.handled = true;
						if (!currentEditor)
						{
							SetFocused();
						}
						arguments.handled = true;
					}
					else if (arguments.code == VKEY::KEY_ESCAPE)
					{
						if (currentEditor)
						{
							SelectCell(currentEditorPos, false);
							SetFocused();
							arguments.handled = true;
						}
					}
					else
					{
						vint columnOffset = 0;
						switch (arguments.code)
						{
						case VKEY::KEY_LEFT:
							columnOffset = -1;
							arguments.handled = true;
							break;
						case VKEY::KEY_RIGHT:
							columnOffset = 1;
							arguments.handled = true;
							break;
						default:
							return;
						}

						vint column = selectedCell.column + columnOffset;
						if (column < 0)
						{
							column = 0;
						}
						else if (column >= listViewItemView->GetColumnCount())
						{
							column = listViewItemView->GetColumnCount();
						}
						SelectCell({ selectedCell.row, column }, false);
					}
				}
			}

			void GuiVirtualDataGrid::OnKeyUp(compositions::GuiGraphicsComposition* sender, compositions::GuiKeyEventArgs& arguments)
			{
			}

			GuiVirtualDataGrid::GuiVirtualDataGrid(theme::ThemeName themeName, list::IItemProvider* _itemProvider)
				:GuiVirtualListView(themeName, _itemProvider)
			{
				listViewItemView = dynamic_cast<IListViewItemView*>(_itemProvider->RequestView(WString::Unmanaged(IListViewItemView::Identifier)));
				columnItemView = dynamic_cast<ListViewColumnItemArranger::IColumnItemView*>(_itemProvider->RequestView(WString::Unmanaged(ListViewColumnItemArranger::IColumnItemView::Identifier)));
				dataGridView = dynamic_cast<IDataGridView*>(_itemProvider->RequestView(WString::Unmanaged(IDataGridView::Identifier)));

				{
					auto mainProperty = [](const Value&) { return new MainColumnVisualizerTemplate; };
					auto subProperty = [](const Value&) { return new SubColumnVisualizerTemplate; };
					auto focusRectangleProperty = [](const Value&) { return new FocusRectangleVisualizerTemplate; };
					auto cellBorderProperty = [](const Value&) { return new CellBorderVisualizerTemplate; };

					defaultMainColumnVisualizerFactory = 
						Ptr(new DataVisualizerFactory(cellBorderProperty,
							Ptr(new DataVisualizerFactory(focusRectangleProperty,
								Ptr(new DataVisualizerFactory(mainProperty)
						)))));
					defaultSubColumnVisualizerFactory = 
						Ptr(new DataVisualizerFactory(cellBorderProperty,
							Ptr(new DataVisualizerFactory(focusRectangleProperty,
								Ptr(new DataVisualizerFactory(subProperty)
						)))));
				}

				CHECK_ERROR(listViewItemView != nullptr, L"GuiVirtualDataGrid::GuiVirtualDataGrid(IStyleController*, GuiListControl::IItemProvider*)#Missing IListViewItemView from item provider.");
				CHECK_ERROR(columnItemView != nullptr, L"GuiVirtualDataGrid::GuiVirtualDataGrid(IStyleController*, GuiListControl::IItemProvider*)#Missing ListViewColumnItemArranger::IColumnItemView from item provider.");
				CHECK_ERROR(dataGridView != nullptr, L"GuiVirtualDataGrid::GuiVirtualDataGrid(IStyleController*, GuiListControl::IItemProvider*)#Missing IDataGridView from item provider.");

				SetViewToDefault();

				ColumnClicked.AttachMethod(this, &GuiVirtualDataGrid::OnColumnClicked);
				focusableComposition->GetEventReceiver()->keyDown.AttachMethod(this, &GuiVirtualDataGrid::OnKeyDown);
				focusableComposition->GetEventReceiver()->keyUp.AttachMethod(this, &GuiVirtualDataGrid::OnKeyUp);
				SelectedCellChanged.SetAssociatedComposition(boundsComposition);
			}

			GuiVirtualDataGrid::~GuiVirtualDataGrid()
			{
			}

			list::IItemProvider* GuiVirtualDataGrid::GetItemProvider()
			{
				return GuiVirtualListView::GetItemProvider();
			}

			void GuiVirtualDataGrid::SetViewToDefault()
			{
				SetStyleAndArranger(
					[](const Value&) { return new list::DefaultDataGridItemTemplate; },
					Ptr(new list::ListViewColumnItemArranger)
				);
			}

			GridPos GuiVirtualDataGrid::GetSelectedCell()
			{
				return selectedCell;
			}

			Ptr<list::IDataEditor> GuiVirtualDataGrid::GetOpenedEditor()
			{
				return currentEditor;
			}

			bool GuiVirtualDataGrid::SelectCell(const GridPos& value, bool openEditor)
			{
				bool validPos = 0 <= value.row && value.row < GetItemProvider()->Count() && 0 <= value.column && value.column < listViewItemView->GetColumnCount();

				if (validPos && selectedCell == value)
				{
					if (currentEditor && !openEditor)
					{
						StopEdit();
					}
					else if (!currentEditor && openEditor)
					{
						StartEdit(value.row, value.column);
					}
					return currentEditor != nullptr;
				}

				StopEdit();
				if (validPos)
				{
					NotifySelectCell(value.row, value.column);
					if (openEditor)
					{
						EnsureItemVisible(value.row);
						if (GetMultiSelect())
						{
							ClearSelection();
						}
					}
					skipOnSelectionChanged = true;
					SetSelected(value.row, true);
					skipOnSelectionChanged = false;
					if (openEditor)
					{
						return StartEdit(value.row, value.column);
					}
				}
				else
				{
					NotifySelectCell(-1, -1);
					ClearSelection();
				}
				return false;
			}
		}
	}
}