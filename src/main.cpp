#include "shader.hpp"
#include "platform/window_context.hpp"
#include "platform/window.hpp"
#include "vertex_buffer.hpp"
#include <filesystem>

int main() {
    WindowContext windowContext;
    Window window{1920, 1080, "model-viewer", nullptr, nullptr, windowContext};

    const std::vector<float> vertices{
        -0.5f, -0.5f, 0,  //
        0.5f,  -0.5f, 0,  //
        0.0f,  0.5f,  0,
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    VertexBuffer vertexBuffer{&vertices};

    Shader shader{"shaders/default.vert", "shaders/default.frag"};

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        vertexBuffer.bind();
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.swapBuffers();
        windowContext.pollEvents();
    }

    return 0;
}
