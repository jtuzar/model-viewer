#include "rendering/model.hpp"

#include "assets/vertex.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_program.hpp"
#include "rendering/vertex_array.hpp"
#include "rendering/vertex_buffer.hpp"

#include <glad/gl.h>

Model::Model(OpenGlContext& /*openGlContext*/)
    : shaderProgram_{"shaders/default.vert", "shaders/default.frag"},
      mesh_{{Vertex{.position = {-0.5F, -0.5F, 0.0F}, .uv = {0.0F, 0.0F}},
             Vertex{.position = {0.5F, -0.5F, 0.0F}, .uv = {0.0F, 0.0F}},
             Vertex{.position = {0.0F, 0.5F, 0.0F}, .uv = {0.0F, 0.0F}}}},
      vertexBuffer_{mesh_.vertices}, vertexArray_{vertexBuffer_.getName()} {}

void Model::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    shaderProgram_.use();

    vertexArray_.bind();
    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(mesh_.vertices.size()));
}
