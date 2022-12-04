#pragma once

#include <chrono>
#include <optional>
#include <iostream>
#include <functional>
#include <vector>

#include "DrawableObject.hpp"
#include "Camera.hpp"
#include "Shader.h"
#include "Callbacks.h"
#include "Observer.h"
#include "Light.hpp"
#include "Skybox.h"
#include "Texture.hpp"

//Include GLFW
#include <GLFW/glfw3.h> // DO NOT MOVE UP!!!!!!

class Scene : public Observer
{
private:
	typedef decltype(std::chrono::high_resolution_clock::now()) TimePoint;
	typedef std::chrono::duration<double, std::ratio<1>> Second;

	Camera *camera;
	GLFWwindow* window;
	Mouse& mouse = Mouse::instance();
	std::vector<std::shared_ptr<ColoredLight>> lights;
	AmbientLight ambientLight;
	std::shared_ptr<Skybox> skybox;
	int test;
	
	void Loop(); //main while loop for window

	size_t lightCount() const;
	void emplaceAmbientLight(glm::vec3 color);
	void initAndEmplace(std::shared_ptr<ColoredLight>& light);
	void emplaceLight(const glm::vec3 color, const glm::vec3 pos, const gl::Light type);
	void emplaceLight(glm::vec3 color, glm::vec3 pos, glm::vec3 dir, float cutoff);
	std::shared_ptr<ColoredLight> createLight(glm::vec3 color, glm::vec3 data, gl::Light type);
	void applyLights() const;
	void placeModel(const int mouseX, const int mouseY);
	void setShaderCount() const;

	void onButtonPress(const MouseData& mouseData);
public:
	Scene(GLFWwindow* window, int test);

	std::vector<DrawableObject> drawable_object;

	void Run();

	void notify(EventType eventType, void* object);
};