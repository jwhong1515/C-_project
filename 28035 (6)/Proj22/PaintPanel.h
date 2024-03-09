#pragma once
#include "Panel.h"
#include "MouseListener.h"

//�׸��׸��� ����� PaintPanel�� �� ���� ��
class Figure;
class PaintFrame;
class PaintPanel : public Panel, public MouseListener, public ActionListener {
public:
	PaintFrame* frame_ = 0;
	MyList<Figure*> myFigureList;

	static const int SET_GRID = 0;

	static const int COMMAND_NONE = 2;
	static const int FIG_RECT = 3;
	static const int FIG_OVAL = 4;
	static const int FIG_LINE = 5;
	static const int FIG_GROUPIZE = 6;

	int figType = COMMAND_NONE;
	int grid = SET_GRID;

	Figure* figure_ = 0;
	PaintFrame* paintFrame_ = 0;

	PaintPanel(string title);
	void mousePressed(MEvent e) override;
	void mouseReleased(MEvent e) override;
	void actionPerformed(ActionEvent e) override;
	void setFrame(PaintFrame* pf);
	void repaint(HDC hdc) override;

	MPoint nearPoint(MPoint p);
	void setFigType(int t);
	void setGrid(int t);

	Figure* findFigure(MPoint p); //���� ã�°͵� frame���� ��
	bool inCluded(Figure* f, MPoint s, MPoint e); 
	void createGroupFigure();

};
