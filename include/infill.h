#pragma once
#include "contour.h"
#include <vector>

/// Infill pattern generation utilities
class InfillGenerator {
public:
    /**
     * @brief Generate a simple grid infill inside a given closed boundary.
     *
     * The function returns a series of line segments (as Contours) representing
     * a grid pattern spaced evenly across the bounding box of the input contour.
     * This is a geometric infill only — clipping to the exact polygon is handled elsewhere.
     *
     * @param boundary A closed contour representing the fill area.
     * @param spacing Distance between infill lines in millimeters.
     * @param angle Optional infill direction in degrees (default 0 = horizontal).
     * @return std::vector<Contour> Grid lines as separate contour paths.
     */
    static std::vector<Contour> generateGrid(const Contour& boundary, float spacing, float angle = 0.0f);
};
