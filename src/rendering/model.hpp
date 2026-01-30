#pragma once
#include "assets/mesh.hpp"
#include "rendering/internal/gl_buffer.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_program.hpp"
#include "rendering/vertex_array.hpp"
class Model {
   public:
    Model(const Mesh&, const ShaderProgram&, OpenGlContext&);
    void draw();

   private:
    unsigned long verticesCount_;
    unsigned long indicesCount_;
    const ShaderProgram& shaderProgram_;
    rendering::GLBuffer vertexBuffer_;
    rendering::GLBuffer elementBuffer_;
    VertexArray vertexArray_;
};
