#ifndef SHADER_H
#define SHADER_H

#include <glad/gl.h>
#include <filesystem>
#include <iostream>

class Shader {
   public:
    unsigned int ID_;
    Shader(std::filesystem::path vert, std::filesystem::path frag);
    void use();
    void setBool(const char* name, bool value);
    void setFloat(const char* name, float value);
    void setInt(const char* name, int value);

   private:
    void checkCompileErrors(unsigned int shader, std::string type) {
        int success;
        char infoLog[GL_INFO_LOG_LENGTH];
        if (type != "PROGRAM") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, GL_INFO_LOG_LENGTH, nullptr,
                                   infoLog);
                std::cout
                    << "ERROR::SHADER_COMPILATION_ERROR of type: " << type
                    << "\n"
                    << infoLog
                    << "\n -- "
                       "--------------------------------------------------- "
                       "-- "
                    << std::endl;
            }
        } else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shader, GL_INFO_LOG_LENGTH, nullptr,
                                    infoLog);
                std::cout
                    << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                    << infoLog
                    << "\n -- "
                       "--------------------------------------------------- "
                       "-- "
                    << std::endl;
            }
        }
    };
};

#endif
