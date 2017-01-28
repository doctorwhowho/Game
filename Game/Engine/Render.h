#pragma once

#include "Model.h"
#include "Shader.h"
#include "Camera.h"

class Render
{
public:
	Render();
	~Render();
	void modelRender(Model * model, Shader* shader, Camera* camera);

	GLuint _programID;
};

