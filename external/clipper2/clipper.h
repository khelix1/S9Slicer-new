// Clipper2 - Real version (abbreviated) from https://github.com/AngusJohnson/Clipper2
#pragma once
#include <vector>
#include <cmath>
#include <cstdint>

namespace Clipper2Lib {

struct PointD {
    double x, y;
    PointD(double x = 0, double y = 0) : x(x), y(y) {}
};

using PathD = std::vector<PointD>;
using PathsD = std::vector<PathD>;

enum class JoinType { Square, Round, Miter };
enum class EndType { Polygon, Joined, Open };

PathsD InflatePaths(const PathsD& paths, double delta,
                    JoinType jt = JoinType::Round,
                    EndType et = EndType::Polygon,
                    double miterLimit = 2.0);

} // namespace Clipper2Lib
