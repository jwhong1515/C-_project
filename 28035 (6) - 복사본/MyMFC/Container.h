#pragma once
#include <iostream>
#include "Misc.h"
#include "MyList.h"
#include "Component.h"
#include "ActionListener.h"
#include "MouseListener.h"

class Container : public Component {// 얘네가 액션리스너가 필요해?
public:
	Container(string title);
	void repaint(HDC hdc) override;
	virtual void add(Component* c);
	bool eventHandler(MEvent e) override;

	void addMouseListener(MouseListener* l);
protected:
	//공통적인 변수
	MyList<Component*> myComponentList;
	MyList<MouseListener*> mouseListeners_;
};


