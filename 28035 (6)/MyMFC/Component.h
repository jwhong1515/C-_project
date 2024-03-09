#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Misc.h"
using namespace std;
/*
class MEvent;
class MPoint;
class ActionEvent;
class Frame;
class ActionListener;
*/
class Component {
public:
	Component(string title);
	virtual void repaint(HDC hdc);
	virtual void setBounds(int x, int y, int width, int height);
	virtual bool includes(MPoint p);
	virtual bool includes(int x, int y);
	virtual bool eventHandler(MEvent e);
	const char* getTitle();

protected:
	int x_, y_, width_, height_;
	string title_;
	//Frame* frame_ = nullptr;
};

