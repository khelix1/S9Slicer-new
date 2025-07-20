#pragma once
#include "layer.h"
#include "contour.h"
#include <vector>

enum class SupportType {
    GRID,
    LINE,
    CONCENTRIC
};

class SupportPlanner {
public:
    std::vector<std::vector<Contour>> generateSupports(const std::vector<Layer>& layers,
                                                       float thresholdAngleDeg);
    std::vector<std::vector<Contour>> generateSupports(const std::vector<Layer>& layers,
                                                       float thresholdAngleDeg,
                                                       SupportType type);
};