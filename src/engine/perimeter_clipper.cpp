#include "perimeter_clipper.h"
#include "clipper2/clipper.h"
#include <iostream>

using namespace Clipper2Lib;

std::vector<Contour> PerimeterClipper::clipPerimeters(const Contour& outer, int count, double offset) {
    std::vector<Contour> result;

    if (count <= 0 || offset <= 0.0 || outer.points.size() < 3) {
        std::cerr << "[PerimeterClipper] Invalid inputs for clipping." << std::endl;
        return result;
    }

    // Convert to Clipper path (scaled by 1000 to use integer math)
    PathD inputPath;
    for (const auto& pt : outer.points)
        inputPath.push_back(PointD(pt.x, pt.y));

    PathsD currentLayer = { inputPath };
    for (int i = 0; i < count; ++i) {
        PathsD offsetLayer = InflatePaths(currentLayer, -offset, JoinType::Round, EndType::Polygon);
        currentLayer = offsetLayer;

        for (const auto& path : offsetLayer) {
            Contour c;
            for (const auto& p : path)
                c.points.push_back({p.x, p.y});
            result.push_back(c);
        }
    }

    std::cout << "[PerimeterClipper] Generated " << result.size() << " perimeters." << std::endl;
    return result;
}
