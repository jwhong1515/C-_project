#include "frame.h"
#include "Component.h"
#include "Button.h"
#include "CheckBox.h"
#include <iostream>

// ��¿ �� ���� ���� ���� 1���� ����Ѵ�.
Frame* theFrame = nullptr;

// �����Լ��δ� ���� �޽��� ó�� �Լ��� �ִ�.
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

		// �׸��� �ڵ�� �̰ɷ� ��!
		if (theFrame != nullptr)
			theFrame->repaint(hdc); //�̰� �¾�? ���� hdc �����µ�

		EndPaint(Hw, &ps);  // BeginPaint�� ¦�� �ȴ�
		
	}
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

Frame::Frame() :Frame("", 800, 600) {
	// ���� ������ �ʰ� ����.
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
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // ���� �ּ�ȭ �ִ�ȭ ������
		WS_THICKFRAME,  // resize�� �����ϰ�
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_); 
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);

	invalidate();
}


// run �Լ��� �����ϸ� ������.
// run�Լ��� �����Լ��� �� �ʿ� ����. �̰� �׳� �����ϸ� �Ǵϱ�
void Frame::run() {
	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));

	MSG msg;

	// �⺻ �޽��� �����Դϴ�:
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
bool Frame::eventHandler(MEvent e) { //Container�� �״�� ���

}
*/

/*
void Frame::repaint(HDC hdc) {
	Container::repaint(hdc);
}
*/

void Frame::invalidate() {
	// �� �޼ҵ带 �θ��� ȭ���� �ٽ� �׸��� �ȴ�.
	InvalidateRect(hWnd_, nullptr, true);
}

//�����Լ��ε� override�ؼ� ���� �ʿ��� initialize�� ���ָ� ��
void Frame::initialize() {
	//�� �޼ҵ带 �θ��� ȭ���� �ٽ� �׸��� �ȴ�.
	InvalidateRect(hWnd_, nullptr, true);
}



//���̺귯��
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

