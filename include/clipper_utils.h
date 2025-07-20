#pragma once
#include "../contour.h"
#include <vector>

/// Utility functions for converting between S9Slicer Contour format and Clipper2 paths.
/// Used by any module that interfaces with Clipper2 (e.g., perimeter generation, infill clipping).
namespace ClipperUtils {

    /**
     * @brief Convert a single Contour into a Clipper2 PathD.
     * @param contour The Contour to convert.
     * @return PathD Clipper2-compatible double-precision path.
     */
    PathD toClipperPath(const Contour& contour);

    /**
     * @brief Convert a vector of Contours into a Clipper2 PathsD.
     * @param contours The vector of Contours to convert.
     * @return PathsD Vector of Clipper2-compatible paths.
     */
    PathsD toClipperPaths(const std::vector<Contour>& contours);

    /**
     * @brief Convert a Clipper2 PathD into a Contour.
     * @param path The Clipper2 path to convert.
     * @return Contour The equivalent Contour format.
     */
    Contour fromClipperPath(const PathD& path);

    /**
     * @brief Convert a Clipper2 PathsD into vector of Contours.
     * @param paths The Clipper2 paths to convert.
     * @return std::vector<Contour> Vector of equivalent Contours.
     */
    std::vector<Contour> fromClipperPaths(const PathsD& paths);

}
