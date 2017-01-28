#include "Window.h"

Window::Window(int width, int height, const char* title)
{
	if (!glfwInit())
	{
		std::cerr << "Could not initialize glfw." << std::endl;
	}

	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 4);

	glfwWindowHint(GLFW_SAMPLES, 16);

	_width = width;
	_height = width;
	_window = glfwCreateWindow(width, height, title, NULL, NULL); 

	glfwMakeContextCurrent(_window);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::swapBuffers()
{
	glfwSwapBuffers(_window);
}

void Window::pollEvents()
{
	glfwPollEvents();
}
