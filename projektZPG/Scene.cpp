#include "Scene.h"
//#include "Sphere.h"
#include "Models/sphere.h"
#include "Models/gift.h"
#include "Models/plain.h"
#include "Models/suzi_flat.h"
#include "Models/suzi_smooth.h"
#include "Models/tree.h"
#include "Bushes.h"
#include "ShaderInstances.h"

#define draw_objects 150

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
	/*for (int j = 0; j < lights.size(); j++) {
		lights[j].apply();
	}*/
	ambientLight.apply();
	applyLights();
	
	while (!glfwWindowShouldClose(window)) {  //main while loop for constant rendering of scene
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color and depth buffer

		const TimePoint now = std::chrono::high_resolution_clock::now(); //new current time
		const float delta = std::chrono::duration_cast<Second>(now - lastTime).count(); //change of before and now time

		/*for (int j = 0; j < lights.size(); j++) {
			lights[j].apply();
		}*/
		ambientLight.apply();
		applyLights();
		if (test == 4)
		{
			//this->lights[1].move(glm::vec3(0.0f, 4.0f, -4.5f));
			//light.setPosition((glm::vec3(0.0f, 4.0f, -4.5f)));
		}
		else
		{
			//this->lights[1].move(glm::vec3(0.0f, 0.0f, -4.5f));
			//light.setPosition((glm::vec3(0.0f, 0.0f, -4.5f)));
		}
		//light.setPosition(glm::vec3(1.0f + sin(glfwGetTime()) * 2.0f, sin(glfwGetTime() / 2.0f) * 1.0f, 0.0f));

		for (int i = 0; i < this->drawable_object.size(); i++) //apply for all draw objects
		{
			this->drawable_object[i].SetUp();
			this->drawable_object[i].DoTransformations(delta);
			this->drawable_object[i].sendShaderMatrix();
			this->drawable_object[i].Draw();
			//glDrawArrays(GL_TRIANGLES, 0, 2880); //mode,first,count
			if (test == 4)
			{
				for (int j = 0; j < 12; j++) {
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
					else if (j >= 9 && j < 12)
					{
						glDrawArrays(GL_TRIANGLES, 0, sizeof(sphere) / 6); //mode,first,count
					}
					else if (j >= 12)
					{
						for (int i = 12; i < draw_objects; i++) {
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
		camera->update(delta);
		glfwPollEvents(); // update other events like input handling
		glfwSwapBuffers(window); // put the stuff weve been drawing onto the display
	}
}

size_t Scene::lightCount() const
{
	return lights.size();
}

void Scene::emplaceAmbientLight(glm::vec3 color)
{
	ambientLight = AmbientLight{ color };
	ambientLight.registerObserver(ShaderInstances::constant());
	ambientLight.registerObserver(ShaderInstances::lambert());
	ambientLight.registerObserver(ShaderInstances::phong());
	ambientLight.registerObserver(ShaderInstances::blinn());
}

void Scene::initAndEmplace(std::shared_ptr<ColoredLight>& light)
{
	light->registerObserver(ShaderInstances::constant());
	light->registerObserver(ShaderInstances::lambert());
	light->registerObserver(ShaderInstances::phong());
	light->registerObserver(ShaderInstances::blinn());
	light->lightIndex = this->lights.size();
	this->lights.emplace_back(light);
}

void Scene::emplaceLight(const glm::vec3 color, const glm::vec3 pos, const gl::Light type)
{
	std::shared_ptr<ColoredLight> light = createLight(color, pos, type);
	this->drawable_object.emplace_back(sphere, sizeof(sphere), ShaderInstances::constant());
	this->drawable_object.back().Pos_mov(pos);
	this->drawable_object.back().Pos_mov(glm::vec3(0.f, 0.f, 0.1f));
	this->drawable_object.back().Pos_scale(0.25);
	initAndEmplace(light);
	applyLights();
}

void Scene::emplaceLight(glm::vec3 color, glm::vec3 pos, glm::vec3 dir, float cutoff)
{
	std::shared_ptr<ColoredLight> light = std::make_shared<Spotlight>(color, pos, dir, cutoff);
	this->drawable_object.emplace_back(sphere, sizeof(sphere), ShaderInstances::constant());
	this->drawable_object.back().Pos_mov(pos);
	this->drawable_object.back().Pos_mov(glm::vec3(0.f, 0.f, 0.1f));
	this->drawable_object.back().Pos_scale(0.25);
	initAndEmplace(light);
	applyLights();
}

std::shared_ptr<ColoredLight> Scene::createLight(glm::vec3 color, glm::vec3 data, gl::Light type)
{
	if (type == gl::Light::Point)
	{
		return std::make_shared<PositionedLight>(color, data);
	}
	else if (type == gl::Light::Directional) {
		return std::make_shared<DirectionalLight>(color, data);
	}
	throw std::runtime_error("Unsupported light type");
}

void Scene::applyLights() const
{
	setShaderCount();
	for (const auto& light : lights)
	{
		light->apply();
	}
}

void Scene::setShaderCount() const
{
	ShaderInstances::blinn().passUniformLocation("lightCount", lights.size());
	ShaderInstances::lambert().passUniformLocation("lightCount", lights.size());
	ShaderInstances::phong().passUniformLocation("lightCount", lights.size());
}

Scene::Scene(GLFWwindow* in_window, int test)
{
	this->test = test;
	this->window = in_window;
	if (test == 1)
	{
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), ShaderInstances::phong()));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), ShaderInstances::phong()));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), ShaderInstances::phong()));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), ShaderInstances::phong()));
	}
	else if (test == 2)
	{
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), "LightShader.txt", "PhongBroken.txt"));
	}
	else if (test == 3)
	{
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), ShaderInstances::phong()));
	}
	else if (test == 4)
	{
		srand(time(NULL));
		this->drawable_object.emplace_back(DrawableObject(suziFlat, sizeof(suziFlat)/4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(50, 2.f, -5));
		this->drawable_object.emplace_back(DrawableObject(suziFlat, sizeof(suziFlat)/4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(2, 2.f, 8));
		this->drawable_object.emplace_back(DrawableObject(suziSmooth, sizeof(suziSmooth) / 4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(16, 2.f, -10));
		this->drawable_object.emplace_back(DrawableObject(suziSmooth, sizeof(suziSmooth) / 4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(4, 2.f, 2));
		this->drawable_object.emplace_back(DrawableObject(gift, sizeof(gift)/4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(4, 0.f, 2));
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, ShaderInstances::constant()));
		this->drawable_object.back().Pos_mov(glm::vec3(0.f, 0.f, 0.f));
		this->drawable_object.back().Pos_scale(60);
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(0.f, 20.f, 0.f));
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(8, 15.f, 9));
		this->drawable_object.emplace_back(DrawableObject(plain, sizeof(plain)/4, ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(2, 10.f, 15));
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), ShaderInstances::phong()));
		this->drawable_object.back().Pos_mov(glm::vec3(-5, 2.f, 10));

		for (int i = 10; i < draw_objects; i++) {
			if (i % 2 == 0) {
				this->drawable_object.emplace_back(DrawableObject(tree, sizeof(tree)/4, ShaderInstances::lambert()));
				float x = ((float)rand() / (float)(RAND_MAX)) * 50;
				float z = ((float)rand() / (float)(RAND_MAX)) * 50;
				this->drawable_object.back().Pos_mov(glm::vec3(x, 0.f, z));
			}
			else {
				Bushes bush = Bushes();
				this->drawable_object.emplace_back(DrawableObject(bush.points_plain, bush.size_points, ShaderInstances::blinn()));
				float x = ((float)rand() / (float)(RAND_MAX)) * 50;
				float z = ((float)rand() / (float)(RAND_MAX)) * 50;
				this->drawable_object.back().Pos_mov(glm::vec3(x, 0.f, z));
				this->drawable_object.back().Pos_scale(3);
			}
		}
	}
	else
	{
		this->drawable_object.emplace_back(DrawableObject(sphere, sizeof(sphere), ShaderInstances::phong()));
	}

	camera = new Camera();
	camera->registerObserver(ShaderInstances::blinn());
	camera->registerObserver(ShaderInstances::constant());
	camera->registerObserver(ShaderInstances::lambert());
	camera->registerObserver(ShaderInstances::phong());

	emplaceLight(glm::vec3{ 1.f }, glm::vec3{ 0.0f, 4.0f, -4.5f }, gl::Light::Point);
	emplaceLight(glm::vec3{ 1.f }, glm::vec3{ 0.f, 4.f, 8.0f }, gl::Light::Point);
	emplaceAmbientLight(glm::vec3{ .1f });
	/*for (int i = 0; i < drawable_object.size(); i++)
	{
		camera->registerObserver(this->drawable_object[i].getShader()); //adding all draw objects to camera as observer
		for (int j = 0; j < lights.size(); j++)
		{
			lights[j].registerObserver(drawable_object[i].getShader());
		}
		//ambientLight.registerObserver(this->drawable_object[i].getShader());
		//light.registerObserver(this->drawable_object[i].getShader());
	}*/
	mouse.instance().registerObserver(*camera); 
	
	Callbacks::Init(window, std::ref(drawable_object), camera); //Initialize Callbacks with drawable object and camera
}

void Scene::Run()
{
	Loop();
}