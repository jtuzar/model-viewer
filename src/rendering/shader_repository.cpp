#include "rendering/shader_repository.hpp"
#include <stdexcept>
#include "rendering/shader_program.hpp"

namespace rendering {
ShaderProgram& ShaderRepository::getShader(ShaderType shaderType) {
    auto shaderSourcesIt = shaderSourcePaths.find(shaderType);
    if (shaderSourcesIt == shaderSourcePaths.end()) {
        throw std::runtime_error("No sources for given shader defined");
    }
    auto [it, _] = shaderMap_.try_emplace(shaderType, shaderSourcesIt->second.vertexShaderSource,
                                          shaderSourcesIt->second.fragmentShaderSource

    );
    return it->second;
}

}  // namespace rendering
