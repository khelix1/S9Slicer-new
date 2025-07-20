#include "stl_parser.h"
#include "infill_generator.h"
#include "infill_clipper.h"
#include "infill_preview.h"
#include <iostream>

int main(int argc, char** argv) {
    bool enable_arcwelder = false;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--enable-arcwelder") {
            enable_arcwelder = true;
        }
    }

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " input.stl output.svg [spacing]\n";
        return 1;
    }

    std::string stlFile = argv[1];
    std::string svgFile = argv[2];
    float spacing = (argc > 3) ? std::stof(argv[3]) : 2.0f;

    std::cout << "[CLI] Loading model: " << stlFile << "\n";
    STLParser parser;
    auto model = parser.load(stlFile);
    if (model.layers.empty() || model.layers[0].contours.empty()) {
        std::cerr << "[CLI] Error: STL parsing failed or empty geometry.\n";
        return 1;
    }

    Contour boundary = model.layers[0].contours[0]; // preview only first slice

    InfillGenerator infillGen;
    auto rawInfill = infillGen.generateGrid(boundary, spacing);  // you can swap this with any pattern
    auto clipped = InfillClipper::clipToBoundary(rawInfill, boundary);

    std::cout << "[CLI] Generating SVG preview: " << svgFile << "\n";
    InfillPreview::renderSVG(clipped, boundary, svgFile);

    std::cout << "[CLI] Done.\n";
    return 0;
}