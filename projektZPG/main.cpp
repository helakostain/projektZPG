#include <stdio.h>
#include "Application.h"

// tridu shader(pro vertex a fragment shader), shaderprogram(dava dokupy shadery), shader manager, vertexobject, 

int main(void)
{
	/*//inicializace konkretni verze
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,
	GLFW_OPENGL_CORE_PROFILE);  //*/

	Application::getInstance().Run();
	int x = 0;
	exit(EXIT_SUCCESS);
}