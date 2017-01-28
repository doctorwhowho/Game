#pragma once
#include <GLFW\glfw3.h>
#include "Window.h"

class Input
{
private:
	GLFWwindow** _window;
public:
	Input(Window* window);
	~Input();

	double* getMousePosition();
};

