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
	DrawableObject(const float points[], int size_points);

	void DoTransformations(const double delta);
	void sendShaderMatrix();
	bool SetUp();

	void setFy(Direction dir);
	void setFx(Direction dir);
	void setRot(Rotation r);
	void setGrow(Growth g);

	Shader& getShader();
	void Pos_mov(glm::vec3 a);
};