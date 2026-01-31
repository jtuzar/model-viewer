#include "assets/mesh.hpp"
#include "rendering/model.hpp"
#include "rendering/internal/gl_buffer.hpp"
#include "rendering/shader_program.hpp"
#include <glad/gl.h>

Model::Model(const Mesh& mesh, ShaderProgram shaderProgram)
    : shaderProgram_{shaderProgram},
      vertexBuffer_{rendering::createVbo(mesh.vertices, GL_STATIC_DRAW)},
      elementBuffer_{rendering::createEbo(mesh.indices, GL_STATIC_DRAW)},
      vertexArray_{vertexBuffer_.getName(), elementBuffer_.getName()},
      verticesCount_{mesh.vertices.size()},
      indicesCount_{mesh.indices.size()} {};

void Model::makeActive() const {
    shaderProgram_.use();
    vertexArray_.bind();
}
