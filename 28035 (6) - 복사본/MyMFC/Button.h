#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Misc.h"
#include "AbstractButton.h"
using namespace std;

class Frame;
class Button : public AbstractButton {
public:
	Button(string title);
	void repaint(HDC hdc) override;
};
