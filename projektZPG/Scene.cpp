#include "Scene.h"
//#include "Sphere.h"
#include "Models/sphere.h"
#include "Models/gift.h"
#include "Models/plain.h"
#include "Models/suzi_flat.h"
#include "Models/suzi_smooth.h"
#include "Models/tree.h"
#include "Bushes.h"

#define draw_objects 300

void Scene::Loop()
{
	TimePoint lastTime = std::chrono::high_resolution_clock::now(); //current time

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear window content
	glEnable(GL_DEPTH_TEST);
	if (test == 1)
	{
		this->drawable_object[0].Pos_mov(glm::vec3(-2.0f, 0.0f, -4.5f)); //top left sphere
		this->drawable_object[1].Pos_mov(glm::vec3(0.0f, -2.0f, -4.5f)); //bottom left sphere
		this->drawable_object[2].Pos_mov(glm::vec3(0.0f, 2.0f, -4.5f)); //top right sphere
		this->drawable_object[3].Pos_mov(glm::vec3(2.0f, 0.0f, -4.5f)); //bottom right sphere
	}
	else if (test == 2)
	{
		this->drawable_object[0].Pos_mov(glm::vec3(0.0f, 1.0f, -2.0f)); //top left sphere 4,3,-3
	}
	else if (test == 3)
	{
		this->drawable_object[0].Pos_mov(glm::vec3(0.0f, 1.0f, -2.0f)); //top left sphere 4,3,-3
	}
	else if (test == 4)
	{
	}
	else
	{
	}

	for (int i = 0; i < this->drawable_object.size(); i++) //first draw of scene
	{
		this->drawable_object[i].SetUp();
		this->drawable_object[i].DoTransformations(0.f);
		this->drawable_object[i].sendShaderMatrix();
		camera->update(1.f);
		if (test == 4)
		{
			for (int j = 0; j < 10; j++) {
				if (j < 4) {
					glDrawArrays(GL_TRIANGLES, 0, 2904);
				}
				else if (j == 4) {
					glDrawArrays(GL_TRIANGLES, 0, 66624);
				}
				else if (j > 4 && j < 9)
				{
					glDrawArrays(GL_TRIANGLES, 0, 6);
				}
				else if (j == 9)
				{
					glDrawArrays(GL_TRIANGLES, 0, sizeof(sphere) / 6); //mode,first,count
				}
				else if (j > 9)
				{
					for (int i = 10; i < draw_objects; i++) {
						if (i % 2 == 0) {
							glDrawArrays(GL_TRIANGLES, 0, 92814);
						}
						else {
							glDrawArrays(GL_TRIANGLES, 0, 8730);
						}
					}
				}
			}
		}
		else
		{
			glDrawArrays(GL_TRIANGLES, 0, sizeof(sphere) / 6); //mode,first,count
		}
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
		if (test == 4)
		{
			light.setPosition((glm::vec3(0.0f, 4.0f, -4.5f)));
		}
		else
		{
			light.setPosition((glm::vec3(0.0f, 0.0f, -4.5f)));
		}
		//light.setPosition(glm::vec3(1.0f + sin(glfwGetTime()) * 2.0f, sin(glfwGetTime() / 2.0f) * 1.0f, 0.0f));

		for (int i = 0; i < this->drawable_object.size(); i++) //apply for all draw objects
		{
			this->drawable_object[i].SetUp();
			this->drawable_object[i].DoTransformations(delta);
			this->drawable_object[i].sendShaderMatrix();
			this->drawable_object[i].Draw();
			camera->update(delta);
			//glDrawArrays(GL_TRIANGLES, 0, 2880); //mode,first,count
			if (test == 4)
			{
				for (int j = 0; j < 10; j++) {
					if (j < 4) {
						glDrawArrays(GL_TRIANGLES, 0, 2904);
					}
					else if( j == 4) {
						glDrawArrays(GL_TRIANGLES, 0, 66624);
					}
					else if (j > 4 && j < 9)
					{
						glDrawArrays(GL_TRIANGLES, 0, 6);
					}
					else if (j == 9)
					{
						glDrawArrays(GL_TRIANGLES, 0, sizeof(sphere) / 6); //mode,first,count
					}
					else if (j > 9)
					{
						for (int i = 10; i < draw_objects; i++) {
							if (i % 2 == 0) {
								glDrawArrays(GL_TRIANGLES, 0, 92814);
							}
							else {
								glDrawArrays(GL_TRIANGLES, 0, 8730);
							}
						}
					}
				}
			}
			else
			{
				glDrawArrays(GL_TRIANGLES, 0, sizeof(sphere) / 6); //mode,first,count
			}
			lastTime = now;
		}
		glfwPollEvents(); // update other events like input handling
		glfwSwapBuffers(window); // put the stuff weve been drawing onto the display
	}
}

Scene::Scene(GLFWwindow* in_window, int test)
{
	this->test = test;
	this->window = in_window;
	if (test == 1)
	{
		//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt")); //add 4 spheres to draw object
		//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt"));
		//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt"));
		//this->drawable_object.emplace_back(DrawableObject(new Sphere(), "LightShader.txt", "Phong.txt"));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
	}
	else if (test == 2)
	{
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "PhongBroken.txt"));
	}
	else if (test == 3)
	{
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
	}
	else if (test == 4)
	{
		srand(time(NULL));
		this->drawable_object.emplace_back(DrawableObject(suziFlat, sizeof(suziFlat)/4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(50, 2.f, -5));
		this->drawable_object.emplace_back(DrawableObject(suziFlat, sizeof(suziFlat)/4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(2, 2.f, 8));
		this->drawable_object.emplace_back(DrawableObject(suziSmooth, sizeof(suziSmooth) / 4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(16, 2.f, -10));
		this->drawable_object.emplace_back(DrawableObject(suziSmooth, sizeof(suziSmooth) / 4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(4, 2.f, 2));
		this->drawable_object.emplace_back(DrawableObject(gift, sizeof(gift)/4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(4, 0.f, 2));
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, "LightShader.txt", "defaultfragment.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(0.f, 0.f, 0.f));
		this->drawable_object.back().Pos_scale(60);
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(0.f, 20.f, 0.f));
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(8, 15.f, 9));
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(2, 10.f, 15));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
		this->drawable_object.back().Pos_mov(glm::vec3(-5, 2.f, 10));

		for (int i = 10; i < draw_objects; i++) {
			if (i % 2 == 0) {
				this->drawable_object.emplace_back(DrawableObject(tree, sizeof(tree)/4, "LightShader.txt", "Lambert.txt"));
				float x = ((float)rand() / (float)(RAND_MAX)) * 50;
				float z = ((float)rand() / (float)(RAND_MAX)) * 50;
				this->drawable_object.back().Pos_mov(glm::vec3(x, 0.f, z));
			}
			else {
				Bushes bush = Bushes();
				this->drawable_object.emplace_back(DrawableObject(bush.points_plain, bush.size_points, "LightShader.txt", "Blinn.txt"));
				float x = ((float)rand() / (float)(RAND_MAX)) * 50;
				float z = ((float)rand() / (float)(RAND_MAX)) * 50;
				this->drawable_object.back().Pos_mov(glm::vec3(x, 0.f, z));
				this->drawable_object.back().Pos_scale(3);
			}
		}
	}
	else
	{
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "Phong.txt"));
	}

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