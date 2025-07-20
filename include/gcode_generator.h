#pragma once
#include <vector>
#include "../contour.h"

/// GCodeGenerator is responsible for converting toolpaths into G-code format.
/// Currently outputs basic G1 travel moves (X/Y) without extrusion or Z-height.
class GCodeGenerator {
public:
    /**
     * @brief Generate G-code from a series of 2D paths.
     * Each path is assumed to be a series of XY travel moves.
     *
     * @param paths A vector of Contour objects representing toolpaths.
     * @return std::string G-code string with G1 commands.
     */
    static std::string generate(const std::vector<Contour>& paths);
};
