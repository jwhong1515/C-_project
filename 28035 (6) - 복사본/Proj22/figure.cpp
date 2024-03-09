#include "figure.h"

Figure::Figure(int x1, int y1, int x2, int y2) : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {
	setXY();
}

void Figure::setXY() {
	if (x1_ > x2_) {
		int t = x1_;
		x1_ = x2_;
		x2_ = t;
	}
	if (y1_ > y2_) {
		int t = y1_;
		y1_ = y2_;
		y2_ = t;
	}
}
void Figure::move(int dx, int dy) {
	x1_ += dx; x2_ += dx;
	y1_ += dy; y2_ += dy;
}

bool Figure::isIn(MPoint p) {
	return x1_ < p.x_&& p.x_ < x2_&& y1_ < p.y_&& p.y_ < y2_;
}

