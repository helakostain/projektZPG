#pragma once

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include GLEW
#include <GL/glew.h>
#include <vector>

#include "Camera.h"

class Models
{
private:
	// Projection matrix : 45 Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection;
	// Camera matrix
	glm::mat4 View;
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model;

	GLuint VBO; //vertex buffer object (VBO)
	GLuint VAO; //Vertex Array Object (VAO)

	float* points; //quad for display with colours

	int size_points;

	static float points_old[];

	void GenerateVBO();
	void GenerateVAO();
public:
	Models();
	Models(float in_points[], int size_points);

	void Init(); //for generating VBO and VAO
	void Bind(); //binding vertex array
};