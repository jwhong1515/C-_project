#pragma once
#include "Windows.h"
//#include "AbstractButton.h" �̰� ������ �� �ȴ�. �׷��� ��ȣ���� ��� ��?

// ȭ����� ���� ��Ÿ���� Ŭ����.
class MPoint {
public:
	int x_, y_;
	MPoint(int x, int y);
	MPoint();
};

// �̺�Ʈ�� Ŭ����ȭ �Ѵ�.
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
