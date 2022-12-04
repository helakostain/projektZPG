#pragma once
#include "Observer.h"

#include <glm/vec3.hpp>

#include <vector>
#include <functional>
#include <cmath>

namespace gl {
    enum class Light {
        Ambient = 0,
        Point = 1,
        Directional = 2,
        Spotlight = 3
    };
}

class ColoredLight : public Observable {
protected:
    mutable glm::vec3 color{ 1.f };

public:
    ColoredLight();
    ColoredLight(glm::vec3 color);

    std::size_t lightIndex = 0;

    virtual void addColor(glm::vec3 delta) const;
    virtual void setColor(glm::vec3 color) const;
    glm::vec3 getColor() const;
    virtual gl::Light type() const;
    virtual void setCutoff(float cutoff) const;
    virtual float getCutoff() const;
    virtual void update(const glm::vec3 newDirection, const glm::vec3 newPos);
    virtual void apply() const;
};

class PositionedLight : public ColoredLight {
    mutable glm::vec3 position{ 0.f };

public:
    PositionedLight();
    PositionedLight(glm::vec3 color, glm::vec3 position);

    void setPosition(glm::vec3 newPos) const;
    void move(glm::vec3 delta) const;

    glm::vec3 getPosition() const;
    gl::Light type() const override;
};

typedef ColoredLight AmbientLight;

class DirectionalLight : public ColoredLight {
    mutable glm::vec3 direction{ 0.f };

public:
    DirectionalLight();
    DirectionalLight(glm::vec3 color, glm::vec3 direction);

    gl::Light type() const override;
    glm::vec3 getDirection() const;
    void setDirection(glm::vec3 newDirection) const;
};

class Spotlight : public PositionedLight {
    mutable glm::vec3 direction{ 0.f };
    mutable float cutoff = 12.5;

public:
    Spotlight();
    Spotlight(glm::vec3 color, glm::vec3 position, glm::vec3 direction, float cutoff);

    gl::Light type() const override;
    glm::vec3 getDirection() const;
    void setDirection(glm::vec3 newDirection) const;
    void setCutoff(float cutoff) const override;
    void update(const glm::vec3 newDirection, const glm::vec3 newPosition) override;
    float getCutoff() const override;
};