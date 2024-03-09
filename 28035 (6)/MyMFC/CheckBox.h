#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Misc.h"
#include "AbstractButton.h"
using namespace std;

class Frame;
class CheckBox : public AbstractButton {
public:
	CheckBox(string title);
	void repaint(HDC hdc) override;
	//ÀÀ¿ë

	bool eventHandler(MEvent e) override;
};

