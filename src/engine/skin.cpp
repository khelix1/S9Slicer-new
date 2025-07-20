#include "skin.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

std::vector<Contour> SkinGenerator::generateTopSkin(const Contour& outer) {
    std::vector<Contour> skinLines;

    if (outer.points.size() < 3) return skinLines;

    double minX = outer.points.front().x;
    double maxX = outer.points.front().x;
    double minY = outer.points.front().y;
    double maxY = outer.points.front().y;

    for (const auto& pt : outer.points) {
        if (pt.x < minX) minX = pt.x;
        if (pt.x > maxX) maxX = pt.x;
        if (pt.y < minY) minY = pt.y;
        if (pt.y > maxY) maxY = pt.y;
    }

    double spacing = 0.4;  // 0.4mm skin fill spacing
    int count = 0;
    for (double y = minY + spacing; y < maxY; y += spacing) {
        Contour line;
        line.points.push_back({minX, y});
        line.points.push_back({maxX, y});
        skinLines.push_back(line);
        count++;
    }

    std::cout << "[SkinGenerator] Generated " << count << " top skin hatch lines.\n";
    return skinLines;
}

std::vector<Contour> SkinGenerator::generateBottomSkin(const Contour& outer) {
    return generateTopSkin(outer);
}
