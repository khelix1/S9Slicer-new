
#include "gcode_generator.h"

void Planner::emitTravelMove(std::ostream& out, const Point& from, const Point& to, float z,
                             GCodeGenerator& gcode, float retract_length, float retract_speed,
                             float z_hop_height, float hop_speed, float prime_speed) {
    out << "; Travel move with retraction and Z-hop\n";
    gcode.emitRetraction(out, retract_length, retract_speed);
    gcode.emitZHopUp(out, z, z_hop_height, hop_speed);
    out << "G0 X" << to.x << " Y" << to.y << "\n";
    gcode.emitZHopDown(out, z, hop_speed);
    gcode.emitPrime(out, retract_length, prime_speed);
}

void Planner::planMovesWithTravel(std::ostream& out, const std::vector<Layer>& layers,
                                  GCodeGenerator& gcode, ExtrusionCalculator& extruder) {
    const float retract_length = 0.8f;
    const float retract_speed = 1200.0f;
    const float prime_speed = 1000.0f;
    const float z_hop_height = 0.6f;
    const float hop_speed = 900.0f;
    const float feedrate = 1800.0f;

    for (size_t i = 0; i < layers.size(); ++i) {
        const Layer& layer = layers[i];
        float z = layer.z;
        out << "; Layer " << i << " at Z=" << z << "\n";
        if (layer.perimeter.points.size() < 2) continue;

        // Initial travel move to first point
        if (i > 0) {
            const Layer& prev = layers[i - 1];
            emitTravelMove(out, prev.perimeter.points.back(), layer.perimeter.points.front(), z,
                           gcode, retract_length, retract_speed, z_hop_height, hop_speed, prime_speed);
        }

        // Extrude all perimeter segments
        for (size_t j = 1; j < layer.perimeter.points.size(); ++j) {
            gcode.emitExtrudedMove(out, layer.perimeter.points[j - 1], layer.perimeter.points[j], extruder, feedrate);
        }
    }
}
