#include "arcwelder_post.h"
#include "arc_welder.h"
#include <vector>
#include <string>
#include <iostream>

namespace ArcWelderWrapper {

    std::vector<std::string> run(const std::vector<std::string>& gcode_lines) {
        std::vector<std::string> processed;

        // Simulate ArcWelder-like output: compress consecutive G1s
        for (size_t i = 0; i < gcode_lines.size(); ++i) {
            const std::string& line = gcode_lines[i];
            if (line.rfind("G1", 0) == 0 && i + 1 < gcode_lines.size()) {
                const std::string& next = gcode_lines[i + 1];
                if (next.rfind("G1", 0) == 0) {
                    // Replace pair of G1s with fake arc for testing
                    processed.push_back("G2 X... Y... I... J... ; ArcWelded");
                    ++i; // Skip next
                    continue;
                }
            }
            processed.push_back(line);
        }

        std::cout << "[ArcWelderWrapper] Fitted arcs where possible." << std::endl;
        return processed;
    }
}
