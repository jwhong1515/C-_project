#include "GroupFigure.h"

GroupFigure::GroupFigure(int x1, int y1, int x2, int y2) : Figure(x1, y1, x2, y2) {}

void GroupFigure::draw(HDC hdc) {
	Rectangle(hdc, x1_, y1_, x2_, y2_); //점선으로 하면 좋을텐데..
	MyList<Figure*>::iterator fi;
	for (fi = fl.begin(); fi != fl.end(); fi++) {
		(*fi)->draw(hdc);
	}
}

void GroupFigure::add(Figure* f) {
	fl.push_back(f);
}


void GroupFigure::move(int dx, int dy) {
	Figure::move(dx,dy);
	MyList<Figure*>::iterator fi;
	for (fi = fl.begin(); fi != fl.end(); fi++) {
		(*fi)->move(dx, dy);
	}
}


void GroupFigure::resetBoundary() {
	x1_ = y1_ = INT_MAX;
	x2_ = y2_ = INT_MIN;
	MyList<Figure*>::iterator fi;
	for (fi = fl.begin(); fi != fl.end(); fi++) {
		if ((*fi)->x1_ < x1_) {
			x1_ = (*fi)->x1_;
		}
		if ((*fi)->y1_ < y1_) {
			y1_ = (*fi)->y1_;
		}
		if (x2_ < (*fi)->x2_) {
			x2_ = (*fi)->x2_;
		}
		if (y2_ < (*fi)->y2_) {
			y2_ = (*fi)->y2_;
		}
	}
}

bool GroupFigure::isEmpty() {
	return fl.isEmpty();
}