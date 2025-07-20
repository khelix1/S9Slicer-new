#pragma once
#include "contour.h"

class InfillClipper {
public:
    static std::vector<Contour> clipToBoundary(const std::vector<Contour>& lines, const Contour& boundary, float minLength = 0.1);
};