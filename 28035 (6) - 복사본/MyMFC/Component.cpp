#include "Component.h"
using namespace std;

//Component�� �ƹ��͵� ���� �׸� ��ü, Ŭ���ϸ� ���� �Ͼ �� ����
Component::Component(string title) : title_(title), x_(0), y_(0), width_(70), height_(25) {
}

void Component::repaint(HDC hdc) {
	Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
}

void Component::setBounds(int x, int y, int width, int height) {
	x_ = x; y_ = y; width_ = width; height_ = height;
}
bool Component::includes(MPoint p) {
	return includes(p.x_, p.y_);
}
bool Component::includes(int x, int y) {
	return x_ < x && x < x_ + width_ && y_ < y && y < y_ + height_;
}


bool Component::eventHandler(MEvent e) { //��ӹ޾Ƽ� ����� ��
	return false;
}

const char* Component::getTitle() {
	return title_.c_str();
}



