#pragma once
#include "assets/mesh.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_program.hpp"
#include "rendering/vertex_array.hpp"
#include "rendering/vertex_buffer.hpp"
class Model {
   public:
    explicit Model(OpenGlContext& openGlContext);
    void draw();

   private:
    Mesh mesh_;
    ShaderProgram shaderProgram_;
    VertexBuffer vertexBuffer_;
    VertexArray vertexArray_;
};
