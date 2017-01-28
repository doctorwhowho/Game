#include "Render.h"

Render::Render()
{
	glEnable(GL_DEPTH_TEST);
}

Render::~Render()
{
}

void Render::modelRender(Model* model, Shader* shader, Camera* camera)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindVertexArray(model->getVao());
	glEnableVertexAttribArray(0);
	shader->start();
	shader->loadMat4(camera->getMVP(), "MVP");
	glBindBuffer(GL_ARRAY_BUFFER, model->getAbo());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->getEbo());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, (void*)0);
	glDisableVertexAttribArray(0);
	shader->stop();
}