#include "PaintPanel.h"
#include "PaintFrame.h"
#include "rect.h"
#include "oval.h"
#include "line.h"
#include "GroupFigure.h"
#include "Button.h" //하위클래스 include하면 상위class도 include됨
#include "CheckBox.h"
#include <iostream>

PaintPanel::PaintPanel(string title) : Panel(title), MouseListener(), ActionListener() {

}

void PaintPanel::setFrame(PaintFrame* f) {
	frame_ = f;
}

void PaintPanel::mousePressed(MEvent e) { //마우스 눌렀을 때 위치기억
	start_ = e.getPoint();
	figure_ = findFigure(start_);
}

void PaintPanel::mouseReleased(MEvent e) { //마우스 뗐을 때 위치기억
	end_ = e.getPoint();

	if (grid) {
		start_ = nearPoint(start_);
		end_ = nearPoint(end_);
	}

	if (figType == FIG_GROUPIZE) { //그룹화 버튼만 눌린거야, paint버튼의 onClick은 setFigType()으로 정했기 때문에 이렇게 해야 함
		createGroupFigure(); //복잡해서 함수화 함
		//그룹화가 끝나면 figType 초기화
		figType = COMMAND_NONE;
	}
	else if (e.isCtrlKeyDown()) {// ctrl키가 눌리면 이동
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
	OutputDebugString(L"Paint판넬 actionListener 호출\n");
	int cmd = (e.getSource())->getCommand();
	if (-1 < cmd && cmd < 2){
		OutputDebugString(L"그리드 설정\n");
		setGrid(cmd);
	}
	else if (1 < cmd && cmd < 7) { //도형그리기 and 이동
		OutputDebugString(L"도형모양 설정\n");
		setFigType(cmd);
	}
}


void PaintPanel::repaint(HDC hdc) {
	// 그려야할 모든 것은 여기에. 
	Panel::repaint(hdc); 
	//응용
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
	MyList<Figure*> temp; //임시리스트에 먼저 넣고 나중에 빼야 오류 안 난다.

	MyList<Figure*>::iterator fi;
	for (fi = myFigureList.begin(); fi != myFigureList.end(); fi++) {
		if (inCluded(*fi, start_, end_)) { //그룹화 범위에 있으면
			temp.push_back(*fi); //일단 임시노드에 먼저 넣음
		}
	}
	if (!temp.isEmpty()) { //그룹도형이 빈 게 아니라면
		GroupFigure* gf = new GroupFigure(start_.x_, start_.y_, end_.x_, end_.y_); //나중에 조정할거임

		MyList<Figure*>::iterator fi2;
		for (fi2 = temp.begin(); fi2 != temp.end(); fi2++) {
			gf->add(*fi2); //그룹도형에 추가
			myFigureList.remove(*fi2); //myFigureList에서 삭제
		}

		gf->resetBoundary();// 위치조정하고
		//완성된 그룹도형을 myFigureList에 추가
		myFigureList.push_back(gf);
	}
}


