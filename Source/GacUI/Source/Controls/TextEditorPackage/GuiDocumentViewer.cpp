#include "GuiDocumentViewer.h"
#include "../../Application/GraphicsHost/GuiGraphicsHost.h"

namespace vl
{
	namespace presentation
	{
		namespace controls
		{
			using namespace collections;
			using namespace elements;
			using namespace compositions;

/***********************************************************************
GuiDocumentItem
***********************************************************************/

			GuiDocumentItem::GuiDocumentItem(const WString& _name)
				:name(_name)
			{
				container = new GuiBoundsComposition;
				container->SetMinSizeLimitation(GuiGraphicsComposition::LimitToElementAndChildren);
				container->SetAssociatedCursor(GetCurrentController()->ResourceService()->GetSystemCursor(INativeCursor::Arrow));
			}

			GuiDocumentItem::~GuiDocumentItem()
			{
				if (!owned)
				{
					SafeDeleteComposition(container);
				}
			}

			compositions::GuiGraphicsComposition* GuiDocumentItem::GetContainer()
			{
				return container;
			}

			WString GuiDocumentItem::GetName()
			{
				return name;
			}

/***********************************************************************
GuiDocumentCommonInterface
***********************************************************************/
			
			void GuiDocumentCommonInterface::InvokeUndoRedoChanged()
			{
				UndoRedoChanged.Execute(documentControl->GetNotifyEventArguments());
			}

			void GuiDocumentCommonInterface::InvokeModifiedChanged()
			{
				ModifiedChanged.Execute(documentControl->GetNotifyEventArguments());
			}

			void GuiDocumentCommonInterface::UpdateCaretPoint()
			{
				GuiGraphicsHost* host=documentComposition->GetRelatedGraphicsHost();
				if(host)
				{
					Rect caret=documentElement->GetCaretBounds(documentElement->GetCaretEnd(), documentElement->IsCaretEndPreferFrontSide());
					Point view=GetDocumentViewPosition();
					vint x=caret.x1-view.x;
					vint y=caret.y2-view.y;
					host->SetCaretPoint(Point(x, y), documentComposition);
				}
			}

			void GuiDocumentCommonInterface::EnsureDocumentRectVisible(Rect bounds)
			{
				if (bounds != Rect())
				{
					bounds.x1 -= 15;
					bounds.y1 -= 15;
					bounds.x2 += 15;
					bounds.y2 += 15;
					EnsureRectVisible(bounds);
				}
			}

			void GuiDocumentCommonInterface::Move(TextPos caret, bool shift, bool frontSide)
			{
				TextPos begin=documentElement->GetCaretBegin();
				TextPos end=documentElement->GetCaretEnd();
				
				TextPos newBegin=shift?begin:caret;
				TextPos newEnd=caret;
				documentElement->SetCaret(newBegin, newEnd, frontSide);
				documentElement->SetCaretVisible(true);
				EnsureDocumentRectVisible(documentElement->GetCaretBounds(newEnd, frontSide));
				UpdateCaretPoint();
				SelectionChanged.Execute(documentControl->GetNotifyEventArguments());
			}

			bool GuiDocumentCommonInterface::ProcessKey(VKEY code, bool shift, bool ctrl)
			{
				if(IGuiShortcutKeyItem* item=internalShortcutKeyManager->TryGetShortcut(ctrl, shift, false, code))
				{
					GuiEventArgs arguments(documentControl->GetBoundsComposition());
					item->Executed.Execute(arguments);
					return true;
				}

				TextPos currentCaret=documentElement->GetCaretEnd();
				bool frontSide=documentElement->IsCaretEndPreferFrontSide();
				TextPos begin=documentElement->GetCaretBegin();
				TextPos end=documentElement->GetCaretEnd();

				switch(code)
				{
				case VKEY::KEY_UP:
					{
						TextPos newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretMoveUp, frontSide);
						Move(newCaret, shift, frontSide);
					}
					break;
				case VKEY::KEY_DOWN:
					{
						TextPos newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretMoveDown, frontSide);
						Move(newCaret, shift, frontSide);
					}
					break;
				case VKEY::KEY_LEFT:
					{
						TextPos newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretMoveLeft, frontSide);
						Move(newCaret, shift, frontSide);
					}
					break;
				case VKEY::KEY_RIGHT:
					{
						TextPos newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretMoveRight, frontSide);
						Move(newCaret, shift, frontSide);
					}
					break;
				case VKEY::KEY_HOME:
					{
						TextPos newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretLineFirst, frontSide);
						if(newCaret==currentCaret)
						{
							newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretFirst, frontSide);
						}
						Move(newCaret, shift, frontSide);
					}
					break;
				case VKEY::KEY_END:
					{
						TextPos newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretLineLast, frontSide);
						if(newCaret==currentCaret)
						{
							newCaret=documentElement->CalculateCaret(currentCaret, IGuiGraphicsParagraph::CaretLast, frontSide);
						}
						Move(newCaret, shift, frontSide);
					}
					break;
				case VKEY::KEY_PRIOR:
					{
					}
					break;
				case VKEY::KEY_NEXT:
					{
					}
					break;
				case VKEY::KEY_BACK:
					if(editMode==Editable)
					{
						if(begin==end)
						{
							ProcessKey(VKEY::KEY_LEFT, true, false);
						}
						Array<WString> text;
						EditText(documentElement->GetCaretBegin(), documentElement->GetCaretEnd(), documentElement->IsCaretEndPreferFrontSide(), text);
						return true;
					}
					break;
				case VKEY::KEY_DELETE:
					if(editMode==Editable)
					{
						if(begin==end)
						{
							ProcessKey(VKEY::KEY_RIGHT, true, false);
						}
						Array<WString> text;
						EditText(documentElement->GetCaretBegin(), documentElement->GetCaretEnd(), documentElement->IsCaretEndPreferFrontSide(), text);
						return true;
					}
					break;
				case VKEY::KEY_RETURN:
					if(editMode==Editable)
					{
						if(ctrl)
						{
							Array<WString> text(1);
							text[0]=L"\r\n";
							EditText(documentElement->GetCaretBegin(), documentElement->GetCaretEnd(), documentElement->IsCaretEndPreferFrontSide(), text);
						}
						else
						{
							Array<WString> text(2);
							EditText(documentElement->GetCaretBegin(), documentElement->GetCaretEnd(), documentElement->IsCaretEndPreferFrontSide(), text);
						}
						return true;
					}
					break;
				default:;
				}
				return false;
			}

			void GuiDocumentCommonInterface::InstallDocumentViewer(
				GuiControl* _sender,
				compositions::GuiGraphicsComposition* _mouseArea,
				compositions::GuiGraphicsComposition* _container,
				compositions::GuiGraphicsComposition* eventComposition,
				compositions::GuiGraphicsComposition* focusableComposition
			)
			{
				documentControl = _sender;

				documentElement = GuiDocumentElement::Create();
				documentElement->SetCallback(this);

				documentComposition = new GuiBoundsComposition;
				documentComposition->SetOwnedElement(Ptr(documentElement));
				documentComposition->SetMinSizeLimitation(GuiGraphicsComposition::LimitToElement);
				documentComposition->SetAlignmentToParent(Margin(5, 5, 5, 5));
				_container->AddChild(documentComposition);
				ReplaceMouseArea(_mouseArea);

				focusableComposition->GetEventReceiver()->caretNotify.AttachMethod(this, &GuiDocumentCommonInterface::OnCaretNotify);
				focusableComposition->GetEventReceiver()->gotFocus.AttachMethod(this, &GuiDocumentCommonInterface::OnGotFocus);
				focusableComposition->GetEventReceiver()->lostFocus.AttachMethod(this, &GuiDocumentCommonInterface::OnLostFocus);
				focusableComposition->GetEventReceiver()->keyDown.AttachMethod(this, &GuiDocumentCommonInterface::OnKeyDown);
				focusableComposition->GetEventReceiver()->charInput.AttachMethod(this, &GuiDocumentCommonInterface::OnCharInput);

				undoRedoProcessor->Setup(documentElement, documentComposition);
				ActiveHyperlinkChanged.SetAssociatedComposition(eventComposition);
				ActiveHyperlinkExecuted.SetAssociatedComposition(eventComposition);
				SelectionChanged.SetAssociatedComposition(eventComposition);
				UndoRedoChanged.SetAssociatedComposition(eventComposition);
				ModifiedChanged.SetAssociatedComposition(eventComposition);

				undoRedoProcessor->UndoRedoChanged.Add(this, &GuiDocumentCommonInterface::InvokeUndoRedoChanged);
				undoRedoProcessor->ModifiedChanged.Add(this, &GuiDocumentCommonInterface::InvokeModifiedChanged);
				SetDocument(Ptr(new DocumentModel));
			}

			void GuiDocumentCommonInterface::ReplaceMouseArea(compositions::GuiGraphicsComposition* _mouseArea)
			{
				if (documentMouseArea)
				{
					documentMouseArea->GetEventReceiver()->mouseMove.Detach(onMouseMoveHandler);
					documentMouseArea->GetEventReceiver()->leftButtonDown.Detach(onMouseDownHandler);
					documentMouseArea->GetEventReceiver()->leftButtonUp.Detach(onMouseUpHandler);
					documentMouseArea->GetEventReceiver()->mouseLeave.Detach(onMouseLeaveHandler);

					onMouseMoveHandler = nullptr;
					onMouseDownHandler = nullptr;
					onMouseUpHandler = nullptr;
					onMouseLeaveHandler = nullptr;
				}
				documentMouseArea = _mouseArea;
				if (documentMouseArea)
				{
					onMouseMoveHandler = documentMouseArea->GetEventReceiver()->mouseMove.AttachMethod(this, &GuiDocumentCommonInterface::OnMouseMove);
					onMouseDownHandler = documentMouseArea->GetEventReceiver()->leftButtonDown.AttachMethod(this, &GuiDocumentCommonInterface::OnMouseDown);
					onMouseUpHandler = documentMouseArea->GetEventReceiver()->leftButtonUp.AttachMethod(this, &GuiDocumentCommonInterface::OnMouseUp);
					onMouseLeaveHandler = documentMouseArea->GetEventReceiver()->mouseLeave.AttachMethod(this, &GuiDocumentCommonInterface::OnMouseLeave);
				}
			}

			void GuiDocumentCommonInterface::SetActiveHyperlink(Ptr<DocumentHyperlinkRun::Package> package)
			{
				ActivateActiveHyperlink(false);
				activeHyperlinks =
					!package ? nullptr :
					package->hyperlinks.Count() == 0 ? nullptr :
					package;
				ActivateActiveHyperlink(true);
				ActiveHyperlinkChanged.Execute(documentControl->GetNotifyEventArguments());
			}

			void GuiDocumentCommonInterface::ActivateActiveHyperlink(bool activate)
			{
				if (activeHyperlinks)
				{
					for (auto run : activeHyperlinks->hyperlinks)
					{
						run->styleName = activate ? run->activeStyleName : run->normalStyleName;
					}
					documentElement->NotifyParagraphUpdated(activeHyperlinks->row, 1, 1, false);
				}
			}

			void GuiDocumentCommonInterface::AddShortcutCommand(VKEY key, const Func<void()>& eventHandler)
			{
				IGuiShortcutKeyItem* item=internalShortcutKeyManager->CreateNewShortcut(true, false, false, key);
				item->Executed.AttachLambda([=](GuiGraphicsComposition* sender, GuiEventArgs& arguments)
				{
					eventHandler();
				});
			}

			void GuiDocumentCommonInterface::EditTextInternal(TextPos begin, TextPos end, const Func<void(TextPos, TextPos, vint&, vint&)>& editor)
			{
				// save run before editing
				if(begin>end)
				{
					TextPos temp=begin;
					begin=end;
					end=temp;
				}
				Ptr<DocumentModel> originalModel=documentElement->GetDocument()->CopyDocument(begin, end, true);
				if(originalModel)
				{
					// edit
					vint paragraphCount=0;
					vint lastParagraphLength=0;
					editor(begin, end, paragraphCount, lastParagraphLength);

					// calculate new caret
					TextPos caret;
					if(paragraphCount==0)
					{
						caret=begin;
					}
					else if(paragraphCount==1)
					{
						caret=TextPos(begin.row, begin.column+lastParagraphLength);
					}
					else
					{
						caret=TextPos(begin.row+paragraphCount-1, lastParagraphLength);
					}
					documentElement->SetCaret(caret, caret, true);
					EnsureDocumentRectVisible(documentElement->GetCaretBounds(caret, true));
					documentControl->TextChanged.Execute(documentControl->GetNotifyEventArguments());
					UpdateCaretPoint();
					SelectionChanged.Execute(documentControl->GetNotifyEventArguments());

					// save run after editing
					Ptr<DocumentModel> inputModel=documentElement->GetDocument()->CopyDocument(begin, caret, true);

					// submit redo-undo
					GuiDocumentUndoRedoProcessor::ReplaceModelStruct arguments;
					arguments.originalStart=begin;
					arguments.originalEnd=end;
					arguments.originalModel=originalModel;
					arguments.inputStart=begin;
					arguments.inputEnd=caret;
					arguments.inputModel=inputModel;
					undoRedoProcessor->OnReplaceModel(arguments);
				}
			}

			void GuiDocumentCommonInterface::EditStyleInternal(TextPos begin, TextPos end, const Func<void(TextPos, TextPos)>& editor)
			{
				// save run before editing
				if(begin>end)
				{
					TextPos temp=begin;
					begin=end;
					end=temp;
				}
				Ptr<DocumentModel> originalModel=documentElement->GetDocument()->CopyDocument(begin, end, true);
				if(originalModel)
				{
					// edit
					editor(begin, end);

					// save run after editing
					Ptr<DocumentModel> inputModel=documentElement->GetDocument()->CopyDocument(begin, end, true);

					// submit redo-undo
					GuiDocumentUndoRedoProcessor::ReplaceModelStruct arguments;
					arguments.originalStart=begin;
					arguments.originalEnd=end;
					arguments.originalModel=originalModel;
					arguments.inputStart=begin;
					arguments.inputEnd=end;
					arguments.inputModel=inputModel;
					undoRedoProcessor->OnReplaceModel(arguments);
				}
			}

			void GuiDocumentCommonInterface::MergeBaselineAndDefaultFont(Ptr<DocumentModel> document)
			{
				document->MergeDefaultFont(documentControl->GetDisplayFont());
				if (baselineDocument)
				{
					document->MergeBaselineStyles(baselineDocument);
				}
			}

			void GuiDocumentCommonInterface::OnFontChanged()
			{
				auto document = documentElement->GetDocument();
				MergeBaselineAndDefaultFont(document);
				documentElement->SetDocument(document);
			}

			void GuiDocumentCommonInterface::OnCaretNotify(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
			{
				if(documentControl->GetVisuallyEnabled())
				{
					if(editMode!=ViewOnly)
					{
						documentElement->SetCaretVisible(!documentElement->GetCaretVisible());
					}
				}
			}

			void GuiDocumentCommonInterface::OnGotFocus(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
			{
				if(documentControl->GetVisuallyEnabled())
				{
					if(editMode!=ViewOnly)
					{
						documentElement->SetCaretVisible(true);
						UpdateCaretPoint();
					}
				}
			}

			void GuiDocumentCommonInterface::OnLostFocus(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
			{
				if(documentControl->GetVisuallyEnabled())
				{
					documentElement->SetCaretVisible(false);
				}
			}

			void GuiDocumentCommonInterface::OnKeyDown(compositions::GuiGraphicsComposition* sender, compositions::GuiKeyEventArgs& arguments)
			{
				if(documentControl->GetVisuallyEnabled())
				{
					if(editMode!=ViewOnly)
					{
						if(ProcessKey(arguments.code, arguments.shift, arguments.ctrl))
						{
							arguments.handled=true;
						}
					}
				}
			}

			void GuiDocumentCommonInterface::OnCharInput(compositions::GuiGraphicsComposition* sender, compositions::GuiCharEventArgs& arguments)
			{
				if (documentControl->GetVisuallyEnabled())
				{
					if (editMode == Editable &&
						arguments.code != (wchar_t)VKEY::KEY_ESCAPE &&
						arguments.code != (wchar_t)VKEY::KEY_BACK &&
						arguments.code != (wchar_t)VKEY::KEY_RETURN &&
						(arguments.code != (wchar_t)VKEY::KEY_TAB || documentControl->GetAcceptTabInput()) &&
						!arguments.ctrl)
					{
						Array<WString> text(1);
						text[0] = WString::FromChar(arguments.code);
						EditText(documentElement->GetCaretBegin(), documentElement->GetCaretEnd(), documentElement->IsCaretEndPreferFrontSide(), text);
					}
				}
			}

			void GuiDocumentCommonInterface::UpdateCursor(INativeCursor* cursor)
			{
				if (documentMouseArea)
				{
					documentMouseArea->SetAssociatedCursor(cursor);
				}
			}

			Point GuiDocumentCommonInterface::GetMouseOffset()
			{
				if (documentMouseArea)
				{
					auto documentBounds = documentComposition->GetGlobalBounds();
					auto mouseAreaBounds = documentMouseArea->GetGlobalBounds();
					return Point(
						documentBounds.x1 - mouseAreaBounds.x1,
						documentBounds.y1 - mouseAreaBounds.y1
					);
				}
				else
				{
					return Point(0, 0);
				}
			}

			void GuiDocumentCommonInterface::OnMouseMove(compositions::GuiGraphicsComposition* sender, compositions::GuiMouseEventArgs& arguments)
			{
				auto offset = GetMouseOffset();
				auto x = arguments.x - offset.x;
				auto y = arguments.y - offset.y;

				if(documentControl->GetVisuallyEnabled())
				{
					switch(editMode)
					{
					case ViewOnly:
						{
							auto package = documentElement->GetHyperlinkFromPoint({ x, y });
							bool handCursor = false;

							if(dragging)
							{
								if(activeHyperlinks)
								{
									if (package && CompareEnumerable(activeHyperlinks->hyperlinks, package->hyperlinks) == 0)
									{
										ActivateActiveHyperlink(true);
										handCursor = true;
									}
									else
									{
										ActivateActiveHyperlink(false);
									}
								}
							}
							else
							{
								SetActiveHyperlink(package);
								handCursor = activeHyperlinks;
							}

							if(handCursor)
							{
								auto cursor = GetCurrentController()->ResourceService()->GetSystemCursor(INativeCursor::Hand);
								UpdateCursor(cursor);
							}
							else
							{
								UpdateCursor(nullptr);
							}
						}
						break;
					case Selectable:
					case Editable:
						if(dragging)
						{
							TextPos caret=documentElement->CalculateCaretFromPoint(Point(x, y));
							TextPos oldCaret=documentElement->GetCaretBegin();
							Move(caret, true, (oldCaret==caret?documentElement->IsCaretEndPreferFrontSide():caret<oldCaret));
						}
						break;
					}
				}
			}

			void GuiDocumentCommonInterface::OnMouseDown(compositions::GuiGraphicsComposition* sender, compositions::GuiMouseEventArgs& arguments)
			{
				auto offset = GetMouseOffset();
				auto x = arguments.x - offset.x;
				auto y = arguments.y - offset.y;

				if(documentControl->GetVisuallyEnabled())
				{
					switch(editMode)
					{
					case ViewOnly:
						SetActiveHyperlink(documentElement->GetHyperlinkFromPoint({ x, y }));
						break;
					case Selectable:
					case Editable:
						{
							documentControl->SetFocused();
							TextPos caret=documentElement->CalculateCaretFromPoint(Point(x, y));
							TextPos oldCaret=documentElement->GetCaretEnd();
							if(caret!=oldCaret)
							{
								Move(caret, arguments.shift, caret<oldCaret);
							}
						}
						break;
					}
					dragging=true;
				}
			}

			void GuiDocumentCommonInterface::OnMouseUp(compositions::GuiGraphicsComposition* sender, compositions::GuiMouseEventArgs& arguments)
			{
				auto offset = GetMouseOffset();
				auto x = arguments.x - offset.x;
				auto y = arguments.y - offset.y;

				if(documentControl->GetVisuallyEnabled())
				{
					dragging=false;
					switch(editMode)
					{
					case ViewOnly:
						{
							auto package = documentElement->GetHyperlinkFromPoint({ x, y });
							if(activeHyperlinks)
							{
								if (package && CompareEnumerable(activeHyperlinks->hyperlinks, package->hyperlinks) == 0)
								{
									ActiveHyperlinkExecuted.Execute(documentControl->GetNotifyEventArguments());
								}
								else
								{
									SetActiveHyperlink(nullptr);
								}
							}
						}
						break;
					default:;
					}
				}
			}

			void GuiDocumentCommonInterface::OnMouseLeave(compositions::GuiGraphicsComposition* sender, compositions::GuiEventArgs& arguments)
			{
				SetActiveHyperlink(nullptr);
			}

			Point GuiDocumentCommonInterface::GetDocumentViewPosition()
			{
				return Point(0, 0);
			}

			void GuiDocumentCommonInterface::EnsureRectVisible(Rect bounds)
			{
			}

			//================ callback

			void GuiDocumentCommonInterface::OnStartRender()
			{
				for (auto item : documentItems.Values())
				{
					item->visible = false;
				}
			}

			void GuiDocumentCommonInterface::OnFinishRender()
			{
				for (auto item : documentItems.Values())
				{
					if (item->container->GetVisible() != item->visible)
					{
						item->container->SetVisible(item->visible);
					}
				}
			}

			Size GuiDocumentCommonInterface::OnRenderEmbeddedObject(const WString& name, const Rect& location)
			{
				vint index = documentItems.Keys().IndexOf(name);
				if (index != -1)
				{
					auto item = documentItems.Values()[index];
					auto size = item->container->GetCachedBounds().GetSize();
					item->container->SetExpectedBounds(Rect(location.LeftTop(), Size(0, 0)));
					item->visible = true;
					return size;
				}
				return Size();
			}

			//================ basic

			GuiDocumentCommonInterface::GuiDocumentCommonInterface()
			{
				undoRedoProcessor = Ptr(new GuiDocumentUndoRedoProcessor);

				internalShortcutKeyManager = Ptr(new GuiShortcutKeyManager);
				AddShortcutCommand(VKEY::KEY_Z, Func<bool()>(this, &GuiDocumentCommonInterface::Undo));
				AddShortcutCommand(VKEY::KEY_Y, Func<bool()>(this, &GuiDocumentCommonInterface::Redo));
				AddShortcutCommand(VKEY::KEY_A, Func<void()>(this, &GuiDocumentCommonInterface::SelectAll));
				AddShortcutCommand(VKEY::KEY_X, Func<bool()>(this, &GuiDocumentCommonInterface::Cut));
				AddShortcutCommand(VKEY::KEY_C, Func<bool()>(this, &GuiDocumentCommonInterface::Copy));
				AddShortcutCommand(VKEY::KEY_V, Func<bool()>(this, &GuiDocumentCommonInterface::Paste));
			}

			GuiDocumentCommonInterface::~GuiDocumentCommonInterface()
			{
			}

			Ptr<DocumentModel> GuiDocumentCommonInterface::GetDocument()
			{
				return documentElement->GetDocument();
			}

			void GuiDocumentCommonInterface::SetDocument(Ptr<DocumentModel> value)
			{
				SetActiveHyperlink(0);
				ClearUndoRedo();
				NotifyModificationSaved();

				if (value)
				{
					if (value->paragraphs.Count() == 0)
					{
						value->paragraphs.Add(Ptr(new DocumentParagraphRun));
					}
					MergeBaselineAndDefaultFont(value);
				}

				documentElement->SetDocument(value);
			}

			//================ document items

			bool GuiDocumentCommonInterface::AddDocumentItem(Ptr<GuiDocumentItem> value)
			{
				if (documentItems.Keys().Contains(value->GetName()))
				{
					return false;
				}
				documentItems.Add(value->GetName(), value);
				documentComposition->AddChild(value->container);
				value->visible = false;
				value->owned = true;
				value->container->SetVisible(false);
				return true;
			}

			bool GuiDocumentCommonInterface::RemoveDocumentItem(Ptr<GuiDocumentItem> value)
			{
				vint index = documentItems.Keys().IndexOf(value->GetName());
				if (index == -1)
				{
					return false;
				}
				if (documentItems.Values()[index] != value)
				{
					return false;
				}
				value->owned = false;
				documentComposition->RemoveChild(value->container);
				documentItems.Remove(value->GetName());
				return true;
			}

			const GuiDocumentCommonInterface::DocumentItemMap& GuiDocumentCommonInterface::GetDocumentItems()
			{
				return documentItems;
			}

			//================ caret operations

			TextPos GuiDocumentCommonInterface::GetCaretBegin()
			{
				return documentElement->GetCaretBegin();
			}

			TextPos GuiDocumentCommonInterface::GetCaretEnd()
			{
				return documentElement->GetCaretEnd();
			}

			void GuiDocumentCommonInterface::SetCaret(TextPos begin, TextPos end)
			{
				documentElement->SetCaret(begin, end, end>=begin);
				UpdateCaretPoint();
				SelectionChanged.Execute(documentControl->GetNotifyEventArguments());
			}

			TextPos GuiDocumentCommonInterface::CalculateCaretFromPoint(Point point)
			{
				return documentElement->CalculateCaretFromPoint(point);
			}

			Rect GuiDocumentCommonInterface::GetCaretBounds(TextPos caret, bool frontSide)
			{
				return documentElement->GetCaretBounds(caret, frontSide);
			}

			//================ editing operations

			void GuiDocumentCommonInterface::NotifyParagraphUpdated(vint index, vint oldCount, vint newCount, bool updatedText)
			{
				documentElement->NotifyParagraphUpdated(index, oldCount, newCount, updatedText);
			}

			void GuiDocumentCommonInterface::EditRun(TextPos begin, TextPos end, Ptr<DocumentModel> model, bool copy)
			{
				EditTextInternal(begin, end, [=, this](TextPos begin, TextPos end, vint& paragraphCount, vint& lastParagraphLength)
				{
					documentElement->EditRun(begin, end, model, copy);
					paragraphCount=model->paragraphs.Count();
					lastParagraphLength=paragraphCount==0?0:model->paragraphs[paragraphCount-1]->GetText(false).Length();
				});
			}

			void GuiDocumentCommonInterface::EditText(TextPos begin, TextPos end, bool frontSide, const collections::Array<WString>& text)
			{
				EditTextInternal(begin, end, [=, this, &text](TextPos begin, TextPos end, vint& paragraphCount, vint& lastParagraphLength)
				{
					documentElement->EditText(begin, end, frontSide, text);
					paragraphCount=text.Count();
					lastParagraphLength=paragraphCount==0?0:text[paragraphCount-1].Length();
				});
			}

			void GuiDocumentCommonInterface::EditStyle(TextPos begin, TextPos end, Ptr<DocumentStyleProperties> style)
			{
				EditStyleInternal(begin, end, [=, this](TextPos begin, TextPos end)
				{
					documentElement->EditStyle(begin, end, style);
				});
			}

			void GuiDocumentCommonInterface::EditImage(TextPos begin, TextPos end, Ptr<GuiImageData> image)
			{
				EditTextInternal(begin, end, [=, this](TextPos begin, TextPos end, vint& paragraphCount, vint& lastParagraphLength)
				{
					documentElement->EditImage(begin, end, image);
					paragraphCount=1;
					lastParagraphLength=wcslen(DocumentImageRun::RepresentationText);
				});
			}

			void GuiDocumentCommonInterface::EditHyperlink(vint paragraphIndex, vint begin, vint end, const WString& reference, const WString& normalStyleName, const WString& activeStyleName)
			{
				EditStyleInternal(TextPos(paragraphIndex, begin), TextPos(paragraphIndex, end), [=, this](TextPos begin, TextPos end)
				{
					documentElement->EditHyperlink(begin.row, begin.column, end.column, reference, normalStyleName, activeStyleName);
				});
			}

			void GuiDocumentCommonInterface::RemoveHyperlink(vint paragraphIndex, vint begin, vint end)
			{
				EditStyleInternal(TextPos(paragraphIndex, begin), TextPos(paragraphIndex, end), [=, this](TextPos begin, TextPos end)
				{
					documentElement->RemoveHyperlink(begin.row, begin.column, end.column);
				});
			}

			void GuiDocumentCommonInterface::EditStyleName(TextPos begin, TextPos end, const WString& styleName)
			{
				EditStyleInternal(begin, end, [=, this](TextPos begin, TextPos end)
				{
					documentElement->EditStyleName(begin, end, styleName);
				});
			}

			void GuiDocumentCommonInterface::RemoveStyleName(TextPos begin, TextPos end)
			{
				EditStyleInternal(begin, end, [=, this](TextPos begin, TextPos end)
				{
					documentElement->RemoveStyleName(begin, end);
				});
			}

			void GuiDocumentCommonInterface::RenameStyle(const WString& oldStyleName, const WString& newStyleName)
			{
				documentElement->RenameStyle(oldStyleName, newStyleName);

				// submit redo-undo
				GuiDocumentUndoRedoProcessor::RenameStyleStruct arguments;
				arguments.oldStyleName=oldStyleName;
				arguments.newStyleName=newStyleName;
				undoRedoProcessor->OnRenameStyle(arguments);
			}

			void GuiDocumentCommonInterface::ClearStyle(TextPos begin, TextPos end)
			{
				EditStyleInternal(begin, end, [=, this](TextPos begin, TextPos end)
				{
					documentElement->ClearStyle(begin, end);
				});
			}

			Ptr<DocumentStyleProperties> GuiDocumentCommonInterface::SummarizeStyle(TextPos begin, TextPos end)
			{
				if (begin>end)
				{
					TextPos temp = begin;
					begin = end;
					end = temp;
				}
				return documentElement->SummarizeStyle(begin, end);
			}

			Nullable<WString> GuiDocumentCommonInterface::SummarizeStyleName(TextPos begin, TextPos end)
			{
				if (begin>end)
				{
					TextPos temp = begin;
					begin = end;
					end = temp;
				}
				return documentElement->SummarizeStyleName(begin, end);
			}

			void GuiDocumentCommonInterface::SetParagraphAlignments(TextPos begin, TextPos end, const collections::Array<Nullable<Alignment>>& alignments)
			{
				vint first = begin.row;
				vint last = end.row;
				if (first > last)
				{
					vint temp = first;
					first = last;
					last = temp;
				}

				Ptr<DocumentModel> document = documentElement->GetDocument();
				if (0 <= first && first < document->paragraphs.Count() && 0 <= last && last < document->paragraphs.Count() && last - first + 1 == alignments.Count())
				{
					auto arguments = Ptr(new GuiDocumentUndoRedoProcessor::SetAlignmentStruct);
					arguments->start = first;
					arguments->end = last;
					arguments->originalAlignments.Resize(alignments.Count());
					arguments->inputAlignments.Resize(alignments.Count());
					for (vint i = first; i <= last; i++)
					{
						arguments->originalAlignments[i - first] = document->paragraphs[i]->alignment;
						arguments->inputAlignments[i - first] = alignments[i - first];
					}
					documentElement->SetParagraphAlignment(begin, end, alignments);
					undoRedoProcessor->OnSetAlignment(arguments);
				}
			}

			void GuiDocumentCommonInterface::SetParagraphAlignment(TextPos begin, TextPos end, Nullable<Alignment> alignment)
			{
#if defined VCZH_GCC && defined VCZH_64
#define abs labs
#endif
				Array<Nullable<Alignment>> alignments(abs(begin.row - end.row) + 1);
#if defined VCZH_GCC && defined VCZH_64
#undef abs
#endif
				for (vint i = 0; i < alignments.Count(); i++)
				{
					alignments[i] = alignment;
				}
				SetParagraphAlignments(begin, end, alignments);
			}

			Nullable<Alignment> GuiDocumentCommonInterface::SummarizeParagraphAlignment(TextPos begin, TextPos end)
			{
				if (begin>end)
				{
					TextPos temp = begin;
					begin = end;
					end = temp;
				}
				return documentElement->SummarizeParagraphAlignment(begin, end);
			}

			//================ editing control

			WString GuiDocumentCommonInterface::GetActiveHyperlinkReference()
			{
				return activeHyperlinks ? activeHyperlinks->hyperlinks[0]->reference : L"";
			}

			GuiDocumentCommonInterface::EditMode GuiDocumentCommonInterface::GetEditMode()
			{
				return editMode;
			}

			void GuiDocumentCommonInterface::SetEditMode(EditMode value)
			{
				if(activeHyperlinks)
				{
					SetActiveHyperlink(nullptr);
				}

				editMode=value;
				if(editMode==ViewOnly)
				{
					UpdateCursor(nullptr);
				}
				else
				{
					INativeCursor* cursor=GetCurrentController()->ResourceService()->GetSystemCursor(INativeCursor::IBeam);
					UpdateCursor(cursor);
				}
			}

			//================ selection operations

			void GuiDocumentCommonInterface::SelectAll()
			{
				vint lastIndex=documentElement->GetDocument()->paragraphs.Count()-1;
				Ptr<DocumentParagraphRun> lastParagraph=documentElement->GetDocument()->paragraphs[lastIndex];

				TextPos begin(0, 0);
				TextPos end(lastIndex, lastParagraph->GetText(false).Length());
				SetCaret(begin, end);
			}

			WString GuiDocumentCommonInterface::GetSelectionText()
			{
				TextPos begin=documentElement->GetCaretBegin();
				TextPos end=documentElement->GetCaretEnd();
				if(begin>end)
				{
					TextPos temp=begin;
					begin=end;
					end=temp;
				}

				Ptr<DocumentModel> model=documentElement->GetDocument()->CopyDocument(begin, end, false);
				return model->GetText(true);
			}

			void GuiDocumentCommonInterface::SetSelectionText(const WString& value)
			{
				List<WString> paragraphs;
				{
					stream::StringReader reader(value);
					WString paragraph;
					bool empty=true;

					while(!reader.IsEnd())
					{
						WString line=reader.ReadLine();
						if(empty)
						{
							paragraph+=line;
							empty=false;
						}
						else if(line!=L"")
						{
							paragraph+=L"\r\n"+line;
						}
						else
						{
							paragraphs.Add(paragraph);
							paragraph=L"";
							empty=true;
						}
					}

					if(!empty)
					{
						paragraphs.Add(paragraph);
					}
				}

				TextPos begin=documentElement->GetCaretBegin();
				TextPos end=documentElement->GetCaretEnd();
				if(begin>end)
				{
					TextPos temp=begin;
					begin=end;
					end=temp;
				}

				Array<WString> text;
				CopyFrom(text, paragraphs);
				EditText(begin, end, documentElement->IsCaretEndPreferFrontSide(), text);
			}

			Ptr<DocumentModel> GuiDocumentCommonInterface::GetSelectionModel()
			{
				TextPos begin=documentElement->GetCaretBegin();
				TextPos end=documentElement->GetCaretEnd();
				if(begin>end)
				{
					TextPos temp=begin;
					begin=end;
					end=temp;
				}

				Ptr<DocumentModel> model=documentElement->GetDocument()->CopyDocument(begin, end, true);
				return model;
			}

			void GuiDocumentCommonInterface::SetSelectionModel(Ptr<DocumentModel> value)
			{
				TextPos begin=documentElement->GetCaretBegin();
				TextPos end=documentElement->GetCaretEnd();
				if(begin>end)
				{
					TextPos temp=begin;
					begin=end;
					end=temp;
				}

				EditRun(begin, end, value, true);
			}

			//================ clipboard operations

			bool GuiDocumentCommonInterface::CanCut()
			{
				return editMode==Editable && documentElement->GetCaretBegin()!=documentElement->GetCaretEnd();
			}

			bool GuiDocumentCommonInterface::CanCopy()
			{
				return documentElement->GetCaretBegin()!=documentElement->GetCaretEnd();
			}

			bool GuiDocumentCommonInterface::CanPaste()
			{
				if (editMode == Editable)
				{
					auto reader = GetCurrentController()->ClipboardService()->ReadClipboard();
					return reader->ContainsText() || reader->ContainsDocument() || reader->ContainsImage();
				}
				return false;
			}

			bool GuiDocumentCommonInterface::Cut()
			{
				if (!CanCut())return false;
				auto writer = GetCurrentController()->ClipboardService()->WriteClipboard();
				auto model = GetSelectionModel();
				writer->SetDocument(model);
				writer->Submit();
				SetSelectionText(L"");
				return true;
			}

			bool GuiDocumentCommonInterface::Copy()
			{
				if (!CanCopy()) return false;
				auto writer = GetCurrentController()->ClipboardService()->WriteClipboard();
				auto model = GetSelectionModel();
				writer->SetDocument(model);
				writer->Submit();
				return true;
			}

			bool GuiDocumentCommonInterface::Paste()
			{
				if (!CanPaste()) return false;
				auto reader = GetCurrentController()->ClipboardService()->ReadClipboard();
				if (reader->ContainsDocument())
				{
					if (auto document = reader->GetDocument())
					{
						SetSelectionModel(document);
						return true;
					}
				}
				if (reader->ContainsText())
				{
					SetSelectionText(reader->GetText());
					return true;
				}
				if (reader->ContainsImage())
				{
					if (auto image = reader->GetImage())
					{
						auto imageData = Ptr(new GuiImageData(image, 0));
						EditImage(GetCaretBegin(), GetCaretEnd(), imageData);
						return true;
					}
				}
				return false;
			}

			//================ undo redo control

			bool GuiDocumentCommonInterface::CanUndo()
			{
				return editMode==Editable && undoRedoProcessor->CanUndo();
			}

			bool GuiDocumentCommonInterface::CanRedo()
			{
				return editMode==Editable && undoRedoProcessor->CanRedo();
			}

			void GuiDocumentCommonInterface::ClearUndoRedo()
			{
				undoRedoProcessor->ClearUndoRedo();
			}

			bool GuiDocumentCommonInterface::GetModified()
			{
				return undoRedoProcessor->GetModified();
			}

			void GuiDocumentCommonInterface::NotifyModificationSaved()
			{
				undoRedoProcessor->NotifyModificationSaved();
			}

			bool GuiDocumentCommonInterface::Undo()
			{
				if(CanUndo())
				{
					return undoRedoProcessor->Undo();
				}
				else
				{
					return false;
				}
			}

			bool GuiDocumentCommonInterface::Redo()
			{
				if(CanRedo())
				{
					return undoRedoProcessor->Redo();
				}
				else
				{
					return false;
				}
			}

/***********************************************************************
GuiDocumentViewer
***********************************************************************/

			void GuiDocumentViewer::BeforeControlTemplateUninstalled_()
			{
				ReplaceMouseArea(nullptr);
			}

			void GuiDocumentViewer::AfterControlTemplateInstalled_(bool initialize)
			{
				auto ct = TypedControlTemplateObject(true);
				baselineDocument = ct->GetBaselineDocument();
				if (documentElement)
				{
					documentElement->SetCaretColor(ct->GetCaretColor());
					SetDocument(GetDocument());
				}
				ReplaceMouseArea(containerComposition->GetParent());
			}

			void GuiDocumentViewer::UpdateDisplayFont()
			{
				GuiScrollContainer::UpdateDisplayFont();
				OnFontChanged();
			}

			Point GuiDocumentViewer::GetDocumentViewPosition()
			{
				return GetViewBounds().LeftTop();
			}

			void GuiDocumentViewer::EnsureRectVisible(Rect bounds)
			{
				Rect viewBounds=GetViewBounds();
				vint offset=0;
				if(bounds.y1<viewBounds.y1)
				{
					offset=bounds.y1-viewBounds.y1;
				}
				else if(bounds.y2>viewBounds.y2)
				{
					offset=bounds.y2-viewBounds.y2;
				}

				if (auto scroll = GetVerticalScroll())
				{
					scroll->SetPosition(viewBounds.y1 + offset);
				}
			}

			GuiDocumentViewer::GuiDocumentViewer(theme::ThemeName themeName)
				:GuiScrollContainer(themeName)
			{
				SetAcceptTabInput(true);
				SetFocusableComposition(boundsComposition);
				InstallDocumentViewer(this, containerComposition->GetParent(), containerComposition, boundsComposition, focusableComposition);

				SetExtendToFullWidth(true);
				SetHorizontalAlwaysVisible(false);
			}

			GuiDocumentViewer::~GuiDocumentViewer()
			{
			}

			const WString& GuiDocumentViewer::GetText()
			{
				text=documentElement->GetDocument()->GetText(true);
				return text;
			}

			void GuiDocumentViewer::SetText(const WString& value)
			{
				SelectAll();
				SetSelectionText(value);
			}

/***********************************************************************
GuiDocumentLabel
***********************************************************************/

			void GuiDocumentLabel::BeforeControlTemplateUninstalled_()
			{
			}

			void GuiDocumentLabel::AfterControlTemplateInstalled_(bool initialize)
			{
				auto ct = TypedControlTemplateObject(true);
				baselineDocument = ct->GetBaselineDocument();
				if (documentElement)
				{
					documentElement->SetCaretColor(ct->GetCaretColor());
					SetDocument(GetDocument());
				}
			}

			void GuiDocumentLabel::UpdateDisplayFont()
			{
				GuiControl::UpdateDisplayFont();
				OnFontChanged();
			}

			GuiDocumentLabel::GuiDocumentLabel(theme::ThemeName themeName)
				:GuiControl(themeName)
			{
				SetAcceptTabInput(true);
				SetFocusableComposition(boundsComposition);
				InstallDocumentViewer(this, containerComposition, containerComposition, boundsComposition, focusableComposition);
			}

			GuiDocumentLabel::~GuiDocumentLabel()
			{
			}

			const WString& GuiDocumentLabel::GetText()
			{
				text=documentElement->GetDocument()->GetText(true);
				return text;
			}

			void GuiDocumentLabel::SetText(const WString& value)
			{
				SelectAll();
				SetSelectionText(value);
			}
		}
	}
}
