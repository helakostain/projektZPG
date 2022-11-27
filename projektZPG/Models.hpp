#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLM  
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

#include "Camera.hpp"
#include "Mesh.hpp"
#include "ModelsLoader.hpp"
#include "Shader.h"

class ModelsLoader;

class Models
{
private:
	friend ModelsLoader;

	void GenerateVBO();
	void GenerateVAO(int valuesInRow, int skip, int values);
protected:
	const float* points;
	int size_points;
	int valuesInRow;
	int skip;
	int values;

	GLuint VBO; //vertex buffer object (VBO)
	GLuint VAO; //Vertex Array Object (VAO)
public:
	Models();
	Models(const float in_points[], int size_points);

	virtual void Init();
	virtual void Init(int valuesInRow, int skip, int values); //for generating VBO and VAO
	virtual void Bind(); //binding vertex array
	virtual void Draw();

	void setIds(GLuint vID, GLuint fID);

	std::vector<Mesh> meshes;
	std::vector<Material> materials;
	std::string directory;

	// 3D models
	void addMesh(Mesh&& mesh);
	void draw(uint32_t id, Shader* shader) const;
};