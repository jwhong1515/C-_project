#pragma once
#include "Misc.h"

class MouseListener {
public:
	virtual void mousePressed(MEvent e) = 0;
	virtual void mouseReleased(MEvent e) = 0;
};