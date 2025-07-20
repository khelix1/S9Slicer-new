#pragma once
#include "contour.h"
#include <string>

class InfillPreview {
public:
    static void renderSVG(const std::vector<Contour>& infill, const Contour& boundary, const std::string& filename);
};