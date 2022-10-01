#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

class Application
{
private:
	// Projection matrix : 45 Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection;
	// Camera matrix
	glm::mat4 View;
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model;

	static float points[];

	const char* vertex_shader;

	const char* fragment_shader;
public:
	Application();
	~Application();

	static void error_callback(int error, const char* description) { fputs(description, stderr); }

	void Run();
};