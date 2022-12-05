#include <stdio.h>
#include <iostream>
#include "Application.h"

int main(void)
{
	/*//inicializace konkretni verze
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,
	GLFW_OPENGL_CORE_PROFILE);  //*/
	int test = 0;
	std::cout << "4 spheres with phong light in middle (1); more than 100 objects (2)" << endl;
	std::cout << "Write number (1-2) of test to display: ";
	std::cin >> test;
	std::cout << endl;

	Application::getInstance().Run(test);
	exit(EXIT_SUCCESS);
}