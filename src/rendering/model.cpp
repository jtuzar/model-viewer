#include "assets/mesh.hpp"
#include "rendering/model.hpp"
#include "rendering/internal/gl_buffer.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_program.hpp"
#include <glad/gl.h>

Model::Model(const Mesh& mesh, const ShaderProgram& shaderProgram, OpenGlContext&)
    : shaderProgram_{shaderProgram},
      vertexBuffer_{rendering::createVbo(mesh.vertices, GL_STATIC_DRAW)},
      elementBuffer_{rendering::createEbo(mesh.indices, GL_STATIC_DRAW)},
      vertexArray_{vertexBuffer_.getName(), elementBuffer_.getName()},
      verticesCount_{mesh.vertices.size()},
      indicesCount_{mesh.indices.size()} {};

void Model::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    shaderProgram_.use();

    vertexArray_.bind();
    glDrawElements(GL_TRIANGLES, indicesCount_, GL_UNSIGNED_INT, nullptr);
}
