#pragma once
#include <GLM\glm.hpp>
#include <GLM\gtc\matrix_transform.hpp>

class Camera
{
private:
	glm::vec3 _location;
	glm::mat4 _mvp;

	float _fov;
	int _width;
	int _height;
public:
	Camera(int width, int height, float fov, glm::vec3 location);
	~Camera();
	
	void calculateMVP(glm::vec3 position);

	glm::vec3 getLocation() { return _location; }
	glm::mat4 getMVP() { return _mvp; }
};

