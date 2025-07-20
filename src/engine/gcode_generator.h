#pragma once
#include <string>
#include "layerplan.h"

class GCodeGenerator {
public:
    GCodeGenerator(double extrusionWidth, double layerHeight, double filamentDia);
    std::string generateFromLayerPlan(const LayerPlan& plan);

private:
    double extrusionWidth;
    double layerHeight;
    double filamentDia;
};