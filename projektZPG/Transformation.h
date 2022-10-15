#pragma once
#include <glm/mat4x4.hpp> // glm::mat4
#include <GL/glew.h>
#include <utility>
#include <exception>

enum class Growth {
	none = 0,
	grow = 1,
	shrink = -1
};

enum class Rotation {
	none = 0,
	left = 1,
	right = -1
};

enum class Direction {
	none = 0,
	up = 1,
	down = -1,
	left = -1,
	right = 1
};

class Transformation
{
private:
	glm::mat4 transform{ 1.f };

	Growth growthDir = Growth::none;
	Rotation rotationDir = Rotation::left;
	glm::vec2 movementDir{ 0.f, 0.f };

	float rotationV = 0;
	float growthV = 1.0;
	glm::vec2 forces{ 0.f, 0.f };

	float rotationDec = 1.0;
	float rotationAcc = 10.5;
	float rotationMax = 10.0;

	float acceleration = 1.0;
	float deceleration = 0.5;
	float maxV = 10.0;

	static float capV(float current, float max);
	static float calcNewV(float current, float acc, float dec);

	void rotate(float degree, glm::vec3 axis);
	void translate(glm::vec3 delta);
	void scale(glm::vec3 scales);


	void updateRotation(const float dt);
	void updateGrowth(const float dt);
	void updateScale(const float dt);
	void updateForces(float dt);
public:
	Transformation();

	const glm::mat4& matrix() const;

	void Update(const float deltaT);
};