#include "Camera.h"


glm::mat4 Camera::getCamera()
{
    return glm::lookAt(eye, eye + target, up);
}

Camera::Camera()
{
	this->eye = glm::vec3(10, 10, 10); // Camera is at (4,3,-3), in World Space
	this->target = glm::vec3(0, 0, 0); // and looks at the origin
	this->up = glm::vec3(0, 1, 0);
}