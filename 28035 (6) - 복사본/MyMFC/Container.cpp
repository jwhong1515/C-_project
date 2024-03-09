#include "Container.h"

//component 중에서도 다른 component들을 안에 집어넣을 수 있는 애
Container::Container(string title) : Component(title) {

}

void Container::add(Component* c) {
	myComponentList.push_back(c);
}

bool Container::eventHandler(MEvent e) { //부속품 불러준 후 없으면 자기자신꺼 불러준다.

	OutputDebugString(L"컨테이너 1\n");
	MyList<Component*>::iterator ci;
	for (ci = myComponentList.begin(); ci != myComponentList.end(); ci++) {
		if ((*ci)->eventHandler(e)) { //처리를 잘 해주어야 한다.
			return true;
		}
	}

	//없으면 자기자신 꺼
	OutputDebugString(L"컨테이너 2\n");

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