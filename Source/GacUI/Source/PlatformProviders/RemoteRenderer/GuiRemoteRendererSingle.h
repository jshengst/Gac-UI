/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Remote Window

Interfaces:
  GuiRemoteRendererSingle

***********************************************************************/

#ifndef VCZH_PRESENTATION_GUIREMOTECONTROLLER_REMOTERENDERER_GUIREMOTERENDERERSINGLE
#define VCZH_PRESENTATION_GUIREMOTECONTROLLER_REMOTERENDERER_GUIREMOTERENDERERSINGLE

#include "../Remote/GuiRemoteProtocol_Shared.h"
#include "../Remote/Protocol/FrameOperations/GuiRemoteProtocolSchema_FrameOperations.h"

namespace vl::presentation::remote_renderer
{
	class GuiRemoteRendererSingle
		: public Object
		, public virtual IGuiRemoteProtocol
		, protected virtual INativeWindowListener
		, protected virtual INativeControllerListener
	{
	protected:
		INativeWindow*							window = nullptr;
		INativeScreen*							screen = nullptr;
		IGuiRemoteProtocolEvents*				events = nullptr;
		bool									disconnectingFromCore = false;

		bool									updatingBounds = false;
		remoteprotocol::WindowSizingConfig		windowSizingConfig;
		NativeSize								suggestedMinSize;

		remoteprotocol::ScreenConfig			GetScreenConfig(INativeScreen* screen);
		remoteprotocol::WindowSizingConfig		GetWindowSizingConfig();
		void									UpdateConfigsIfNecessary();

		void									NativeWindowDestroying(INativeWindow* _window) override;

		void									Opened() override;
		void									BeforeClosing(bool& cancel) override;
		void									AfterClosing() override;
		void									Closed() override;

		void									Moving(NativeRect& bounds, bool fixSizeOnly, bool draggingBorder) override;
		void									Moved() override;
		void									DpiChanged(bool preparing) override;
		void									RenderingAsActivated() override;
		void									RenderingAsDeactivated() override;

	protected:
		using GlobalShortcutMap = collections::Dictionary<vint, remoteprotocol::GlobalShortcutKey>;

		GlobalShortcutMap						globalShortcuts;

		void									UnregisterGlobalShortcutKeys();
		void									GlobalShortcutKeyActivated(vint id) override;

	protected:
		struct SolidLabelMeasuring
		{
			remoteprotocol::ElementSolidLabelMeasuringRequest		request;
			Nullable<Size>											minSize;
		};

		using ElementMap = collections::Dictionary<vint, Ptr<elements::IGuiGraphicsElement>>;
		using ImageMap = collections::Dictionary<vint, Ptr<INativeImage>>;
		using SolidLabelMeasuringMap = collections::Dictionary<vint, SolidLabelMeasuring>;
		using FontHeightMeasuringSet = collections::SortedList<collections::Pair<WString, vint>>;

		remoteprotocol::ElementMeasurings		elementMeasurings;
		FontHeightMeasuringSet					fontHeightMeasurings;
		SolidLabelMeasuringMap					solidLabelMeasurings;

		ElementMap								availableElements;
		ImageMap								availableImages;
		Ptr<remoteprotocol::RenderingDom>		renderingDom;
		remoteprotocol::DomIndex				renderingDomIndex;

		Alignment								GetAlignment(remoteprotocol::ElementHorizontalAlignment alignment);
		Alignment								GetAlignment(remoteprotocol::ElementVerticalAlignment alignment);
		void									StoreLabelMeasuring(vint id, remoteprotocol::ElementSolidLabelMeasuringRequest request, Ptr<elements::GuiSolidLabelElement> solidLabel, Size minSize);
		remoteprotocol::ImageMetadata			CreateImageMetadata(vint id, INativeImage* image);
		remoteprotocol::ImageMetadata			CreateImage(const remoteprotocol::ImageCreation& arguments);
		void									CheckDom();

	protected:
		bool									supressPaint = false;
		bool									needRefresh = false;

		void									UpdateRenderTarget(elements::IGuiGraphicsRenderTarget* rt);
		void									Render(Ptr<remoteprotocol::RenderingDom> dom, elements::IGuiGraphicsRenderTarget* rt);
		void									HitTestInternal(Ptr<remoteprotocol::RenderingDom> dom, Point location, Nullable<INativeWindowListener::HitTestResult>& hitTestResult, Nullable<INativeCursor::SystemCursorType>& cursorType);
		void									HitTest(Ptr<remoteprotocol::RenderingDom> dom, Point location, INativeWindowListener::HitTestResult& hitTestResult, INativeCursor*& cursor);

		void									GlobalTimer() override;
		void									Paint() override;
		INativeWindowListener::HitTestResult	HitTest(NativePoint location) override;

	protected:

		void									LeftButtonDown(const NativeWindowMouseInfo& info) override;
		void									LeftButtonUp(const NativeWindowMouseInfo& info) override;
		void									LeftButtonDoubleClick(const NativeWindowMouseInfo& info) override;
		void									RightButtonDown(const NativeWindowMouseInfo& info) override;
		void									RightButtonUp(const NativeWindowMouseInfo& info) override;
		void									RightButtonDoubleClick(const NativeWindowMouseInfo& info) override;
		void									MiddleButtonDown(const NativeWindowMouseInfo& info) override;
		void									MiddleButtonUp(const NativeWindowMouseInfo& info) override;
		void									MiddleButtonDoubleClick(const NativeWindowMouseInfo& info) override;
		void									HorizontalWheel(const NativeWindowMouseInfo& info) override;
		void									VerticalWheel(const NativeWindowMouseInfo& info) override;
		void									MouseMoving(const NativeWindowMouseInfo& info) override;
		void									MouseEntered() override;
		void									MouseLeaved() override;
		void									KeyDown(const NativeWindowKeyInfo& info) override;
		void									KeyUp(const NativeWindowKeyInfo& info) override;
		void									Char(const NativeWindowCharInfo& info) override;

	public:
		GuiRemoteRendererSingle();
		~GuiRemoteRendererSingle();

		void									RegisterMainWindow(INativeWindow* _window);
		void									UnregisterMainWindow();
		void									ForceExitByFatelError();

		WString									GetExecutablePath() override;
		void									Initialize(IGuiRemoteProtocolEvents* _events) override;
		void									Submit(bool& disconnected) override;
		IGuiRemoteEventProcessor*				GetRemoteEventProcessor() override;


#define MESSAGE_NOREQ_NORES(NAME, REQUEST, RESPONSE)					void Request ## NAME() override;
#define MESSAGE_NOREQ_RES(NAME, REQUEST, RESPONSE)						void Request ## NAME(vint id) override;
#define MESSAGE_REQ_NORES(NAME, REQUEST, RESPONSE)						void Request ## NAME(const REQUEST& arguments) override;
#define MESSAGE_REQ_RES(NAME, REQUEST, RESPONSE)						void Request ## NAME(vint id, const REQUEST& arguments) override;
#define MESSAGE_HANDLER(NAME, REQUEST, RESPONSE, REQTAG, RESTAG, ...)	MESSAGE_ ## REQTAG ## _ ## RESTAG(NAME, REQUEST, RESPONSE)
		GACUI_REMOTEPROTOCOL_MESSAGES(MESSAGE_HANDLER)
#undef MESSAGE_HANDLER
#undef MESSAGE_REQ_RES
#undef MESSAGE_REQ_NORES
#undef MESSAGE_NOREQ_RES
#undef MESSAGE_NOREQ_NORES
	};
}

#endif