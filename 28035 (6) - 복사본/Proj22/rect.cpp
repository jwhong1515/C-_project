#include "rect.h"

Rect::Rect(int x1, int y1, int x2, int y2) : Figure(x1, y1, x2, y2) {}

void Rect::draw(HDC hdc) {
	Rectangle(hdc, x1_, y1_, x2_, y2_);
}

