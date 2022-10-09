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

	static const char* vertex_shader;
	static const char* fragment_shader;
public:
	DrawableObject();
	DrawableObject(float points[], int size_points);

	bool SetUp();
};