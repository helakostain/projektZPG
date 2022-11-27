#include "Mesh.hpp"


void Mesh::bindAndDraw(const unsigned int id, Shader* shader) const {

    if (texture) {
        texture->bind(shader);
    }

    glStencilFunc(GL_ALWAYS, id, 0xFF);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::shared_ptr<Texture> tex, const Material& material) :
    vertices(std::move(vertices)), indices(std::move(indices)), texture(std::move(tex)), material(material) {

    init();
}

void Mesh::init() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(decltype(vertices)::value_type), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(decltype(indices)::value_type), indices.data(), GL_STATIC_DRAW);

    /* Vertex positions */
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(decltype(vertices)::value_type), nullptr);

    /* Vertex normals */
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(decltype(vertices)::value_type), (void*)sizeof(Vertex::position));

    /* Texture coordinates */
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(decltype(vertices)::value_type),
        (void*)(sizeof(Vertex::position) + sizeof(Vertex::normal)));

    glBindVertexArray(0);
}

Mesh::Mesh(Mesh&& mesh) noexcept :
    vertices(std::move(mesh.vertices)), indices(std::move(mesh.indices)), texture(std::move(mesh.texture)),
    vbo(mesh.vbo), vao(mesh.vao), ebo(mesh.ebo), material(mesh.material) { }