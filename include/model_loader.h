#pragma once
#include <string>
#include <vector>

/// Represents a single triangle in 3D space
struct Triangle {
    float normal[3];
    float vertices[3][3];
};

/// Represents a 3D model composed of STL triangle data
struct Model {
    std::vector<Triangle> triangles;
    bool isBinary = false;
    std::string sourceFile;
};

/// ModelLoader is responsible for loading and parsing STL files into triangle data.
class ModelLoader {
public:
    /**
     * @brief Load and parse an STL file.
     * Supports both ASCII and Binary STL.
     *
     * @param filename Path to the STL file
     * @return Model struct with triangle data and metadata
     */
    static Model loadSTL(const std::string& filename);
};
