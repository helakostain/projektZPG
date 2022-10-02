#include "Application.h"
#include "Callbacks.h"
#include "Models.h"
#include "Shader.h"

Application* Application::instance = nullptr;

void Application::StartGLEW()
{
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
}

Application::Application()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	Callbacks::Init(window);
}

Application::~Application()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

Application& Application::getInstance()
{
	if (not instance)
	{
		instance = new Application();
	}
	return *instance;
}

void Application::Run()
{
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	StartGLEW();

	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);



	Models::Init();

	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Shader::Init();
		Models::Bind();
		// draw triangles
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4); //mode,first,count
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we�ve been drawing onto the display
		glfwSwapBuffers(window);
	}

}