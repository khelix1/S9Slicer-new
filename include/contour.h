#pragma once
#include <vector>
#include <cmath>

/// Basic 2D point used in contours
struct Point {
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    /// Check equality with a tolerance
    bool nearlyEquals(const Point& other, double epsilon = 1e-6) const {
        return std::fabs(x - other.x) < epsilon && std::fabs(y - other.y) < epsilon;
    }
};

/// A contour is a polyline used for perimeters, infill boundaries, skins, etc.
class Contour {
public:
    std::vector<Point> points;

    /**
     * @brief Ensure the contour is closed (first and last point are the same).
     * Adds the first point to the end if not already closed.
     */
    void close();

    /**
     * @brief Check if the contour is closed.
     * A contour is considered closed if it has at least 3 points and the
     * first and last points are nearly equal.
     *
     * @return true if closed, false otherwise.
     */
    bool isClosed() const;
};
