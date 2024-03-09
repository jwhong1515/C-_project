#include "Container.h"

//component �߿����� �ٸ� component���� �ȿ� ������� �� �ִ� ��
Container::Container(string title) : Component(title) {

}

void Container::add(Component* c) {
	myComponentList.push_back(c);
}

bool Container::eventHandler(MEvent e) { //�μ�ǰ �ҷ��� �� ������ �ڱ��ڽŲ� �ҷ��ش�.

	OutputDebugString(L"�����̳� 1\n");
	MyList<Component*>::iterator ci;
	for (ci = myComponentList.begin(); ci != myComponentList.end(); ci++) {
		if ((*ci)->eventHandler(e)) { //ó���� �� ���־�� �Ѵ�.
			return true;
		}
	}

	//������ �ڱ��ڽ� ��
	OutputDebugString(L"�����̳� 2\n");

	if (includes(e.getPoint())) {
		if (e.isLButtonDownEvent() || e.isRButtonDownEvent()) {
			MyList<MouseListener*>::iterator mli;
			for (mli = mouseListeners_.begin(); mli != mouseListeners_.end(); mli++) {
				(*mli)->mousePressed(e);
				//return true;
			}
		}
		else if (e.isLButtonUpEvent() || e.isRButtonUpEvent()) {
			MyList<MouseListener*>::iterator mli;
			for (mli = mouseListeners_.begin(); mli != mouseListeners_.end(); mli++) {
				(*mli)->mouseReleased(e);
				//return true;
			}
		}
	}

}

void Container::repaint(HDC hdc) {
	Component::repaint(hdc); //Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
	MyList<Component*>::iterator ci;
	for (ci = myComponentList.begin(); ci != myComponentList.end(); ci++) {
		(*ci)->repaint(hdc);
	}
}

void Container::addMouseListener(MouseListener* l) {
	mouseListeners_.push_back(l);
}