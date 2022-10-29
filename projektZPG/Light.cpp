#include "Light.h"


static float boundColor(const float color) {
	return std::max(std::min(1.f, color), 0.f);
}

static glm::vec3 boundColor(const glm::vec3 color) {
	return { boundColor(color.x), boundColor(color.y), boundColor(color.z) };
}

ColoredLight::ColoredLight() = default;

ColoredLight::ColoredLight(const glm::vec3 color) : color(boundColor(color)) { }

void ColoredLight::addColor(glm::vec3 delta) {
	setColor(color + delta);
}

void ColoredLight::setColor(const glm::vec3 newColor) {
	color = boundColor(newColor);
	apply();
}

glm::vec3 ColoredLight::getColor()
{
	return color;
}

LightType ColoredLight::type() {
	return LightType::Ambient;
}

void ColoredLight::apply() {
	notifyObservers(EventType::LightChanged, (void*)this);
}

PositionedLight::PositionedLight() : ColoredLight() { }

PositionedLight::PositionedLight(const glm::vec3 color, const glm::vec3 position) : ColoredLight(color), position(position) { }

void PositionedLight::move(const glm::vec3 delta) {
	setPosition(position + delta);
}

void PositionedLight::setPosition(const glm::vec3 newPos) {
	position = newPos;
	apply();
}

void PositionedLight::setColor(const glm::vec3 newColor) {
	color = boundColor(newColor);
	apply();
}

glm::vec3 PositionedLight::getPosition() {
	return position;
}

LightType PositionedLight::type() {
	return LightType::Default;
}

void PositionedLight::apply()
{
	notifyObservers(EventType::LightChanged, (void*)this);
}