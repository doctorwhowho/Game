#pragma once
#include <GL\glew.h>
#include <GLM\gtx\rotate_vector.hpp>

#include "Window.h"
#include "Render.h"
#include "Model.h"
#include "Shader.h"
#include "Camera.h"
#include "Input.h"

#include <iostream>


//do this before window creation
void _glfwInit()
{
	if (!glfwInit())
	{
		std::cerr << "Could not initialize glfw." << std::endl;
	}
}

//do this after window creation
void _glewInit()
{
	if (glewInit() != GLEW_OK)
		std::cerr << "Could not initialize glew." << std::endl;
}