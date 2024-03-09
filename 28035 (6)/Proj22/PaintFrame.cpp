#include "PaintFrame.h"
#include "PaintPanel.h"
#include "rect.h"
#include "oval.h"
#include "line.h"
#include "GroupFigure.h"
#include "Button.h" //����Ŭ���� include�ϸ� ����class�� include��
#include "CheckBox.h"
#include <iostream>


PaintFrame::PaintFrame() :PaintFrame("", 800, 600) {
	// ���� ������ �ʰ� ����.
}

PaintFrame::PaintFrame(std::string title, int width, int height) : Frame(title, width, height) {

}

void PaintFrame::initialize() {
	toolBar_ = new ToolBar("����");
	paintPanel_ = new PaintPanel("Paint�г�");

	Button* btnRect = new Button("�簢��");
	Button* btnOval = new Button("Ÿ��");
	Button* btnLine = new Button("����");
	Button* btnGroupize = new Button("�׷�ȭ");
	CheckBox* btnGrid = new CheckBox("�׸���");
	//�� ���� actionlistener�ٿ���� ��?Button
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

	paintPanel_->addMouseListener(paintPanel_); //panel�� mouseListener ����

	add(toolBar_);
	add(paintPanel_);
	paintPanel_->setFrame(this);
}



/*
void PaintFrame::repaint(HDC hdc) {
	// �׷����� ��� ���� ���⿡. 
	Frame::repaint(HDC hdc);
	//����
	MyList<Figure*>::iterator fi;
	for (fi = myFigureList.begin(); fi != myFigureList.end(); fi++) {
		(*fi)->draw(hdc);
	}
}
*/