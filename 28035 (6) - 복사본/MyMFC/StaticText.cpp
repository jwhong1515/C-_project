#include "StaticText.h"
#include "Frame.h"
using namespace std;
//이게 Label 역할
StaticText::StaticText(string title) : AbstractButton(title) {

}

void StaticText::repaint(HDC hdc) {
	AbstractButton::repaint(hdc); //Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
	TextOutA(hdc, x_ + 5, y_ + 4, title_.c_str(), title_.length());
}
