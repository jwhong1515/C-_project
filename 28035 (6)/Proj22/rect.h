#pragma once
#include <Windows.h>
#include "figure.h"
class Rect : public Figure{
public:
	Rect(int x1, int y1, int x2, int y2);
	void draw(HDC hdc) override;
};