#include "infill_clipper.h"
#include "clipper.h"
#include <cmath>

std::vector<Contour> InfillClipper::clipToBoundary(const std::vector<Contour>& lines, const Contour& boundary, float minLength) {
    std::vector<Contour> clipped;

    ClipperLib::Path boundary_path;
    for (const auto& pt : boundary.points) {
        boundary_path << ClipperLib::IntPoint(static_cast<ClipperLib::cInt>(pt.x * 1000),
                                              static_cast<ClipperLib::cInt>(pt.y * 1000));
    }

    for (const auto& line : lines) {
        ClipperLib::Path line_path;
        for (const auto& pt : line.points) {
            line_path << ClipperLib::IntPoint(static_cast<ClipperLib::cInt>(pt.x * 1000),
                                              static_cast<ClipperLib::cInt>(pt.y * 1000));
        }

        ClipperLib::Paths solution;
        ClipperLib::Clipper clipper;
        clipper.AddPath(line_path, ClipperLib::ptSubject, false);
        clipper.AddPath(boundary_path, ClipperLib::ptClip, true);
        clipper.Execute(ClipperLib::ctIntersection, solution, ClipperLib::pftNonZero, ClipperLib::pftNonZero);

        for (const auto& path : solution) {
            Contour result;
            for (const auto& ipt : path) {
                result.points.emplace_back(Point(ipt.X / 1000.0, ipt.Y / 1000.0));
            }

            if (result.points.size() >= 2) {
                double dx = result.points[1].x - result.points[0].x;
                double dy = result.points[1].y - result.points[0].y;
                double len = std::sqrt(dx * dx + dy * dy);
                if (len >= minLength)
                    clipped.push_back(result);
            }
        }
    }

    return clipped;
}