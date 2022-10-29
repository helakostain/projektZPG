#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLM  
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "Camera.hpp"

class Models
{
private:
	GLuint VBO; //vertex buffer object (VBO)
	GLuint VAO; //Vertex Array Object (VAO)

	const float* points;
	int size_points;

	void GenerateVBO();
	void GenerateVAO();
public:
	Models();
	Models(const float in_points[], int size_points);

	void Init(); //for generating VBO and VAO
	void Bind(); //binding vertex array
};