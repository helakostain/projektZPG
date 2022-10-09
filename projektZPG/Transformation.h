#pragma once
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

class Transformation
{
private:
	glm::mat4 matrix;
public:
	Transformation();

	void setT();
	void rotateT();
	void changeSizeT();
};