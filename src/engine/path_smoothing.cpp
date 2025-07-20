
#include "path_smoothing.h"
#include <cmath>

ClipperLib::Paths smoothPaths(const ClipperLib::Paths& input, double tolerance) {
    ClipperLib::Paths result;
    for (const auto& path : input) {
        ClipperLib::Path smoothed;
        for (size_t i = 1; i + 1 < path.size(); ++i) {
            ClipperLib::IntPoint prev = path[i - 1];
            ClipperLib::IntPoint curr = path[i];
            ClipperLib::IntPoint next = path[i + 1];

            double dx1 = curr.X - prev.X;
            double dy1 = curr.Y - prev.Y;
            double dx2 = next.X - curr.X;
            double dy2 = next.Y - curr.Y;

            double dot = dx1 * dx2 + dy1 * dy2;
            double mag1 = std::sqrt(dx1 * dx1 + dy1 * dy1);
            double mag2 = std::sqrt(dx2 * dx2 + dy2 * dy2);

            double angle = std::acos(dot / (mag1 * mag2 + 1e-6));
            if (angle < tolerance) continue;  // skip sharp angles

            smoothed.push_back(curr);
        }
        if (!smoothed.empty())
            result.push_back(smoothed);
    }
    return result;
}
