#pragma once

#include "contour.h"
#include "path.h"
#include <vector>

class SupportPathGenerator {
public:
    SupportPathGenerator(double line_width, double spacing);

    void generateGrid(const std::vector<ClipperLib::Paths>& supportRegions);
    void generateLine(const std::vector<ClipperLib::Paths>& supportRegions, double angle = 0);
    void generateConcentric(const std::vector<ClipperLib::Paths>& supportRegions);

    const std::vector<Path>& getPaths() const;

private:
    double lineWidth;
    double spacing;
    std::vector<Path> extrusionPaths;
};