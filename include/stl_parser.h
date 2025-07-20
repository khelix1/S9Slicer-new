#pragma once
#include "../contour.h"
#include <vector>
#include <string>
#include "model_loader.h"

/// STLParser provides low-level utilities to parse STL files into triangle meshes.
/// Used internally by ModelLoader to handle both ASCII and Binary STL formats.
/// Outputs a flat list of Triangle structs containing vertex and normal data.
class STLParser {
public:
    /**
     * @brief Parse an ASCII-format STL file into triangle data.
     *
     * @param filename Path to the ASCII STL file
     * @return std::vector<Triangle> List of parsed triangles
     */
    static std::vector<Triangle> parseASCIISTL(const std::string& filename);

    /**
     * @brief Parse a Binary-format STL file into triangle data.
     *
     * @param filename Path to the binary STL file
     * @return std::vector<Triangle> List of parsed triangles
     */
    static std::vector<Triangle> parseBinarySTL(const std::string& filename);
};
