#pragma once
#include "../contour.h"
#include <vector>

/// SkinGenerator creates hatch line fills for top and bottom solid layers.
/// The fill is based on the bounding box of the given outer contour.
/// This generator is a simplified substitute until real clipping logic is applied.
class SkinGenerator {
public:
    /**
     * @brief Generate horizontal hatch fill lines for the top skin layer.
     * Fills the bounding box of the outer contour with horizontal lines spaced evenly.
     *
     * @param outer The outer perimeter contour of the layer region to fill.
     * @return std::vector<Contour> A vector of Contour objects representing fill lines.
     */
    static std::vector<Contour> generateTopSkin(const Contour& outer);

    /**
     * @brief Generate horizontal hatch fill lines for the bottom skin layer.
     * Uses the same logic as generateTopSkin for now.
     *
     * @param outer The outer perimeter contour of the layer region to fill.
     * @return std::vector<Contour> A vector of Contour objects representing fill lines.
     */
    static std::vector<Contour> generateBottomSkin(const Contour& outer);
};
