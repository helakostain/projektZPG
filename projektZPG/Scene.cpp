#include "Scene.h"

Scene::Scene(GLFWwindow* in_window)
{
	this->window = in_window;
	this->drawable_object = DrawableObject(std::vector<float>{
		-0.9f, -0.6f, 0.0f, 1, 1, 1, 0, 1,
			0.0f, -0.6f, 0.0f, 1, 1, 0, 0, 1,
			-0.45f, 0.6f, 0.0f, 1, 0, 0, 0, 1});
	this->drawable_object2 = DrawableObject(std::vector<float>{
		0.0f, -0.6f, 0.0f, 1, 1, 1, 0, 1,
			0.9f, -0.6f, 0.0f, 1, 1, 0, 0, 1,
			0.45f, 0.6f, 0.0f, 1, 0, 0, 0, 1});
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
