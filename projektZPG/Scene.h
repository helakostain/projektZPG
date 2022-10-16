#pragma once
#include "DrawableObject.h"
#include "Camera.hpp"
#include "Shader.h"
#include "Callbacks.h"
//Include GLFW
#include <GLFW/glfw3.h>
#include <chrono>
#include <optional>
#include <iostream>
#include <functional>
#include <vector>

class Scene
{
private:
	typedef decltype(std::chrono::high_resolution_clock::now()) TimePoint;
	typedef std::chrono::duration<double, std::ratio<1>> Second;

	Camera camera;
	GLFWwindow* window;

	void Loop(); //main while loop for window
public:
	Scene(GLFWwindow* window);

	std::vector<DrawableObject> drawable_object;

	void Run();
};