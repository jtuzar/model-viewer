#pragma once

#include <filesystem>
#include <unordered_map>
#include "rendering/shader_program.hpp"
#include "rendering/shader_type.hpp"

namespace rendering {

class ShaderRepository {
   public:
    ShaderProgram& getShader(ShaderType shaderType);

   private:
    std::unordered_map<ShaderType, ShaderProgram> shaderMap_;
};

struct ShaderSourcePaths {
    std::filesystem::path vertexShaderSource;
    std::filesystem::path fragmentShaderSource;
};

static const std::unordered_map<ShaderType, ShaderSourcePaths> shaderSourcePaths{
    {ShaderType::basic, ShaderSourcePaths{"shaders/default.vert", "shaders/default.frag"}}};

}  // namespace rendering
