#pragma once
#include "Models.h"
#include "Shader.h"
#include "Transformation.h"


class DrawableObject
{
private:
	Models* models;
	Shader* shaders;

public:
	DrawableObject();

	bool SetUp();
};