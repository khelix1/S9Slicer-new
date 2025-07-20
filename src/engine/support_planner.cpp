#include "path_smoothing.h"
#include "support_planner.h"
#include "geometry_utils.h"
#include <cmath>

std::vector<std::vector<Contour>> SupportPlanner::generateSupports(const std::vector<Layer>& layers,
                                                                   float thresholdAngleDeg) {
    return generateSupports(layers, thresholdAngleDeg, SupportType::GRID);
}

std::vector<std::vector<Contour>> SupportPlanner::generateSupports(const std::vector<Layer>& layers,
                                                                   float thresholdAngleDeg,
                                                                   SupportType type) {
    std::vector<std::vector<Contour>> supportContours(layers.size());



    for (size_t i = 1; i < layers.size(); ++i) {
        const auto& above = layers[i].perimeter;
        if (above.points.empty()) continue;

        if (type == SupportType::GRID) {
            supportContours[i].push_back(generateGridPattern(above, 1.5f));
        } else if (type == SupportType::LINE) {
            supportContours[i].push_back(generateLinePattern(above, 1.5f, true));
        } else if (type == SupportType::CONCENTRIC) {
            supportContours[i].push_back(generateConcentricPattern(above, 1.5f, 4));
        }
    }
    }
    }

    return supportContours;
}
// --- Grid support generation logic ---
#include "clipper_utils.h"

static Contour generateGridPattern(const Contour& bounds, float spacing) {
    Contour result;
    float min_x = bounds.minX();
    float max_x = bounds.maxX();
    float min_y = bounds.minY();
    float max_y = bounds.maxY();

    for (float x = min_x; x <= max_x; x += spacing) {
        result.points.emplace_back(Point(x, min_y));
        result.points.emplace_back(Point(x, max_y));
    }

    for (float y = min_y; y <= max_y; y += spacing) {
        result.points.emplace_back(Point(min_x, y));
        result.points.emplace_back(Point(max_x, y));
    }

    return smoothPaths(result, 0.2);
}

// --- Line support generation logic ---
static Contour generateLinePattern(const Contour& bounds, float spacing, bool vertical = true) {
    Contour result;
    float min_x = bounds.minX();
    float max_x = bounds.maxX();
    float min_y = bounds.minY();
    float max_y = bounds.maxY();

    if (vertical) {
        for (float x = min_x; x <= max_x; x += spacing) {
            result.points.emplace_back(Point(x, min_y));
            result.points.emplace_back(Point(x, max_y));
        }
    } else {
        for (float y = min_y; y <= max_y; y += spacing) {
            result.points.emplace_back(Point(min_x, y));
            result.points.emplace_back(Point(max_x, y));
        }
    }

    return smoothPaths(result, 0.2);
}

// --- Concentric support generation logic ---
static Contour generateConcentricPattern(const Contour& bounds, float spacing, int rings = 4) {
    Contour result;
    float min_x = bounds.minX();
    float max_x = bounds.maxX();
    float min_y = bounds.minY();
    float max_y = bounds.maxY();

    float center_x = (min_x + max_x) / 2.0f;
    float center_y = (min_y + max_y) / 2.0f;
    float radius = std::min(max_x - min_x, max_y - min_y) / 2.0f;

    for (int i = 0; i < rings; ++i) {
        float r = radius - i * spacing;
        if (r <= 0) break;
        const int segments = 60;
        for (int j = 0; j <= segments; ++j) {
            float angle = 2.0f * M_PI * j / segments;
            result.points.emplace_back(Point(center_x + r * cos(angle), center_y + r * sin(angle)));
        }
    }

    return smoothPaths(result, 0.2);
}
