#include "rendering/renderer.hpp"
#include "rendering/shader_program.hpp"
#include <glad/gl.h>

void Renderer::submit(const Mesh& mesh, const ShaderProgram& shaderProgram) {
    models_.emplace_back(mesh, shaderProgram);
}

void Renderer::draw() const {
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& model : models_) {
        model.bindForDraw();

        if (model.isIndexed()) {
            glDrawElements(GL_TRIANGLES, model.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
        } else {
            glDrawArrays(GL_TRIANGLES, 0, model.getVerticesCount());
        }
    }
}
