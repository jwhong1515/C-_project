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
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;	 // ���� �ڵ��� �����صд�.
	HDC hDC_;    // �� ������ �־�� �׸��� �׸� �� �ִ�.

	Panel* panel_;
	ToolBar* toolBar_;

public:
	Frame();
	Frame(std::string, int, int);
	void run(); //�����Լ��� �� �ʿ� ����.
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