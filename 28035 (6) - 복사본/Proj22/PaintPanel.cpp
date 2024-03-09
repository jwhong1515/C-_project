#include "PaintPanel.h"
#include "PaintFrame.h"
#include "rect.h"
#include "oval.h"
#include "line.h"
#include "GroupFigure.h"
#include "Button.h" //����Ŭ���� include�ϸ� ����class�� include��
#include "CheckBox.h"
#include <iostream>

PaintPanel::PaintPanel(string title) : Panel(title), MouseListener(), ActionListener() {

}

void PaintPanel::setFrame(PaintFrame* f) {
	frame_ = f;
}

void PaintPanel::mousePressed(MEvent e) { //���콺 ������ �� ��ġ���
	start_ = e.getPoint();
	figure_ = findFigure(start_);
}

void PaintPanel::mouseReleased(MEvent e) { //���콺 ���� �� ��ġ���
	end_ = e.getPoint();

	if (grid) {
		start_ = nearPoint(start_);
		end_ = nearPoint(end_);
	}

	if (figType == FIG_GROUPIZE) { //�׷�ȭ ��ư�� �����ž�, paint��ư�� onClick�� setFigType()���� ���߱� ������ �̷��� �ؾ� ��
		createGroupFigure(); //�����ؼ� �Լ�ȭ ��
		//�׷�ȭ�� ������ figType �ʱ�ȭ
		figType = COMMAND_NONE;
	}
	else if (e.isCtrlKeyDown()) {// ctrlŰ�� ������ �̵�
		Figure* f = findFigure(start_);
		if (f) {
			f->move(end_.x_ - start_.x_, end_.y_ - start_.y_);
		}
	}
	else {
		if (figType == FIG_RECT) {
			myFigureList.push_back(new Rect(start_.x_, start_.y_, end_.x_, end_.y_));
		}
		else if (figType == FIG_OVAL) {
			myFigureList.push_back(new Oval(start_.x_, start_.y_, end_.x_, end_.y_));
		}
		else if (figType == FIG_LINE) {
			myFigureList.push_back(new Line(start_.x_, start_.y_, end_.x_, end_.y_));
		}
	}
}

void PaintPanel::actionPerformed(ActionEvent e) {
	OutputDebugString(L"Paint�ǳ� actionListener ȣ��\n");
	int cmd = (e.getSource())->getCommand();
	if (-1 < cmd && cmd < 2){
		OutputDebugString(L"�׸��� ����\n");
		setGrid(cmd);
	}
	else if (1 < cmd && cmd < 7) { //�����׸��� and �̵�
		OutputDebugString(L"������� ����\n");
		setFigType(cmd);
	}
}


void PaintPanel::repaint(HDC hdc) {
	// �׷����� ��� ���� ���⿡. 
	Panel::repaint(hdc); 
	//����
	MyList<Figure*>::iterator fi;
	for (fi = myFigureList.begin(); fi != myFigureList.end(); fi++) {
		(*fi)->draw(hdc);
	}
}

MPoint PaintPanel::nearPoint(MPoint p) {
	return MPoint((p.x_ + 10) / 20 * 20, (p.y_ + 10) / 20 * 20);
}

void PaintPanel::setFigType(int t) {
	figType = t;
}

void PaintPanel::setGrid(int t) {
	grid = t;
}


Figure* PaintPanel::findFigure(MPoint p) {
	MyList<Figure*>::reverse_iterator fi;
	for (fi = myFigureList.rbegin(); fi != myFigureList.rend(); fi++) {
		if ((*fi)->isIn(p)) {
			return *fi;
		}
	}
	return nullptr;
}

bool PaintPanel::inCluded(Figure* f, MPoint s, MPoint e) {
	return s.x_ < f->x1_&& f->x2_ < e.x_&& s.y_ < f->y1_&& f->y2_ < e.y_;
}


void PaintPanel::createGroupFigure() {
	MyList<Figure*> temp; //�ӽø���Ʈ�� ���� �ְ� ���߿� ���� ���� �� ����.

	MyList<Figure*>::iterator fi;
	for (fi = myFigureList.begin(); fi != myFigureList.end(); fi++) {
		if (inCluded(*fi, start_, end_)) { //�׷�ȭ ������ ������
			temp.push_back(*fi); //�ϴ� �ӽó�忡 ���� ����
		}
	}
	if (!temp.isEmpty()) { //�׷쵵���� �� �� �ƴ϶��
		GroupFigure* gf = new GroupFigure(start_.x_, start_.y_, end_.x_, end_.y_); //���߿� �����Ұ���

		MyList<Figure*>::iterator fi2;
		for (fi2 = temp.begin(); fi2 != temp.end(); fi2++) {
			gf->add(*fi2); //�׷쵵���� �߰�
			myFigureList.remove(*fi2); //myFigureList���� ����
		}

		gf->resetBoundary();// ��ġ�����ϰ�
		//�ϼ��� �׷쵵���� myFigureList�� �߰�
		myFigureList.push_back(gf);
	}
}


