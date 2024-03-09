#pragma once
#include "Misc.h"
#include <Windows.h>
class Figure {
public:
	Figure(int x1, int y1, int x2, int y2);
	virtual void draw(HDC hdc) = 0;
	void setXY(); //시작점이 끝점보다 커지는 것을 방지하기 위함
	virtual void move(int, int); 
	bool isIn(MPoint p); //
	
//protected:
	int x1_, y1_, x2_, y2_;
};




