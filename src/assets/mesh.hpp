#pragma once

#include "assets/vertex.hpp"
#include <vector>

struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};
