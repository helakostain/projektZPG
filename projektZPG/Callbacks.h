#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <optional>

#include "Application.h"
#include "DrawableObject.hpp"
#include "Camera.hpp"
#include "Mouse.h"
#include "Scene.h"

class Callbacks
{
private:
	static double clickX;
	static double clickY;
	static std::vector<DrawableObject> drawableObj;
	static Camera* camera;

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
public:
	Callbacks();
	~Callbacks();

	static void Init(GLFWwindow* window, std::vector<DrawableObject>& dO, Camera *camera);
};