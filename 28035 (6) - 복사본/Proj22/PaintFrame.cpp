#include "PaintFrame.h"
#include "PaintPanel.h"
#include "rect.h"
#include "oval.h"
#include "line.h"
#include "GroupFigure.h"
#include "Button.h" //하위클래스 include하면 상위class도 include됨
#include "CheckBox.h"
#include <iostream>


PaintFrame::PaintFrame() :PaintFrame("", 800, 600) {
	// 현재 사용되지 않고 있음.
}

PaintFrame::PaintFrame(std::string title, int width, int height) : Frame(title, width, height) {

}

void PaintFrame::initialize() {
	toolBar_ = new ToolBar("툴바");
	paintPanel_ = new PaintPanel("Paint패널");

	Button* btnRect = new Button("사각형");
	Button* btnOval = new Button("타원");
	Button* btnLine = new Button("선분");
	Button* btnGroupize = new Button("그룹화");
	CheckBox* btnGrid = new CheckBox("그리드");
	//다 각각 actionlistener붙여줘야 함?Button
	/*
	btnRect->setBounds(0 + 100 * 0, 0, 100, 30);
	btnOval->setBounds(0 + 100 * 1, 0, 100, 30);
	btnLine->setBounds(0 + 100 * 2, 0, 100, 30);
	btnGroupize->setBounds(0 + 100 * 3, 0, 100, 30);
	btnGrid->setBounds(0 + 100 * 4, 0, 100, 30);
	*/
	toolBar_->add(btnRect);
	toolBar_->add(btnOval);
	toolBar_->add(btnLine);
	toolBar_->add(btnGroupize);
	toolBar_->add(btnGrid);

	btnRect->addActionListener(paintPanel_); 
	btnOval->addActionListener(paintPanel_);
	btnLine->addActionListener(paintPanel_);
	btnGroupize->addActionListener(paintPanel_);
	btnGrid->addActionListener(paintPanel_);

	paintPanel_->addMouseListener(paintPanel_); //panel이 mouseListener 역할

	add(toolBar_);
	add(paintPanel_);
	paintPanel_->setFrame(this);
}



/*
void PaintFrame::repaint(HDC hdc) {
	// 그려야할 모든 것은 여기에. 
	Frame::repaint(HDC hdc);
	//응용
	MyList<Figure*>::iterator fi;
	for (fi = myFigureList.begin(); fi != myFigureList.end(); fi++) {
		(*fi)->draw(hdc);
	}
}
*/