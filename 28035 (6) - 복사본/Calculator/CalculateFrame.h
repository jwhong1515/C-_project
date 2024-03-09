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
//���� ������ �κ��� statictext��. //��ư�� �״��
class CalculateFrame : public Frame { //����� ���� �ʿ����.
protected:

	// ������ ���� �ʿ��� ����

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
	CalculateFrame(std::string, int, int); //������ ������ �� �� �Ŵ�
	bool eventHandler(MEvent e) override;
	void repaint() override;

	//
	void initialize() override;

};

