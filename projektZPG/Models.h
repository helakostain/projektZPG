#pragma once

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include GLEW
#include <GL/glew.h>

class Models
{
private:
	// Projection matrix : 45 Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection;
	// Camera matrix
	glm::mat4 View;
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model;

	static GLuint VBO; //vertex buffer object (VBO)
	static GLuint VAO; //Vertex Array Object (VAO)

	static float points[]; //quad for display with colours

	static void GenerateVBO();
	static void GenerateVAO();
public:
	Models();

	static void Init(); //for generating VBO and VAO
	static void Bind(); //binding vertex array
};