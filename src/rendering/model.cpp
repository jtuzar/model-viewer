#include "assets/mesh.hpp"
#include "rendering/model.hpp"
#include "assets/vertex.hpp"
#include "rendering/internal/gl_buffer.hpp"
#include "rendering/shader_program.hpp"
#include <glad/gl.h>
#include <cstddef>
#include <iostream>

Model::Model(const Mesh& mesh, const ShaderProgram* const shaderProgram)
    : shaderProgram_{shaderProgram},
      vertexBuffer_{rendering::createVbo(mesh.vertices, GL_STATIC_DRAW)},
      verticesCount_{mesh.vertices.size()},
      indicesCount_{mesh.indices.size()} {
    vertexArray_.bindVbo(vertexBuffer_.getName());
    vertexArray_.setAttribute(0, Vec3::componentCount, GL_FLOAT, false, offsetof(Vertex, position));
    vertexArray_.setAttribute(1, Vec3::componentCount, GL_FLOAT, false, offsetof(Vertex, normal));
    vertexArray_.setAttribute(2, Vec2::componentCount, GL_FLOAT, false, offsetof(Vertex, uv));

    if (!mesh.indices.empty()) {
        elementBuffer_ = rendering::createEbo(mesh.indices, GL_STATIC_DRAW);
        vertexArray_.bindEbo(elementBuffer_->getName());
    }
};

void Model::bindForDraw() const {
    if (!shaderProgram_) {
        std::cout << "ShaderProgram pointer is a nullptr";
        return;
    }
    shaderProgram_->use();
    vertexArray_.bind();
}
