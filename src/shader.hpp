#pragma once

#include <glad/gl.h>
#include <filesystem>

#if MV_DEBUG
#include <iostream>
#endif  // DEBUG

class Shader {
   public:
    Shader(std::filesystem::path vertexPath, std::filesystem::path fragmentPath);
    void use();
    void setBool(const char* name, bool value);
    void setFloat(const char* name, float value);
    void setInt(const char* name, int value);

   private:
    unsigned int id_;

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
};
