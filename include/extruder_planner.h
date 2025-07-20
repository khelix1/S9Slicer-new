#pragma once
#include <vector>
#include "../contour.h"

/// ExtruderPlanner calculates E-axis extrusion values for given toolpaths.
/// It uses volumetric calculations based on path length, nozzle dimensions, and filament diameter.
/// All E values are cumulative for compatibility with Marlin firmware in absolute extrusion mode.
class ExtruderPlanner {
public:
    /**
     * @brief Compute cumulative E values for a toolpath using volumetric logic.
     *
     * Formula:
     *   E = length * layerHeight * width / (π * (filamentDiameter / 2)^2)
     *
     * @param paths               Vector of toolpath contours (each contour is a polyline)
     * @param nozzleWidth         Nozzle width in mm (typically 0.4)
     * @param layerHeight         Layer height in mm (typically 0.2)
     * @param filamentDiameter    Filament diameter in mm (typically 1.75)
     * @param extrusionMultiplier Optional flow modifier (1.0 = 100%)
     * @return std::vector<double> Vector of cumulative E values (1 per segment)
     */
    static std::vector<double> computeEValues(
        const std::vector<Contour>& paths,
        double nozzleWidth,
        double layerHeight,
        double filamentDiameter,
        double extrusionMultiplier = 1.0
    );
};
