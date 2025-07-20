#pragma once
#include <vector>
#include <Clipper2/clipper.h>

struct ArcSegment {
    ClipperLib::IntPoint start;
    ClipperLib::IntPoint end;
    double iOffset;
    double jOffset;
    bool clockwise;
};

class ArcFitter {
public:
    static std::vector<std::string> fitArcs(const ClipperLib::Path& path, double tolerance = 0.1);
};
