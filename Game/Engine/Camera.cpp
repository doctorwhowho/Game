#include "Camera.h"

Camera::Camera(int width, int height, float fov, glm::vec3 location)
{
	_location = location;

	glm::mat4 view = glm::perspective(fov, (float)width / (float)height, 0.1f, 1000.0f);

	/* TODO:
	ADD ROTATION SYSTEM, CHANGE 'UP';
	CHANGE VIEW POIN. 
	*/
	glm::mat4 perspective = glm::lookAt(_location, _location + glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));

	glm::mat4 model = glm::mat4(1.0f);

	_mvp = model * view *  perspective;

	_fov = fov;
	_width = width;
	_height = height;
}

Camera::~Camera()
{
}

void Camera::calculateMVP(glm::vec3 position)
{
	glm::mat4 view = glm::perspective(_fov, (float)_width / (float)_height, 0.1f, 1000.0f);

	/* TODO:
	ADD ROTATION SYSTEM, CHANGE 'UP';
	CHANGE VIEW POIN.
	*/
	glm::mat4 perspective = glm::lookAt(position, position + glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));

	glm::mat4 model = glm::mat4(1.0f);

	_mvp = model * view *  perspective;
}
