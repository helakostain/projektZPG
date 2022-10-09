#pragma once
#include "Models.h"
#include "Shader.h"
#include "Transformation.h"
#include <vector>

class DrawableObject
{
private:
	Models models[2];
	Shader* shaders;
	Transformation* transformations;

public:
	DrawableObject();
	DrawableObject(std::vector<float> points);

	bool SetUp();
};