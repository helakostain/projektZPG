#pragma once
#include "Observer.h"

#include <glm/vec3.hpp>

#include <vector>
#include <functional>
#include <cmath>

enum class LightType {
    Default,
    Ambient
};

class ColoredLight : public Observable {

protected:

    glm::vec3 color{ 0.f, 0.f, 1.f };

public:
    ColoredLight();
    ColoredLight(glm::vec3 color);

    virtual void addColor(glm::vec3 delta);
    virtual void setColor(glm::vec3 color);
    virtual glm::vec3 getColor();
    virtual LightType type();

    virtual void apply();
};

class PositionedLight : public ColoredLight {

    glm::vec3 color{ 0.f, 0.f, 1.f };
    glm::vec3 position{ 0.f };

    void onPositionChanged(LightType lightType);

public:
    PositionedLight();
    PositionedLight(glm::vec3 color, glm::vec3 position);

    void move(glm::vec3 delta);
    void setPosition(glm::vec3 newPos);

    void setColor(glm::vec3 color) override;
    glm::vec3 getPosition();
    LightType type()  override;

    void apply() override;
};

typedef ColoredLight AmbientLight;