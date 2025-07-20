#pragma once
#include "contour.h"
#include <vector>

/// Namespace for geometric operations using ClipperLib
namespace ClipperUtils {

    /**
     * @brief Offset a polygonal contour by a given distance.
     * 
     * Uses ClipperLib to perform polygon offsetting.
     * Positive distance expands outward; negative shrinks inward.
     *
     * @param input The source contour (must be closed).
     * @param distance The offset distance in millimeters.
     * @return std::vector<Contour> One or more offset contours.
     */
    std::vector<Contour> offset(const Contour& input, double distance);
}
