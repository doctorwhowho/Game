#include "Model.h"

Model::Model(std::vector<float> data, std::vector<unsigned int> indices)
{
	glGenVertexArrays(1, &_vaoID);
	glBindVertexArray(_vaoID);

	glGenBuffers(1, &_aboID);
	glBindBuffer(GL_ARRAY_BUFFER, _aboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &_eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

	glBindVertexArray(0);

	_numberOfVerts = indices.size();
}

Model::~Model()
{
}
