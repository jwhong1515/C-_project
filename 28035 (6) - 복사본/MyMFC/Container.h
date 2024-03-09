#pragma once
#include <iostream>
#include "Misc.h"
#include "MyList.h"
#include "Component.h"
#include "ActionListener.h"
#include "MouseListener.h"

class Container : public Component {// ��װ� �׼Ǹ����ʰ� �ʿ���?
public:
	Container(string title);
	void repaint(HDC hdc) override;
	virtual void add(Component* c);
	bool eventHandler(MEvent e) override;

	void addMouseListener(MouseListener* l);
protected:
	//�������� ����
	MyList<Component*> myComponentList;
	MyList<MouseListener*> mouseListeners_;
};


