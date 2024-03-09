#pragma once
#include "Misc.h"
//#include "Container.h"
/*
class MEvent;
class ActionEvent;
class Component;
class Frame;
*/
class Component;
class Container;
class ActionListener {
public:
	ActionListener();
	ActionListener(Container* c);
	virtual void actionPerformed(ActionEvent e) =0;

	void setContainer(Container* c);

protected:
	Container* container_;
};

