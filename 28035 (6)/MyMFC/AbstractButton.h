#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Misc.h"
#include "MyList.h"
#include "ActionListener.h" //있어야 한다.
#include "Component.h"
using namespace std;
/*
class MEvent;
class MPoint;
class ActionEvent;
class Frame;
class ActionListener;
*/
class AbstractButton : public Component {
public:
	AbstractButton(string title);
	void repaint(HDC hdc) override;

	bool eventHandler(MEvent e) override; 
	virtual void addActionListener(ActionListener* al);

	void setCommand(int t); //함수자체는 라이브러리에 두는 게 좋을 듯 하다
	int getCommand();

protected:
	int command_;

	MyList<ActionListener*> listeners_;
};