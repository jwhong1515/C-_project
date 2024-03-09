#pragma once
#include "Container.h"
#include "Misc.h"
class ToolBar : public Container {
protected:
	int idx;
public:
	ToolBar(string title); 
	void add(Component* c) override;
};