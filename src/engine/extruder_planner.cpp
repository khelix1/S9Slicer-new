#include "extruder_planner.h"
#include <cmath>
#include <iostream>

std::vector<double> ExtruderPlanner::computeEValues(
    const std::vector<Contour>& paths,
    double nozzleWidth,
    double layerHeight,
    double filamentDiameter,
    double extrusionMultiplier
) {
    std::vector<double> eValues;
    double filamentArea = M_PI * std::pow(filamentDiameter / 2.0, 2);
    double currentE = 0.0;

    for (const auto& contour : paths) {
        for (size_t i = 1; i < contour.points.size(); ++i) {
            const Point& p1 = contour.points[i - 1];
            const Point& p2 = contour.points[i];

            double dx = p2.x - p1.x;
            double dy = p2.y - p1.y;
            double length = std::sqrt(dx * dx + dy * dy);

            double volume = length * layerHeight * nozzleWidth;
            double e = (volume / filamentArea) * extrusionMultiplier;
            currentE += e;
            eValues.push_back(currentE);
        }
    }

    std::cout << "[ExtruderPlanner] Computed " << eValues.size() << " E-values.\n";
    return eValues;
}
