#pragma once
#include "DrawableObject.h"
//Include GLFW
#include <GLFW/glfw3.h>

class Scene
{
private:
	DrawableObject drawable_object;
	DrawableObject drawable_object2;
	GLFWwindow* window;

	void Loop(); //main while loop for window
public:
	Scene(GLFWwindow* window);

	void Run();
};