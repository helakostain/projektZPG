#pragma once

#include <GL/glew.h>
#include <glm/mat4x4.hpp>

#include "Models.h"

#include <iterator>
#include <vector>


class SuziFlat : public Models
{
private:
	const float* points;
	int valuesInRow = 6;
	int skip = 3;
	int values = 3;
	GLuint VAO = 0;
	GLuint VBO = 0;
public:
	SuziFlat();
	void Draw() override;
	void Init() override;
	void Bind() override;
};