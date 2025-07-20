#include "infill_preview.h"
#include <fstream>

void InfillPreview::renderSVG(const std::vector<Contour>& infill, const Contour& boundary, const std::string& filename) {
    std::ofstream svg(filename);
    if (!svg.is_open()) return;

    double x_min = boundary.points[0].x, x_max = boundary.points[0].x;
    double y_min = boundary.points[0].y, y_max = boundary.points[0].y;

    for (const auto& pt : boundary.points) {
        if (pt.x < x_min) x_min = pt.x;
        if (pt.x > x_max) x_max = pt.x;
        if (pt.y < y_min) y_min = pt.y;
        if (pt.y > y_max) y_max = pt.y;
    }

    svg << "<svg xmlns='http://www.w3.org/2000/svg' width='800' height='800' viewBox='" << x_min << " " << y_min << " "
        << (x_max - x_min) << " " << (y_max - y_min) << "'>
";

    svg << "<g stroke='black' stroke-width='0.1' fill='none'>
";

    for (const auto& contour : infill) {
        svg << "<path d='M ";
        for (size_t i = 0; i < contour.points.size(); ++i) {
            svg << contour.points[i].x << " " << contour.points[i].y;
            if (i != contour.points.size() - 1)
                svg << " L ";
        }
        svg << "' />
";
    }

    svg << "</g>
";

    svg << "<g stroke='red' stroke-width='0.2' fill='none'>
";
    svg << "<path d='M ";
    for (size_t i = 0; i < boundary.points.size(); ++i) {
        svg << boundary.points[i].x << " " << boundary.points[i].y;
        if (i != boundary.points.size() - 1)
            svg << " L ";
    }
    svg << " Z' />
";
    svg << "</g>
";

    svg << "</svg>
";
}
void renderSupportsSVG(const std::vector<Contour>& supports, std::ofstream& svg) {
    svg << "<g stroke='blue' stroke-width='0.15' fill='none'>\n";
    for (const auto& support : supports) {
        svg << "<path d='M ";
        for (size_t i = 0; i < support.points.size(); ++i) {
            svg << support.points[i].x << " " << support.points[i].y;
            if (i != support.points.size() - 1)
                svg << " L ";
        }
        svg << " Z' />\n";
    }
    svg << "</g>\n";
}
