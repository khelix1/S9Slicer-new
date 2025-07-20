#include "extrusion_calculator.h"
#include <cmath>

ExtrusionCalculator::ExtrusionCalculator(float nozzle_diameter, float layer_height, float filament_diameter)
    : width(nozzle_diameter),
      height(layer_height),
      e_position(0.0f)
{
    float r = filament_diameter / 2.0f;
    filament_area = M_PI * r * r;
}

float ExtrusionCalculator::calculateE(float path_length) {
    float volume = width * height * path_length;  // mm³
    float e = volume / filament_area;
    e_position += e;
    return e_position;
}

void ExtrusionCalculator::reset() {
    e_position = 0.0f;
}

float ExtrusionCalculator::getCurrentE() const {
    return e_position;
}