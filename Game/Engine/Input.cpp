#include "Input.h"



Input::Input(Window* window)
{
	_window = window->getWindowPtr();
}


Input::~Input()
{
}

double* Input::getMousePosition()
{
	double position[2];
	glfwGetCursorPos(*_window, &position[0], &position[1]);
	return position;
}
