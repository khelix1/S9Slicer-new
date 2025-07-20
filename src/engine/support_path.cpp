#include "support_path.h"
#include "clipper_utils.h"
#include <cmath>

SupportPathGenerator::SupportPathGenerator(double line_width, double spacing)
    : lineWidth(line_width), spacing(spacing) {}

void SupportPathGenerator::generateGrid(const std::vector<ClipperLib::Paths>& regions) {
    extrusionPaths.clear();
    for (const auto& region : regions) {
        auto infill = ClipperUtils::generateGrid(region, spacing, 0.0);
        extrusionPaths.insert(extrusionPaths.end(), infill.begin(), infill.end());
        auto infill2 = ClipperUtils::generateGrid(region, spacing, 90.0);
        extrusionPaths.insert(extrusionPaths.end(), infill2.begin(), infill2.end());
    }
}

void SupportPathGenerator::generateLine(const std::vector<ClipperLib::Paths>& regions, double angle) {
    extrusionPaths.clear();
    for (const auto& region : regions) {
        auto infill = ClipperUtils::generateLines(region, spacing, angle);
        extrusionPaths.insert(extrusionPaths.end(), infill.begin(), infill.end());
    }
}

void SupportPathGenerator::generateConcentric(const std::vector<ClipperLib::Paths>& regions) {
    extrusionPaths.clear();
    for (const auto& region : regions) {
        auto infill = ClipperUtils::generateConcentric(region, spacing, 1.5, 4);
        extrusionPaths.insert(extrusionPaths.end(), infill.begin(), infill.end());
    }
}

const std::vector<Path>& SupportPathGenerator::getPaths() const {
    return extrusionPaths;
}