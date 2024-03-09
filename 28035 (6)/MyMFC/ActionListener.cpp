#include "ActionListener.h"

ActionListener::ActionListener() : container_(0){

}

ActionListener::ActionListener(Container* c) {
	container_ = c;
}


void ActionListener::setContainer(Container* c) {
	container_ = c;
}

