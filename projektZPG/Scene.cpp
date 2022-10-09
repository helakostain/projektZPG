#include "Scene.h"

Scene::Scene(GLFWwindow* in_window)
{
	this->window = in_window;
	this->drawable_object = DrawableObject();
}

void Scene::Loop()
{
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Shader::Init();
		//Models::Bind();
		drawable_object.SetUp();
		// draw triangles
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4); //mode,first,count
		// update other events like input handling
		glfwPollEvents();
		// put the stuff weve been drawing onto the display
		glfwSwapBuffers(window);
	}
}

void Scene::Run()
{
	//Models::Init();
	Loop();
}
