#pragma once
#include <GL\glew.h>

#include <vector>
#include <iostream>

class Model
{
private:
	GLuint _vaoID;
	GLuint _aboID;
	GLuint _eboID;

	int _numberOfVerts;
public:
	Model(std::vector<float> data, std::vector<unsigned int> indices);
	~Model();

	GLuint getVao() { return _vaoID; }
	GLuint getAbo() { return _aboID; }
	GLuint getEbo() { return _eboID; }

	int getVertexCount() { return _numberOfVerts; }
};

