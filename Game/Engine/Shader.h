#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GLM\glm.hpp>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Shader
{
private:
	GLuint _programID;
public:
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	void start();

	void stop();

	void cleanup();

	void loadMat4(glm::mat4 mat4, const GLchar* definition);
};

