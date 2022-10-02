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
	GLFWwindow* window;

	static Application* instance;
	void StartGLEW();
	void VersionInfo();
public:
	Application();
	~Application();

	static Application& getInstance();

	void Run();
};