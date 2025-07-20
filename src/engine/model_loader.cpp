#include "model_loader.h"
#include "stl_parser.h"
#include <fstream>
#include <iostream>

Model ModelLoader::loadSTL(const std::string& filename) {
    Model model;
    model.sourceFile = filename;

    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "[ModelLoader] Failed to open file: " << filename << "\n";
        return model;
    }

    // Check for binary STL by reading first 80 bytes (header)
    char header[80];
    file.read(header, 80);
    file.seekg(0);  // reset to beginning

    std::string headerStr(header, 80);
    bool isBinary = headerStr.find("solid") != 0;

    model.isBinary = isBinary;

    if (isBinary) {
        model.triangles = STLParser::parseBinarySTL(filename);
    } else {
        model.triangles = STLParser::parseASCIISTL(filename);
    }

    std::cout << "[ModelLoader] Loaded " << model.triangles.size() << " triangles from "
              << (isBinary ? "binary" : "ASCII") << " STL.\n";

    return model;
}
