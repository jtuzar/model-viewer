#pragma once

#include <filesystem>

class ShaderProgram {
   public:
    ShaderProgram(std::filesystem::path vertexPath, std::filesystem::path fragmentPath);
    void use() const;
    void setBool(const char* name, bool value) const;
    void setFloat(const char* name, float value) const;
    void setInt(const char* name, int value) const;

   private:
    unsigned int id_;
};
