#include "rendering/opengl/shader.hpp"
#include <glad/gl.h>
#include <filesystem>
#include <fstream>
#include <iostream>

Shader::Shader(std::filesystem::path vertexPath, std::filesystem::path fragmentPath) {
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch (std::ifstream::failure& e) {
#if MV_DEBUG
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
#endif  // DEBUG
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
#if MV_DEBUG
    checkCompileErrors(vertex, "VERTEX");
#endif  // DEBUG

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
#if MV_DEBUG
    checkCompileErrors(fragment, "FRAGMENT");
#endif  // DEBUG

    id_ = glCreateProgram();
    glAttachShader(id_, vertex);
    glAttachShader(id_, fragment);
    glLinkProgram(id_);
#if MV_DEBUG
    checkCompileErrors(id_, "PROGRAM");
#endif  // DEBUG
    glDeleteShader(vertex);
    glDeleteShader(fragment);
};

void Shader::use() {
    glUseProgram(id_);
}

void Shader::setBool(const char* name, bool value) {
    const int unifromLocation = glGetUniformLocation(id_, name);
    glUniform1i(unifromLocation, value);
};
void Shader::setFloat(const char* name, float value) {
    const int unifromLocation = glGetUniformLocation(id_, name);
    glUniform1f(unifromLocation, value);
};
void Shader::setInt(const char* name, int value) {
    const int unifromLocation = glGetUniformLocation(id_, name);
    glUniform1i(unifromLocation, value);
};
