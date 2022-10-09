#pragma once
#include "Models.h"
#include "Shader.h"
#include "Transformation.h"

class DrawableObject
{
private:
	Models* models;
	Shader* shaders;
	Transformation* transformations;

public:
	DrawableObject();

	bool SetUp();
};