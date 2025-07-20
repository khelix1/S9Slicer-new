#pragma once
#include "../contour.h"
#include <vector>

/// LayerPlanner organizes and plans toolpaths for a single layer.
/// This includes assigning skin, infill, and perimeters to the appropriate generators.
/// Currently uses simple logic but is designed for future expansion.
class LayerPlanner {
public:
    /**
     * @brief Plan a single Z-layer using a vector of input contours.
     *
     * This method currently:
     * - Assumes the first contour is the outer perimeter
     * - Generates top skin hatch fills using SkinGenerator
     * - Computes E values using ExtruderPlanner
     * - Emits G-code using GCodeGenerator
     *
     * Future implementations will support:
     * - Infill types
     * - Perimeter sorting
     * - Z-lift and travel planning
     * - Multiple extrusion tools
     *
     * @param layerContours Vector of raw 2D contours for the current Z-layer
     */
    static void planLayer(const std::vector<Contour>& layerContours);
};
