#pragma once
#include "DrawableObject.h"
//Include GLFW
#include <GLFW/glfw3.h>
#include <chrono>

class Scene
{
private:
	typedef decltype(std::chrono::high_resolution_clock::now()) TimePoint;
	typedef std::chrono::duration<double, std::ratio<1>> Second;

	std::vector<DrawableObject> drawable_object;
	GLFWwindow* window;

	void Loop(); //main while loop for window
public:
	Scene(GLFWwindow* window);

	void Run();
};