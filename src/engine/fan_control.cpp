#include "fan_control.h"
#include <iostream>
#include <cmath>

FanControlManager::FanControlManager()
    : current_layer(0), last_e(0.0), current_fan_speed(0) {}

void FanControlManager::registerExtrusionMove(double x, double y, double z, double e, double speed) {
    double extrusion_amount = e - last_e;
    last_e = e;

    // Compute speed proportional to extrusion amount (clamped between 0 and 255)
    int fan_speed = static_cast<int>(std::min(255.0, std::max(0.0, extrusion_amount * 10000.0)));

    if (fan_speed != current_fan_speed) {
        current_fan_speed = fan_speed;
        std::cout << "[FanControl] Layer " << current_layer << ", E=" << e
                  << ", Fan=" << current_fan_speed << "\n";
    }
}

void FanControlManager::nextLayer(int layerNum) {
    current_layer = layerNum;
    fan_commands.push_back({layerNum, current_fan_speed});
}

int FanControlManager::getCurrentFanSpeed() const {
    return current_fan_speed;
}

std::vector<FanCommand> FanControlManager::getFanCommands() const {
    return fan_commands;
}
