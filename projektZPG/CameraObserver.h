#pragma once

#include <glm/mat4x4.hpp>

struct CameraObserver {

    virtual void updateView(const glm::mat4& view) = 0;
    virtual void updateProjection(const glm::mat4& projection) = 0;

};