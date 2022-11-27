#pragma once
#include <vector>

#include "Models.hpp"
#include "Shader.h"
#include "Transformation.h"
#include "Texture.hpp"

class DrawableObject
{
private:
	Models* models;
	Shader* shaders;
	Transformation* transformations;
	shared_ptr<Texture> texture;

	const char* vertex_shader;
	const char* fragment_shader;

	bool isObject;
	int id;
public:
	DrawableObject();
	//DrawableObject(const float points[], int size_points, const char* vertex_path, const char* fragment_path);
	//DrawableObject(const float points[], int size_points, Shader& shader);
	//DrawableObject(const float points[], int size_points, Shader& shader, shared_ptr<Texture> texture);
	DrawableObject(Models* model, const char* vertex_path, const char* fragment_path, int size);
	DrawableObject(Models* model, Shader& shader, int size);
	DrawableObject(Models* model, Shader& shader, shared_ptr<Texture> texture, int size);
	DrawableObject(Models* model, Shader& shader, shared_ptr<Texture> texture, int size, bool object);

	void DoTransformations(const double delta);
	void sendShaderMatrix();
	bool SetUp();
	void Pos_scale(float a);
	void setFy(Direction dir);
	void setFx(Direction dir);
	void setRot(Rotation r);
	void setGrow(Growth g);
	void Pos_mov(glm::vec3 a);
	void Draw();
	void updateObject(const float delta);
	void applyTexture(std::shared_ptr<Texture> texture);
	void rotate(float degree, glm::vec3 axis);

	Shader& getShader();
};