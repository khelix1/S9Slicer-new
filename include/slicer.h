#pragma once
#include "model_loader.h"
#include "contour.h"
#include "perimeter_clipper.h"
#include <vector>

class Slicer {
public:
    Slicer();
    void loadModel(const std::string& path);
    void slice(float layerHeight);
    const std::vector<std::vector<Contour>>& getLayers() const;

private:
    Model model;
    std::vector<std::vector<Contour>> layers;
};
