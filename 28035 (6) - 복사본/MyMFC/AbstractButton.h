#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Misc.h"
#include "MyList.h"
#include "ActionListener.h" //�־�� �Ѵ�.
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

	void setCommand(int t); //�Լ���ü�� ���̺귯���� �δ� �� ���� �� �ϴ�
	int getCommand();

protected:
	int command_;

	MyList<ActionListener*> listeners_;
};