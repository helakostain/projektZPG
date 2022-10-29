#include "Scene.h"
//#include "Sphere.h"
#include "Models/sphere.h"

void Scene::Loop()
{
	TimePoint lastTime = std::chrono::high_resolution_clock::now(); //current time

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear window content
	glEnable(GL_DEPTH_TEST);

	this->drawable_object[0].Pos_mov(glm::vec3(-2.0f, 0.0f, -4.5f)); //top left sphere
	this->drawable_object[1].Pos_mov(glm::vec3(0.0f, -2.0f, -4.5f)); //bottom left sphere
	this->drawable_object[2].Pos_mov(glm::vec3(0.0f, 2.0f, -4.5f)); //top right sphere
	this->drawable_object[3].Pos_mov(glm::vec3(2.0f, 0.0f, -4.5f)); //bottom right sphere

	for (int i = 0; i < this->drawable_object.size(); i++) //first draw of scene
	{
		this->drawable_object[i].SetUp();
		this->drawable_object[i].DoTransformations(0.f);
		this->drawable_object[i].sendShaderMatrix();
		camera->update(1.f);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(sphere) / 6); //mode,first,count
	}
	glfwPollEvents(); // update other events like input handling
	glfwSwapBuffers(window); // put the stuff weve been drawing onto the display
	camera->apply(); //applying camera
	ambientLight.apply();
	light.apply();
	
	while (!glfwWindowShouldClose(window)) {  //main while loop for constant rendering of scene
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color and depth buffer

		const TimePoint now = std::chrono::high_resolution_clock::now(); //new current time
		const float delta = std::chrono::duration_cast<Second>(now - lastTime).count(); //change of before and now time

		ambientLight.apply();
		light.apply();
		light.setPosition((glm::vec3(0.0f, 0.0f, -4.5f)));
		//light.setPosition(glm::vec3(1.0f + sin(glfwGetTime()) * 2.0f, sin(glfwGetTime() / 2.0f) * 1.0f, 0.0f));

		for (int i = 0; i < this->drawable_object.size(); i++) //apply for all draw objects
		{
			this->drawable_object[i].SetUp();
			this->drawable_object[i].DoTransformations(delta);
			this->drawable_object[i].sendShaderMatrix();
			this->drawable_object[i].Draw();
			camera->update(delta);
			glDrawArrays(GL_TRIANGLES, 0, 2880); //mode,first,count
			lastTime = now;
		}
		glfwPollEvents(); // update other events like input handling
		glfwSwapBuffers(window); // put the stuff weve been drawing onto the display
	}
}

Scene::Scene(GLFWwindow* in_window)
{
	this->window = in_window;
	//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt")); //add 4 spheres to draw object
	//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt"));
	//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt"));
	//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt"));
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
	this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
	camera = new Camera();

	for (int i = 0; i < drawable_object.size(); i++) 
	{
		camera->registerObserver(this->drawable_object[i].getShader()); //adding all draw objects to camera as observer
		ambientLight.registerObserver(this->drawable_object[i].getShader());
		light.registerObserver(this->drawable_object[i].getShader());
	}
	mouse.instance().registerObserver(*camera); 
	
	Callbacks::Init(window, std::ref(drawable_object), camera); //Initialize Callbacks with drawable object and camera
}

void Scene::Run()
{
	Loop();
}