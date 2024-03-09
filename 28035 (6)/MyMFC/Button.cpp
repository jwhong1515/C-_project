#include "Button.h"
#include "Frame.h"
using namespace std;

Button::Button(string title) : AbstractButton(title){

}

void Button::repaint(HDC hdc) {
	AbstractButton::repaint(hdc); //Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
	TextOutA(hdc, x_ + 5, y_ + 4, title_.c_str(), title_.length());
}





