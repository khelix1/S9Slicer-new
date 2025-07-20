#include "arc_fitter.h"
#include <cmath>
#include <string>

using namespace ClipperLib;

static double distance(const IntPoint& a, const IntPoint& b) {
    double dx = (a.X - b.X) / 1000.0;
    double dy = (a.Y - b.Y) / 1000.0;
    return std::sqrt(dx * dx + dy * dy);
}

std::vector<std::string> ArcFitter::fitArcs(const Path& path, double tol) {
    std::vector<std::string> gcode;
    if (path.size() < 3) return gcode;

    IntPoint last = path[0];
    gcode.push_back("G1 X" + std::to_string(last.X / 1000.0) + " Y" + std::to_string(last.Y / 1000.0));

    for (size_t i = 1; i + 1 < path.size(); ++i) {
        IntPoint p0 = path[i - 1];
        IntPoint p1 = path[i];
        IntPoint p2 = path[i + 1];

        double dx1 = p1.X - p0.X;
        double dy1 = p1.Y - p0.Y;
        double dx2 = p2.X - p1.X;
        double dy2 = p2.Y - p1.Y;

        double angle1 = std::atan2(dy1, dx1);
        double angle2 = std::atan2(dy2, dx2);

        double delta = std::fabs(angle2 - angle1);
        if (delta > M_PI) delta = 2 * M_PI - delta;

        if (delta > 0.05 && delta < 1.6) {
            double cx = (p0.X + p2.X) / 2.0;
            double cy = (p0.Y + p2.Y) / 2.0;
            double i = (cx - p0.X) / 1000.0;
            double j = (cy - p0.Y) / 1000.0;
            bool cw = ((dx1 * dy2 - dy1 * dx2) < 0);
            gcode.push_back((cw ? "G2" : "G3") + std::string(" X") +
                std::to_string(p2.X / 1000.0) + " Y" + std::to_string(p2.Y / 1000.0) +
                " I" + std::to_string(i) + " J" + std::to_string(j));
            ++i; // skip next to avoid duplication
        } else {
            gcode.push_back("G1 X" + std::to_string(p1.X / 1000.0) + " Y" + std::to_string(p1.Y / 1000.0));
        }
    }
    return gcode;
}
