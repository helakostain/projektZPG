#include "Application.h"

float Application::points[] = {
	 0.0f, 0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};

Application::Application()
{
	Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);
	View = glm::lookAt(
		glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	Model = glm::mat4(1.0f);
	vertex_shader =
		"#version 330\n"
		"layout(location=0) in vec3 vp;"
		"void main () {"
		"     gl_Position = vec4 (vp, 1.0);"
		"}";
	fragment_shader =
		"#version 330\n"
		"out vec4 frag_colour;"
		"void main () {"
		"     frag_colour = vec4 (0.0, 0.5, 1.0, 1.0);"
		"}";
}

Application::~Application()
{
}

void Application::error_callback(int error, const char* description) 
{
	fputs(description, stderr);
}

void Application::Run()
{

}