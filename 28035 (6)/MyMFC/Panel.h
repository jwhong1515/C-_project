#pragma once
#include "Container.h"
#include "Misc.h"
class Panel : public Container {
protected:
	MPoint start_; //ó���Ǿ��ִµ� �׷��� ��� �ؾ� ��?
	MPoint end_;
public:
	Panel(string title);
};