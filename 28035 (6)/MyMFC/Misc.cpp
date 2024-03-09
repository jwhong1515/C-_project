#include "Misc.h"

MPoint::MPoint(int x, int y) : x_(x), y_(y) {}

MPoint::MPoint() : x_(0), y_(0) {}

MEvent::MEvent(UINT msg, WPARAM wParam, LPARAM lParam) :
	msg_(msg), wParam_(wParam), lParam_(lParam)
{
	//  Nothing to do here.
}

bool MEvent::isLButtonDownEvent() {
	return msg_ == WM_LBUTTONDOWN;
}
bool MEvent::isLButtonUpEvent() {
	return msg_ == WM_LBUTTONUP;
}
bool MEvent::isRButtonDownEvent() {
	return msg_ == WM_RBUTTONDOWN;
}
bool MEvent::isRButtonUpEvent() {
	return msg_ == WM_RBUTTONUP;
}

//
bool MEvent::isCtrlKeyDown() { // ctrlŰ�� ����ä�� �߻��� event����
	return wParam_ & MK_CONTROL;
}
bool MEvent::isShiftKeyDown() { // shiftŰ�� ����ä�� �߻��� event����
	return wParam_ & MK_SHIFT;
}
int MEvent::getX() {
	return LOWORD(lParam_);
}
int MEvent::getY() {
	return HIWORD(lParam_);
}
MPoint MEvent::getPoint() {
	return MPoint(LOWORD(lParam_), HIWORD(lParam_));
}

ActionEvent MEvent::makeActionEvent(AbstractButton* c) { //��ư üũ�ڽ� ����
	return ActionEvent(msg_, wParam_, lParam_, c);
}


ActionEvent::ActionEvent(UINT msg, WPARAM wParam, LPARAM lParam, AbstractButton* b) :
	MEvent(msg, wParam,lParam), button_(b)
{
	//  Nothing to do here.
}

AbstractButton* ActionEvent::getSource() {
	return button_;
}




