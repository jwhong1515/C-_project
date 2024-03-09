#include "frame.h"
#include "Component.h"
#include "Button.h"
#include "CheckBox.h"
#include <iostream>

// 어쩔 수 없이 전역 변수 1개는 사용한다.
Frame* theFrame = nullptr;

// 전역함수로는 윈도 메시지 처리 함수가 있다.
LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
{

	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONDBLCLK:
	case WM_RBUTTONUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_CHAR:
	case WM_SIZE:
		if (theFrame != nullptr)
			theFrame->eventHandler(MEvent(Msg, wParam, lParam));
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(Hw, &ps);

		// 그리기 코드는 이걸로 끝!
		if (theFrame != nullptr)
			theFrame->repaint(hdc); //이게 맞아? 여기 hdc 없었는데

		EndPaint(Hw, &ps);  // BeginPaint의 짝이 된다
		
	}
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

Frame::Frame() :Frame("", 800, 600) {
	// 현재 사용되지 않고 있음.
}

Frame::Frame(std::string title, int width, int height) : Container(title){
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hWnd_ = CreateWindowExA(WS_EX_TOPMOST, "MyWIn", title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // 종료 최소화 최대화 아이콘
		WS_THICKFRAME,  // resize가 가능하게
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_); 
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);

	invalidate();
}


// run 함수는 수정하면 위험함.
// run함수는 가상함수로 할 필요 없다. 이거 그냥 실행하면 되니깐
void Frame::run() {
	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

/*
bool Frame::eventHandler(MEvent e) { //Container꺼 그대로 사용

}
*/

/*
void Frame::repaint(HDC hdc) {
	Container::repaint(hdc);
}
*/

void Frame::invalidate() {
	// 이 메소드를 부르면 화면을 다시 그리게 된다.
	InvalidateRect(hWnd_, nullptr, true);
}

//가상함수인데 override해서 내가 필요한 initialize만 해주면 됨
void Frame::initialize() {
	//이 메소드를 부르면 화면을 다시 그리게 된다.
	InvalidateRect(hWnd_, nullptr, true);
}



//라이브러리
/*
Component* Frame::findComponent(MPoint p) {
	MyList<Component*>::iterator bi;
	for (bi = myComponentList.begin(); bi != myComponentList.end(); bi++) {
		if ((*bi)->isSelected(p)) {
			return *bi;
		}
	}
	return nullptr;
}
*/

HDC Frame::getDC() {
	return hDC_;
}

void Frame::setContentPane(Panel* p) {
	add(p);
	p->setBounds(0, 300, 1000, 600);
	panel_ = p;
}

Panel* Frame::getContentPane() {
	return panel_;
}

void Frame::addToolBar(ToolBar* tb) {
	add(tb);
}

ToolBar* Frame::getToolBar() {
	return toolBar_;
}

