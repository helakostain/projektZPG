#pragma once
#include <memory>

#include "Shader.h"
#include "Texture.hpp"
#include "ShaderInstances.h"

class Skybox {

    std::vector<float> points;
    std::shared_ptr<Texture> cubeMap;
    Shader* shader;
    GLuint VBO = 0;
    GLuint VAO = 0;

public:
    Skybox(std::shared_ptr<Texture> cubeMap);
    void draw();
    void Models_init();
    void bind_array();
};