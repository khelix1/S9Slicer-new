#pragma once

class ExtrusionCalculator {
public:
    ExtrusionCalculator(float nozzle_diameter, float layer_height, float filament_diameter);
    float calculateE(float path_length);
    void reset();
    float getCurrentE() const;

private:
    float width;
    float height;
    float filament_area;
    float e_position;
};