#pragma once
#include "Windows.h"
//#include "AbstractButton.h" 이게 있으면 안 된다. 그러면 상호참조 어떻게 함?

// 화면상의 점을 나타내는 클래스.
class MPoint {
public:
	int x_, y_;
	MPoint(int x, int y);
	MPoint();
};

// 이벤트를 클래스화 한다.
class AbstractButton;
class ActionEvent;
class MEvent {
private:
	UINT msg_;
	WPARAM wParam_;
	LPARAM lParam_;
public:

	MEvent(UINT msg, WPARAM wParam, LPARAM lParam);
	bool isLButtonDownEvent();
	bool isLButtonUpEvent();
	bool isRButtonDownEvent();
	bool isRButtonUpEvent();

	bool isCtrlKeyDown();
	bool isShiftKeyDown();
	int getX();
	int getY();
	MPoint getPoint();

	ActionEvent makeActionEvent(AbstractButton* c);

};

class ActionEvent : public MEvent {
public:
	ActionEvent(UINT msg, WPARAM wParam, LPARAM lParam, AbstractButton* b);

	AbstractButton* getSource();
private:
	AbstractButton* button_;

};
