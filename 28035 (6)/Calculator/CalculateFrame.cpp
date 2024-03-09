#include "CalculateFrame.h"
#include "Button.h"
#include "StaticText.h"
#include <iostream>


CalculateFrame::CalculateFrame() :CalculateFrame("", 800, 600) {
	// 현재 사용되지 않고 있음.
}

CalculateFrame::CalculateFrame(std::string title, int width, int height) : Frame(title, width, height) {

}

bool CalculateFrame::eventHandler(MEvent e) {

	// TODO: 여기에 구현 코드 추가.
	OutputDebugString(L"Event\n");
	std::cout << L"Event\n" << std::endl;  // 여기는 cmd 창으로 출력

	if (Frame::eventHandler(e)) { //버튼이 눌렸을 때 바로 return하여 밑에 코드 실행하지 않게 한다.
		return true;
	}

	// 이벤트의 종류를 파악해서 사각형 그리기를 여기서 해준다.
	if (e.isLButtonDownEvent() || e.isRButtonDownEvent()) {
		start_ = e.getPoint();
		OutputDebugString(L"Down\n");
	}
	else if (e.isLButtonUpEvent()) {
		end_ = e.getPoint();
		OutputDebugString(L"Up\n");

		invalidate();
	}
	else if (e.isRButtonUpEvent()) {
		end_ = e.getPoint();
		OutputDebugString(L"Up\n");

		invalidate();
	}

	return false;
}


void CalculateFrame::repaint() {
	// 그려야할 모든 것은 여기에. 
	Frame::repaint();
	//응용

}

void CalculateFrame::initialize() {
	Button* btn0 = new Button("0");
	Button* btn1 = new Button("1");
	Button* btn2 = new Button("2");
	Button* btn3 = new Button("3");
	Button* btn4 = new Button("4");
	Button* btn5 = new Button("5");
	Button* btn6 = new Button("6");
	Button* btn7 = new Button("7");
	Button* btn8 = new Button("8");
	Button* btn9 = new Button("9");

	Button* btnP = new Button("+");
	Button* btnMi = new Button("-");
	Button* btnMu = new Button("*");
	Button* btnD = new Button("/");


	//addActionListener해야함?


	add(btn0);
	add(btn1);
	add(btn2);
	add(btn2);
	add(btn3);
	add(btn4);
	add(btn5);
	add(btn6);
	add(btn7);
	add(btn8);
	add(btn9);
	add(btnP);
	add(btnMi);
	add(btnMu);
	add(btnD);

	/*
	->setBounds(10, 10, 75, 25);
	->setBounds(100, 10, 75, 25);
	->setBounds(190, 10, 75, 25);
	->setBounds(280, 10, 75, 25);
	->setBounds(370, 10, 75, 25);
	*/

}
