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

#include "Camera.hpp"

class Models
{
private:
	void GenerateVBO();
	void GenerateVAO();
protected:
	const float* points;
	int size_points;

	GLuint VBO; //vertex buffer object (VBO)
	GLuint VAO; //Vertex Array Object (VAO)
public:
	Models();
	Models(const float in_points[], int size_points);

	virtual void Init(); //for generating VBO and VAO
	virtual void Bind(); //binding vertex array
	virtual void Draw();
};