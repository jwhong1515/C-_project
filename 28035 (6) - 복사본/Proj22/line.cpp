#include "line.h"

Line::Line(int x1, int y1, int x2, int y2) : Figure(x1, y1, x2, y2) {}

void Line::draw(HDC hdc) {
	MoveToEx(hdc, x1_, y1_, NULL);  //line �׸��� ���� ���� ��ġ�� ����
	LineTo(hdc, x2_, y2_);  //MoveToEx��(x, y)��ǥ���� LineTo��(x2, y2)��ǥ�� �� �߱�
}