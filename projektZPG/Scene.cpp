#include "Scene.h"
float points[]{
		-0.9f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 
		-0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.45f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f };
float points2[]{
	0.9f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
	0.45f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f };

Scene::Scene(GLFWwindow* in_window)
{
	this->window = in_window;
	
	
}


void Scene::Loop()
{
	this->drawable_object.push_back(DrawableObject(points, sizeof(points)));
	this->drawable_object.push_back(DrawableObject(points2, sizeof(points2)));
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (int i = 0; i < this->drawable_object.size(); i++)
		{
			this->drawable_object[i].SetUp();
			//glDrawArrays(GL_TRIANGLE_FAN, 0, 4); //mode,first,count
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
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
