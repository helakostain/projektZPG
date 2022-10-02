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

	static Application* instance; //singleton variable
	void StartGLEW(); //initialize GLEW
	void VersionInfo(); //Writes all Versions to console
	void Loop(); //main while loop for window
public:
	Application();
	~Application();

	static Application& getInstance(); //allows only one instance at time

	void Run();
};