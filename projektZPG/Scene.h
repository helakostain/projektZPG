#pragma once
#include "DrawableObject.h"
//Include GLFW
#include <GLFW/glfw3.h>
#include "Models.h"

class Scene
{
private:
	DrawableObject drawable_object;
	GLFWwindow* window;

	void Loop(); //main while loop for window
public:
	Scene(GLFWwindow* window);

	void Run();
};