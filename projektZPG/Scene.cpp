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
	this->drawable_object.emplace_back(DrawableObject(points, sizeof(points)));
	this->drawable_object.emplace_back(DrawableObject(points2, sizeof(points2)));
	this->camera.emplace();
	Callbacks::Init(window,drawable_object, camera);

	
}


void Scene::Loop()
{
	TimePoint lastTime = std::chrono::high_resolution_clock::now();
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		const TimePoint now = std::chrono::high_resolution_clock::now();
		const float delta = std::chrono::duration_cast<Second>(now - lastTime).count();

		for (int i = 0; i < this->drawable_object.size(); i++)
		{
			this->drawable_object[i].SetUp();
			this->drawable_object[i].DoTransformations(delta);
			this->drawable_object[i].sendShaderMatrix();
			//glDrawArrays(GL_TRIANGLE_FAN, 0, 4); //mode,first,count
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lastTime = now;
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
