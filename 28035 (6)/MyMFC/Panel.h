#pragma once
#include "Container.h"
#include "Misc.h"
class Panel : public Container {
protected:
	MPoint start_; //처리되어있는데 그러면 어디서 해야 해?
	MPoint end_;
public:
	Panel(string title);
};