#include "Skybox.h"

Skybox::Skybox(std::shared_ptr<Texture> cubeMap) : cubeMap(std::move(cubeMap)), shader(&ShaderInstances::skybox()) {

    this->points = {
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f
    };
    this->VAO = 0;
    this->VBO = 0;
    Models_init();
}

void Skybox::Models_init() {

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    int typeSize = sizeof(decltype(points)::value_type);
    glBufferData(GL_ARRAY_BUFFER, points.size() * typeSize, points.data(), GL_STATIC_DRAW);



    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);


    using type = decltype(points)::value_type;
    typeSize = sizeof(type);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * typeSize, nullptr);
}

void Skybox::bind_array() {
    glBindVertexArray(this->VAO);
}

void Skybox::draw() {

    glDepthMask(GL_FALSE);
    shader->shaderUseProgram();
    cubeMap->bind(shader);
    //glStencilFunc(GL_ALWAYS, -1, 0xFF);
    this->bind_array();
    glDrawArrays(GL_TRIANGLES, 0, points.size());
    glDepthMask(GL_TRUE);

}