#include "support_gcode.h"
#include <sstream>
#include <cmath>
#include <iomanip>

SupportGCodeGenerator::SupportGCodeGenerator(double extrusionWidth, double layerHeight, double filamentDiameter)
    : last_e(0.0) {
    double area = extrusionWidth * layerHeight;
    double filamentArea = M_PI * std::pow(filamentDiameter / 2.0, 2);
    e_per_mm = area / filamentArea;
}

std::string SupportGCodeGenerator::formatMove(double x, double y, double e, double f) {
    std::ostringstream gcode;
    gcode << std::fixed << std::setprecision(4);
    gcode << "G1 X" << x / 1000.0 << " Y" << y / 1000.0 << " E" << e << " F" << f << "\n";
    return gcode.str();
}

std::string SupportGCodeGenerator::generateGCode(const SupportPlanner& planner) {
    std::ostringstream output;
    const auto& paths = planner.getExtrusionPaths();

    double feedrate = 1800;  // mm/min

    for (const auto& path : paths) {
        if (path.empty()) continue;
        auto start = path.front();
        output << "G0 X" << start.x / 1000.0 << " Y" << start.y / 1000.0 << " F4800\n";
        for (size_t i = 1; i < path.size(); ++i) {
            auto p0 = path[i - 1];
            auto p1 = path[i];
            double dist = std::hypot((p1.x - p0.x) / 1000.0, (p1.y - p0.y) / 1000.0);
            last_e += dist * e_per_mm;
            output << formatMove(p1.x, p1.y, last_e, feedrate);
        }
    }

    return output.str();
}