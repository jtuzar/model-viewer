#include <glad/gl.h>
#include "rendering/opengl/renderer_opengl.hpp"
#include "rendering/opengl/shader.hpp"
#include "platform/window_context.hpp"
#include "platform/window.hpp"
#include "rendering/opengl/vertex_array.hpp"
#include "rendering/opengl/vertex_buffer.hpp"
#include "assets/vertex.hpp"
#include <filesystem>
#include <vector>

int main() {
    WindowContext windowContext;
    Window window{1920, 1080, "model-viewer", nullptr, nullptr, windowContext};
    RendererOpenGL renderer{window};

    const std::vector<Vertex> vertices{Vertex{{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}},
                                       Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}},
                                       Vertex{{0.0f, 0.5f, 0.0f}, {0.0f, 0.0f}}};

    VertexBuffer vbo{vertices};
    VertexArray vao{vbo.getName()};

    Shader shader{"shaders/default.vert", "shaders/default.frag"};

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.swapBuffers();
        windowContext.pollEvents();
    }

    return 0;
}
