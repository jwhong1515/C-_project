#pragma once
#include "Windows.h"
#include <iostream>
#include <string>
#include <list>
//#include <vector>
#include "frame.h"
#include "Misc.h"
#include "figure.h"
#include "MyList.h"
#include "ActionListener.h"
using namespace std;

class PaintPanel;
class PaintFrame : public Frame{
protected:
	
public:

	PaintFrame();
	PaintFrame(std::string, int, int); //������ ������ �� �� �Ŵ�
	//bool eventHandler(MEvent e) override;
	//void repaint(HDC hdc) override;

	void initialize() override;



	PaintPanel* paintPanel_ = nullptr;
};

