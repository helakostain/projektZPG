#pragma once
#include "Models.h"
#include "Shader.h"
#include "Transformation.h"
#include <vector>

class DrawableObject
{
private:
	Models* models;
	Shader* shaders;
	Transformation* transformations;

	const char* vertex_shader;
	const char* fragment_shader;
public:
	DrawableObject();
	DrawableObject(float points[], int size_points);

	bool SetUp();
};