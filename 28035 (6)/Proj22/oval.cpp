#include "oval.h"

Oval::Oval(int x1, int y1, int x2, int y2) : Figure(x1, y1, x2, y2) {}

void Oval::draw(HDC hdc) {
	Ellipse(hdc, x1_, y1_, x2_, y2_);
}