#include "contour.h"
#include <iostream>

void Contour::close() {
    if (points.empty()) return;

    if (!isClosed()) {
        points.push_back(points.front());
        std::cout << "[Contour] Closed contour by appending first point.\n";
    }
}

bool Contour::isClosed() const {
    if (points.size() < 3) return false;
    return points.front().nearlyEquals(points.back());
}
