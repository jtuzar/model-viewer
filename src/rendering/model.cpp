#include "assets/vertex.hpp"
#include "rendering/model.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_program.hpp"
#include "rendering/vertex_buffer.hpp"
#include "rendering/vertex_array.hpp"
#include <glad/gl.h>

Model::Model(OpenGlContext& openGlContext)
    : shaderProgram_{"shaders/default.vert", "shaders/default.frag"},
      mesh_{{Vertex{{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}}, Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}},
             Vertex{{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f}}}},
      vertexBuffer_{mesh_.vertices},
      vertexArray_{vertexBuffer_.getName()} {}

void Model::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    shaderProgram_.use();

    vertexArray_.bind();
    glDrawArrays(GL_TRIANGLES, 0, mesh_.vertices.size());
}
