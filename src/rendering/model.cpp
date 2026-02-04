#include "assets/mesh.hpp"
#include "rendering/model.hpp"
#include "assets/vertex.hpp"
#include "rendering/internal/gl_buffer.hpp"
#include <glad/gl.h>
#include <cstddef>

Model::Model(const Mesh& mesh, const ShaderType shaderType)
    : shaderType_{shaderType},
      vertexBuffer_{rendering::createVbo(mesh.vertices, GL_STATIC_DRAW)},
      verticesCount_{mesh.vertices.size()},
      indicesCount_{mesh.indices.size()} {
    vertexArray_.bindVbo(vertexBuffer_.getName());
    vertexArray_.setAttribute(0, glm::vec3::length(), GL_FLOAT, false, offsetof(Vertex, position));
    vertexArray_.setAttribute(1, glm::vec3::length(), GL_FLOAT, false, offsetof(Vertex, normal));
    vertexArray_.setAttribute(2, glm::vec2::length(), GL_FLOAT, false, offsetof(Vertex, uv));

    if (!mesh.indices.empty()) {
        elementBuffer_ = rendering::createEbo(mesh.indices, GL_STATIC_DRAW);
        vertexArray_.bindEbo(elementBuffer_->getName());
    }
};

void Model::bindForDraw() const {
    vertexArray_.bind();
}
