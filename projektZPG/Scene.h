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
#include "Light.hpp"

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
	//AmbientLight ambientLight{ glm::vec3 { 0.1f} };
	//PositionedLight light{ glm::vec3 { 1.f }, glm::vec3 { 0.f } };
	std::vector<std::shared_ptr<ColoredLight>> lights;
	AmbientLight ambientLight;
	int test;
	
	void Loop(); //main while loop for window

	size_t lightCount() const;
	void emplaceAmbientLight(glm::vec3 color);
	void initAndEmplace(std::shared_ptr<ColoredLight>& light);
	void emplaceLight(const glm::vec3 color, const glm::vec3 pos, const gl::Light type);
	void emplaceLight(glm::vec3 color, glm::vec3 pos, glm::vec3 dir, float cutoff);
	std::shared_ptr<ColoredLight> createLight(glm::vec3 color, glm::vec3 data, gl::Light type);
	void applyLights() const;
	void setShaderCount() const;
public:
	Scene(GLFWwindow* window, int test);

	std::vector<DrawableObject> drawable_object;

	void Run();
};