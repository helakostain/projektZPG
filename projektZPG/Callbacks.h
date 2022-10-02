#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

class Callbacks
{
private:
	static double clickX;
	static double clickY;

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

	static void Init(GLFWwindow* window);
};