#include "Transformation.h"
#include <cmath>
#include <glm/ext/matrix_transform.hpp>

Transformation::Transformation()
{
}

const glm::mat4& Transformation::matrix() const
{
    return transform;
}

void Transformation::rotate(float degree, const glm::vec3 axis) {
	transform = glm::rotate(transform, degree, axis);
}

void Transformation::translate(const glm::vec3 delta) {
	transform = glm::translate(transform, delta);
}

void Transformation::scale(const glm::vec3 scales) {
	transform = glm::scale(transform, scales);
}

float Transformation::calcNewV(float current, const float acc, const float dec) {

	if (std::abs(current) <= dec) {
		current = 0;
	}
	else {
		current -= (-1 + (2 * (current > 0))) * dec;
	}

	return current + acc;
}


float Transformation::capV(float current, float max) {
	return std::min(std::max(current, -max), max);
}

void Transformation::updateGrowth(const float dt) {
	const auto g = 1 + growthV * (int)growthDir * dt;
	scale(glm::vec3(g));
}

void Transformation::updateRotation(const float dt) {

	const float dec = rotationDec * dt;
	const float acc = rotationAcc * dt * (int)rotationDir;

	rotationV = capV(calcNewV(rotationV, acc, dec), rotationMax);

	rotate(rotationV * dt, glm::vec3(0.f, 0.f, 1.f));
}

void Transformation::updateScale(const float dt) {

	const float dec = deceleration * dt;
	const float acc = acceleration * dt;

	const float fx = capV(calcNewV(forces.x, acc * movementDir.x, dec), maxV);
	const float fy = capV(calcNewV(forces.y, acc * movementDir.y, dec), maxV);

	forces = { fx, fy };

	translate({ fx * dt, fy * dt, 0.f });
}

void Transformation::Update(const float deltaT)
{
	updateGrowth(deltaT);
	updateRotation(deltaT);
	updateScale(deltaT);
}
