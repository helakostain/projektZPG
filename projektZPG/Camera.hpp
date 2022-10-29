#pragma once
#define _USE_MATH_DEFINES

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include <math.h>
#include <functional>
#include <vector>

#include "Mouse.h"
#include "Transformation.h"
#include "Observer.h"


class Camera : public Observer, public Observable
{
private:
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)4.f / 3.f, 0.1f, 100.0f);

	glm::vec3 eye{ 0.f, 1.f, 3.f }; // Camera is at (4,3,-3), in World Space
	glm::vec3 target{ 0.f, 0.f, 0.f }; // and looks at the origin
	glm::vec3 up{ 0.f, 1.f, 0.f };  // Head is up (set to 0,-1,0 to look upside-down)

	float fi = 1.5f * M_PI;
	float psi = 0.f;

	int sidewaysMovement = 0;
	int forwardMovement = 0;
	int hRotate = 0;
	int vRotate = 0;

	bool changeMade = false;

	glm::mat4 camera;

	static constexpr float moveSpeed = 3.f;
	static constexpr float rotationSpeed = 1.f;
	static constexpr float dragSpeed = 0.3f;

	void updateCameraMatrix();
	void calcTarget();

	void capAngles();

	void updateAngle(float dt);
	void updateForwardMovement(float dt);
public: 
	Camera();

	void setPosition(glm::vec3 pos);

	void moveSideways(Direction dir);
	void moveForward(Direction dir);
	void rotateHor(Direction dir);
	void rotateVer(Direction dir);

	void update(float dt);

	void apply();

	void onMouseMove(const MouseData& md);
	
	void notify(EventType eventType, void* object) override;

	glm::mat4 view() const;
	glm::mat4 project() const;
	glm::vec3 position() const;
};