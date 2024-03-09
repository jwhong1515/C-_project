#pragma once
#include "Windows.h"
#include <iostream>
#include <string>
#include <list>
//#include <vector>
#include "Container.h"
#include "Panel.h"
#include "ToolBar.h"
#include "Misc.h"
#include "MyList.h"
using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Component;
class Frame : public Container {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;	 // 윈도 핸들을 저장해둔다.
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.

	Panel* panel_;
	ToolBar* toolBar_;

public:
	Frame();
	Frame(std::string, int, int);
	void run(); //가상함수로 할 필요 없다.
	//virtual bool eventHandler(MEvent e);
	//void repaint(HDC hdc) override;
	virtual void invalidate();
	virtual void initialize();

	//void drawComponents();
	//Component* findComponent(MPoint p);
	HDC getDC();

	void setContentPane(Panel* p);
	Panel* getContentPane();
	void addToolBar(ToolBar* tb);
	ToolBar* getToolBar();

};