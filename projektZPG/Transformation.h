#pragma once
#include <GL/glew.h>
#include <glm/mat4x4.hpp> // glm::mat4
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
	static constexpr float growthV = 1.0;
	glm::vec2 forces{ 0.f, 0.f };

	static constexpr float rotationDec = 1.0;
	static constexpr float rotationAcc = 10.5;
	static constexpr float rotationMax = 10.0;

	static constexpr float acceleration = 1.0;
	static constexpr float deceleration = 0.5;
	static constexpr float maxV = 10.0;

	static float capV(float current, float max);
	static float calcNewV(float current, float acc, float dec);

	void rotate(float degree, glm::vec3 axis);
	//void translate(glm::vec3 delta);
	void scale(glm::vec3 scales);

	static float getAcc(Direction dir);

	void updateForces(const float dt);
	void updateRotation(const float dt);
	void updateGrowth(const float dt);
public:
	Transformation();
	void translate(glm::vec3 delta);
	const glm::mat4& matrix() const;

	void Update(const float deltaT);

	void applyForce(Direction dx, Direction dy);
	void applyFx(Direction dir);
	void applyFy(Direction dir);

	void setGrowth(Growth growth);
	void setRotation(Rotation rotation);
};