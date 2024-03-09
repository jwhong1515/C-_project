#include "ToolBar.h"

ToolBar::ToolBar(string title) : Container(title), idx(0) {
	setBounds(0, 0, 1000, 30);
}

void ToolBar::add(Component* c) {
	Container::add(c);
	c->setBounds(0 + 100 * idx, 0, 100, 30);
	idx++;
}
/*
void ToolBar::repaint(HDC hdc) {

	Container::repaint(hdc);
}
*/