#pragma once
//Include GLEW
#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h>

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

class Application
{
private:
	

	const char* vertex_shader;

	const char* fragment_shader;

	GLFWwindow* window;

	static Application* instance;
public:
	Application();
	~Application();

	static Application& getInstance();

	void Run();
};