#include "AbstractButton.h"
using namespace std;

AbstractButton::AbstractButton(string title) : Component(title), command_(0) {

}

void AbstractButton::repaint(HDC hdc) {
	Component::repaint(hdc); //Rectangle(hdc, x_, y_, x_ + width_, y_ + height_);
}

bool AbstractButton::eventHandler(MEvent e) {
	if (!listeners_.isEmpty()) {
		MyList<ActionListener*>::iterator ali;
		for (ali = listeners_.begin(); ali != listeners_.end(); ali++) {
			(*ali)->actionPerformed(e.makeActionEvent(this));
		}
	}
	return true;
}

void AbstractButton::addActionListener(ActionListener* al) {
	listeners_.push_back(al);
}

void AbstractButton::setCommand(int t) {
	command_ = t;
}
int AbstractButton::getCommand() {
	return command_;
}