#pragma once
#include "Windows.h"
#include <iostream>
#include <string>
#include <list>
//#include <vector>
#include "frame.h"
#include "Misc.h"
#include "MyList.h"
using namespace std;
//계산기 나오는 부분이 statictext다. //버튼은 그대로
class CalculateFrame : public Frame { //계산기는 툴바 필요없다.
protected:

	// 응용을 위해 필요한 변수

	MPoint start_;
	MPoint end_;
	static const int COMMAND_NONE = 0;
	static const int FIG_RECT = 1;
	static const int FIG_OVAL = 2;
	static const int FIG_LINE = 3;
	static const int FIG_GROUPIZE = 4;
	static const bool SET_GRID = false;

	int figType = COMMAND_NONE;
	bool grid = SET_GRID;

public:
	CalculateFrame();
	CalculateFrame(std::string, int, int); //생성자 없으면 안 될 거다
	bool eventHandler(MEvent e) override;
	void repaint() override;

	//
	void initialize() override;

};

