#pragma once
#include <Windows.h>
#include "figure.h"
class Line : public Figure {
public:
	Line(int x1, int y1, int x2, int y2);
	void draw(HDC hdc) override;
};

