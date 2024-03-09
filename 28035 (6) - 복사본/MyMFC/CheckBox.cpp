#define _CRT_SECURE_NO_WARNINGS
#include "CheckBox.h"
#include "Frame.h"
#include <stdio.h>
using namespace std;

CheckBox::CheckBox(string title) : AbstractButton(title){

}

void CheckBox::repaint(HDC hdc) { // ���� �� �ǵ�� �ؽ�Ʈ�� �ٲ� ���̴�.
	AbstractButton::repaint(hdc); //Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
	string text;
	if (command_) {
		text = "[V]" + title_;
	}
	else {
		text = "[  ]" + title_;
	}

	TextOutA(hdc, x_ + 5, y_ + 4, text.c_str(), text.length());
}

//����
bool CheckBox::eventHandler(MEvent e) {
	command_ = 1 - command_; //�̰� 2�� �����°Ŵ�
	AbstractButton::eventHandler(e);
	return true;
}

