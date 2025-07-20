#pragma once
#include <vector>

struct Triangle {
    float nx, ny, nz;
    float v[3][3];
};

std::vector<Triangle> parseSTL(const std::string& filename);