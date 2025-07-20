#include "clipper.h"

namespace Clipper2Lib {

PathsD InflatePaths(const PathsD& paths, double delta,
                    JoinType jt, EndType et, double miterLimit) {
    // Example: simple radius expansion logic (not real Clipper2 internals)
    PathsD result;
    for (const auto& path : paths) {
        PathD offset;
        for (const auto& pt : path) {
            offset.push_back(PointD(pt.x + delta, pt.y + delta));
        }
        result.push_back(offset);
    }
    return result;
}

}  // namespace Clipper2Lib
