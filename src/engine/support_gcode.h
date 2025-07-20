#ifndef SUPPORT_GCODE_H
#define SUPPORT_GCODE_H

#include <string>
#include "support_planner.h"

class SupportGCodeGenerator {
public:
    SupportGCodeGenerator(double extrusionWidth, double layerHeight, double filamentDiameter);
    std::string generateGCode(const SupportPlanner& planner);

private:
    double e_per_mm;
    double last_e;
    std::string formatMove(double x, double y, double e, double f);
};

#endif