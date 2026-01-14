#include <glad/gl.h>
#include "platform/window.hpp"
#include <GLFW/glfw3.h>
#include <filesystem>
#include <iostream>
#include <shader.hpp>

int main() {
    Window window{640, 640, "model-viewer", nullptr, nullptr};

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "."
              << GLAD_VERSION_MINOR(version) << std::endl;

    const float vertices[]{
        -0.5f, -0.5f, 0,  //
        0.5f,  -0.5f, 0,  //
        0.0f,  0.5f,  0,

    };

    unsigned int VAO, VBO;
    glGenBuffers(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    Shader shader{"shaders/default.vert", "shaders/default.frag"};

    while (!glfwWindowShouldClose(window.getGLFWHandle())) {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window.getGLFWHandle());
        glfwPollEvents();
    }

    return 0;
}
