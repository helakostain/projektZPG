#include "Scene.h"
#include "Models/sphere.h"
const float points[]{
		-0.9f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 
		-0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.45f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f };
const float points2[]{
	0.9f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
	0.45f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f };

Scene::Scene(GLFWwindow* in_window)
{
	this->window = in_window;
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere))); //add 4 spheres to draw object
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere)));
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere)));
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere)));
	camera = Camera();
	//this->drawable_object.back().Pos_mov(glm::vec3(5.f, 0.f, 0.f));

	for (int i = 0; i < drawable_object.size(); i++) {
		camera.addObserver(this->drawable_object[i].getShader()); //adding all draw objects to camera as observer
	}
	
	Callbacks::Init(window, std::ref(drawable_object), std::ref(camera)); //Initialize Callbacks with drawable object and camera as observers
}


void Scene::Loop()
{
	TimePoint lastTime = std::chrono::high_resolution_clock::now(); //current time
	//init
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear window content
	this->drawable_object[0].Pos_mov(glm::vec3(-1.5f,  2.0f, -4.5f)); //top left sphere
	this->drawable_object[1].Pos_mov(glm::vec3(-1.5f, -2.0f, -4.5f)); //bottom left sphere
	this->drawable_object[2].Pos_mov(glm::vec3(1.5f, 2.0f, -4.5f)); //top right sphere
	this->drawable_object[3].Pos_mov(glm::vec3(1.5f, -2.0f, -4.5f)); //bottom right sphere
	for (int i = 0; i < this->drawable_object.size(); i++) //first draw of scene
	{
		this->drawable_object[i].SetUp();
		this->drawable_object[i].DoTransformations(0.f);
		this->drawable_object[i].sendShaderMatrix();
		camera.update(1.f);
		//glDrawArrays(GL_TRIANGLE_FAN, 0, 4); //mode,first,count
		
		glDrawArrays(GL_TRIANGLES, 0, sizeof(sphere)/6);
		
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		
	}
	// update other events like input handling
	glfwPollEvents();
	// put the stuff weve been drawing onto the display
	glfwSwapBuffers(window);
	//end init

	camera.apply(); //applying camera

	while (!glfwWindowShouldClose(window)) {  //main while loop for constant rendering of scene
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		const TimePoint now = std::chrono::high_resolution_clock::now(); //new current time
		const float delta = std::chrono::duration_cast<Second>(now - lastTime).count(); //change of before and now time

		
		for (int i = 0; i < this->drawable_object.size(); i++) //apply for all draw objects
		{
			this->drawable_object[i].SetUp();
			this->drawable_object[i].DoTransformations(delta);
			this->drawable_object[i].sendShaderMatrix();
			//glDrawArrays(GL_TRIANGLE_FAN, 0, 4); //mode,first,count
			camera.update(delta);
			//glDrawArrays(GL_TRIANGLES, 0, 3);
			glDrawArrays(GL_TRIANGLES, 0, 2880);
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
