#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();

	void swapBuffers();
	void pollEvents();

	bool shouldClose() { return glfwWindowShouldClose(_window); }

	GLFWwindow** getWindowPtr() { return &_window; }

	GLFWwindow* getWindow() { return _window; }
private:
	int _width;
	int _height;
	GLFWwindow* _window;
};

