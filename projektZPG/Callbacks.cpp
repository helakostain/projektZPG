#include "Callbacks.h"

double Callbacks::clickX = 0;
double Callbacks::clickY = 0;

void Callbacks::error_callback(int error, const char* description)
{
	printf("This error callback\n");
	fputs(description, stderr);
}

void Callbacks::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Callbacks::cursor_callback(GLFWwindow* window, double x, double y)
{
	printf("cursor_callback %d, %d; %d, %d \n", (int)x, (int)y, (int)clickX, (int)clickY);
}

void Callbacks::button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (action == GLFW_PRESS)
	{
		printf("button_callback [%d,%d,%d]\n", button, action, mode);
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			glfwGetCursorPos(window, &clickX, &clickY);
		}
	}
	
}

void Callbacks::window_focus_callback(GLFWwindow* window, int focused)
{
	printf("window_focus_callback \n");
}

void Callbacks::window_iconify_callback(GLFWwindow* window, int iconified)
{
	printf("window_iconify_callback \n");
}

void Callbacks::window_size_callback(GLFWwindow* window, int width, int height)
{
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

Callbacks::Callbacks()
{

}

Callbacks::~Callbacks()
{

}

void Callbacks::Init(GLFWwindow* window)
{
	glfwSetErrorCallback(Callbacks::error_callback);
	glfwSetKeyCallback(window, Callbacks::key_callback);
	glfwSetCursorPosCallback(window, Callbacks::cursor_callback);
	glfwSetMouseButtonCallback(window, Callbacks::button_callback);
	glfwSetWindowFocusCallback(window, Callbacks::window_focus_callback);
	glfwSetWindowIconifyCallback(window, Callbacks::window_iconify_callback);
	glfwSetWindowSizeCallback(window, Callbacks::window_size_callback);
}