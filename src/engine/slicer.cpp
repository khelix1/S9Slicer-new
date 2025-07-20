#include "slicer.h"
#include <iostream>

Slicer::Slicer(float layerHeight)
    : layerHeight(layerHeight) {}

void Slicer::loadModel(const std::string& path) {
    if (model.loadFromSTL(path)) {
        std::cout << "[Slicer] Model loaded successfully.\n";
    } else {
        std::cerr << "[Slicer] Failed to load model.\n";
    }
}

void Slicer::generateLayers() {
    std::cout << "[Slicer] Generating slices at height: " << layerHeight << "mm\n";

    float z = 0.0f;
    float modelHeight = model.getMaxZ();  // You will implement this later

    while (z <= modelHeight) {
        std::vector<Contour> layerContours = model.sliceAtZ(z);  // To be implemented in Model
        rawContoursByZ[z] = layerContours;
        z += layerHeight;
    }

    std::cout << "[Slicer] " << rawContoursByZ.size() << " layers generated.\n";
}

void Slicer::generatePerimeters() {
    layers.clear();

    for (const auto& entry : rawContoursByZ) {
        std::vector<Contour> offsetContours;
        for (const auto& contour : entry.second) {
            auto perims = PerimeterClipper::offsetPerimeters(contour, -0.4); // example offset
            offsetContours.insert(offsetContours.end(), perims.begin(), perims.end());
        }
        layers.push_back(offsetContours);
    }

    std::cout << "[Slicer] Perimeter generation complete.\n";
}

void Slicer::generateInfill() {
    std::cout << "[Slicer] Infill generation is not implemented yet.\n";
}

const std::vector<std::vector<Contour>>& Slicer::getLayers() const {
    return layers;
}
