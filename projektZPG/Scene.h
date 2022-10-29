#pragma once

#include <chrono>
#include <optional>
#include <iostream>
#include <functional>
#include <vector>

#include "DrawableObject.h"
#include "Camera.hpp"
#include "Shader.h"
#include "Callbacks.h"
#include "Observer.h"
#include "Light.h"

//Include GLFW
#include <GLFW/glfw3.h> // DO NOT MOVE UP!!!!!!

class Scene
{
private:
	typedef decltype(std::chrono::high_resolution_clock::now()) TimePoint;
	typedef std::chrono::duration<double, std::ratio<1>> Second;

	Camera *camera;
	GLFWwindow* window;
	Mouse& mouse = Mouse::instance();
	AmbientLight ambientLight{ glm::vec3 { 0.1f} };
	PositionedLight light{ glm::vec3 { 1.f }, glm::vec3 { 0.f } };

	void Loop(); //main while loop for window
public:
	Scene(GLFWwindow* window);

	std::vector<DrawableObject> drawable_object;

	void Run();
};