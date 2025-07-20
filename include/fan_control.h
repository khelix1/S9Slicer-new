#pragma once
#include <vector>
#include <string>

struct FanCommand {
    int layer;
    int speed; // PWM 0–255
};

class FanControlManager {
public:
    FanControlManager();

    void registerExtrusionMove(double x, double y, double z, double e, double speed);
    void nextLayer(int layerNum);
    int getCurrentFanSpeed() const;
    std::vector<FanCommand> getFanCommands() const;

private:
    int current_layer;
    double last_e;
    int current_fan_speed;
    std::vector<FanCommand> fan_commands;
};
