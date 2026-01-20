#pragma once

#include <filesystem>

class ShaderProgram {
  public:
    ShaderProgram(std::filesystem::path vertexPath, std::filesystem::path fragmentPath);
    void use();
    void setBool(const char* name, bool value);
    void setFloat(const char* name, float value);
    void setInt(const char* name, int value);

  private:
    unsigned int id_{};
};
