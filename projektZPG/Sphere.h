#pragma once
#include <GL/glew.h>

#include <glm/mat4x4.hpp>

#include <iterator>
#include <vector>

#include "Models.h"
#include "Models/sphere.h"

class Sphere : public Models
{
private:
	//float x[] = { 0.f, 0.f, 0.f, 0.f };
	const float* points;
	int valuesInRow = 6;
	int skip = 3;
	int values = 3;
	GLuint VAO = 0;
	GLuint VBO = 0;
public:
	Sphere();
	void Init();
	void Bind();
	void Draw();
};