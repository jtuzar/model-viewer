#include "rendering/shader_program.hpp"
#include <glad/gl.h>
#include <fstream>
#include <iostream>

#if MV_DEBUG
#include <iostream>
void checkCompileErrors(unsigned int shader, std::string type);
#endif  // DEBUG

ShaderProgram::ShaderProgram(std::filesystem::path vertexPath, std::filesystem::path fragmentPath) {
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

void ShaderProgram::use() {
    glUseProgram(id_);
}

void ShaderProgram::setBool(const char* name, bool value) {
    const int unifromLocation = glGetUniformLocation(id_, name);
    glUniform1i(unifromLocation, value);
};
void ShaderProgram::setFloat(const char* name, float value) {
    const int unifromLocation = glGetUniformLocation(id_, name);
    glUniform1f(unifromLocation, value);
};
void ShaderProgram::setInt(const char* name, int value) {
    const int unifromLocation = glGetUniformLocation(id_, name);
    glUniform1i(unifromLocation, value);
};

#if MV_DEBUG
void checkCompileErrors(unsigned int shader, std::string type) {
    int success;
    char infoLog[GL_INFO_LOG_LENGTH];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, GL_INFO_LOG_LENGTH, nullptr, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                      << infoLog
                      << "\n -- "
                         "--------------------------------------------------- "
                         "-- "
                      << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, GL_INFO_LOG_LENGTH, nullptr, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                      << infoLog
                      << "\n -- "
                         "--------------------------------------------------- "
                         "-- "
                      << std::endl;
        }
    }
};
#endif  // DEBUG
