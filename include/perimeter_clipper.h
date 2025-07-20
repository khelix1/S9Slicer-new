#pragma once
#include "../contour.h"
#include <vector>

/// PerimeterClipper generates inner perimeters (shells) using Clipper2 offsetting logic.
/// It offsets inward from an outer contour to create multiple wall loops.
/// Used during slicing to generate the shell structure of each layer.
class PerimeterClipper {
public:
    /**
     * @brief Generate N inner perimeters from an outer contour using Clipper2.
     *
     * Uses Clipper2's InflatePaths() with negative offset to shrink the contour inward.
     *
     * @param outer The outer perimeter of the layer or island
     * @param count Number of inner perimeters to generate
     * @param offset Distance between each perimeter (usually nozzle width)
     * @return std::vector<Contour> Vector of offset inner perimeters
     */
    static std::vector<Contour> clipPerimeters(const Contour& outer, int count, double offset);
};
