#include <iostream>
#include <fstream>
#include "gcode_generator.h"
#include "layerplan.h"
#include "clipper.hpp"

void print_usage() {
    std::cout << "Usage: ./s9slicer [--test-layerplan]" << std::endl;
}

int main(int argc, char* argv[]) {
    bool testLayerPlan = false;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--test-support-gap") {
    LayerPlan plan;
    SupportPlanner sp;
    ClipperLib::Path base = {{0,0}, {6000,0}, {6000,600}, {0,600}};
    sp.setSupportFill({base});
    ClipperLib::Paths iface = sp.generateSupportWithInterface();
    plan.setSupportFill(iface);
    generateFromLayerPlan(plan, "support_gap_output.gcode");
    return 0;
}

if (arg == "--test-support-smooth") {
    LayerPlan plan;
    SupportPlanner sp;
    ClipperLib::Path base = {{0,0}, {6000,0}, {6000,600}, {0,600}};
    sp.setSupportFill({base});
    ClipperLib::Paths skin = sp.generateSupportSkins(3, 150);
    ClipperLib::Paths perimeter = sp.generateSupportPerimeters(150);
    skin.insert(skin.end(), perimeter.begin(), perimeter.end());
    plan.setSupportFill(skin);
    generateFromLayerPlan(plan, "support_smooth_output.gcode");
    return 0;
}

if (arg == "--test-support-perimeter") {
    LayerPlan plan;
    SupportPlanner sp;
    ClipperLib::Path base = {{0,0}, {6000,0}, {6000,600}, {0,600}};
    sp.setSupportFill({base});
    ClipperLib::Paths skin = sp.generateSupportSkins(3, 150);
    ClipperLib::Paths perimeter = sp.generateSupportPerimeters(150);
    skin.insert(skin.end(), perimeter.begin(), perimeter.end());
    plan.setSupportFill(skin);
    generateFromLayerPlan(plan, "support_perimeter_output.gcode");
    return 0;
}

if (arg == "--test-support-interface") {
    LayerPlan plan;
    SupportPlanner sp;
    sp.enableSupportInterface(true, 2);
    ClipperLib::Path base = {{0,0}, {6000,0}, {6000,600}, {0,600}};
    sp.setSupportFill({base});
    plan.setSupportFill(sp.generateSupportWithInterface());
    generateFromLayerPlan(plan, "support_interface_output.gcode");
    return 0;
}

if (arg == "--test-bridge-tune") {
    LayerPlan plan;
    // Sample bridge infill geometry for testing
    ClipperLib::Path path = {{0,0}, {6000,0}, {6000,600}, {0,600}};
    plan.setBridgeFill({path});
    generateFromLayerPlan(plan, "bridge_tune_output.gcode");
    return 0;
}

if (arg == "--test-layerplan") {
            testLayerPlan = true;
        } else {
            print_usage();
            return 1;
        }
    }

    if (testLayerPlan) {
        std::cout << "Generating LayerPlan G-code..." << std::endl;

        ClipperLib::Path rect = {{ {0,0}, {0,5000}, {5000,5000}, {5000,0} }};
        ClipperLib::Paths paths = {{ rect }};

        LayerPlan plan(0.2);
        plan.addPerimeters(paths);
        plan.addInfill(paths);
        plan.addSkin(paths, paths);
        plan.addSupports(paths);
        plan.addBridges(paths);

        GCodeGenerator ggen(0.4, 0.2, 1.75);
        std::string gcode = ggen.generateFromLayerPlan(plan);

        std::ofstream fout("layerplan_output.gcode");
        fout << gcode;
        fout.close();

        std::cout << "LayerPlan G-code written to layerplan_output.gcode" << std::endl;
        return 0;
    }

    print_usage();
    return 0;
}