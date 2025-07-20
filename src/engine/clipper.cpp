#include "clipper.h"
#include "../contour.h"
#include <iostream>

using namespace Clipper2Lib;

namespace ClipperUtils {

std::vector<Contour> offset(const Contour& input, double distance) {
    // Convert Contour to Clipper2 PathD
    PathD path;
    for (const auto& pt : input.points) {
        path.emplace_back(pt.x, pt.y);
    }

    // Perform offset using Clipper2
    PathsD result = InflatePaths({ path }, distance, JoinType::Miter, EndType::Polygon);

    // Convert result back to std::vector<Contour>
    std::vector<Contour> contours;
    for (const auto& rpath : result) {
        Contour contour;
        for (const auto& pt : rpath) {
            contour.points.push_back({pt.x, pt.y});
        }
        contour.close();
        contours.push_back(contour);
    }

    std::cout << "[ClipperUtils] offset(): Applied offset of " << distance << " mm\n";
    return contours;
}

}  // namespace ClipperUtils
