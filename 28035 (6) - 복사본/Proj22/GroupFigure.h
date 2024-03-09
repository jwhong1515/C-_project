#pragma once
#include "MyList.h"
#include "figure.h"
#include <Windows.h>
class GroupFigure : public Figure{ //이게 box역할
public:
	GroupFigure(int x1, int y1, int x2, int y2);
	void draw(HDC hdc) override;
	void add(Figure*);
	
	void move(int, int) override;

	void resetBoundary(); //
	bool isEmpty(); //
protected:
	MyList<Figure*> fl;
};

