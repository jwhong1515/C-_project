#include "line.h"

Line::Line(int x1, int y1, int x2, int y2) : Figure(x1, y1, x2, y2) {}

void Line::draw(HDC hdc) {
	MoveToEx(hdc, x1_, y1_, NULL);  //line 그리기 전에 시작 위치를 지정
	LineTo(hdc, x2_, y2_);  //MoveToEx의(x, y)좌표에서 LineTo의(x2, y2)좌표로 선 긋기
}