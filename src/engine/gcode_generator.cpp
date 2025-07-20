
#include "extrusion_calculator.h"

void GCodeGenerator::emitExtrudedMove(std::ostream& out, const Point& from, const Point& to,
                                      ExtrusionCalculator& extruder, float feedrate) {
    float dx = to.x - from.x;
    float dy = to.y - from.y;
    float length = std::sqrt(dx * dx + dy * dy);

    float e = extruder.calculateE(length);
    out << "G1 X" << to.x << " Y" << to.y << " E" << e << " F" << feedrate << "\n";
}

void GCodeGenerator::emitRetraction(std::ostream& out, float retract_length, float retract_speed) {
    out << "; Retraction\n";
    out << "G1 E-" << retract_length << " F" << retract_speed << "\n";
}

void GCodeGenerator::emitPrime(std::ostream& out, float retract_length, float prime_speed) {
    out << "; Prime\n";
    out << "G1 E" << retract_length << " F" << prime_speed << "\n";
}

void GCodeGenerator::emitZHopUp(std::ostream& out, float current_z, float z_hop_height, float hop_speed) {
    out << "; Z-hop up\n";
    out << "G1 Z" << (current_z + z_hop_height) << " F" << hop_speed << "\n";
}

void GCodeGenerator::emitZHopDown(std::ostream& out, float original_z, float hop_speed) {
    out << "; Z-hop down\n";
    out << "G1 Z" << original_z << " F" << hop_speed << "\n";
}
