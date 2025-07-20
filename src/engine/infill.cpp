
std::vector<Contour> InfillGenerator::generateSparse(const Contour& boundary, float spacing, int layerIndex, int interval) {
    std::vector<Contour> infill;

    if (layerIndex % interval != 0) {
        std::cout << "[InfillGenerator] Skipping sparse infill at layer " << layerIndex << "\n";
        return infill;
    }

    std::cout << "[InfillGenerator] Generating sparse infill at layer " << layerIndex << " every " << interval << " layers\n";
    infill = generateLine(boundary, spacing, 45.0f);  // Example: 45 degree sparse infill
    return clipToBoundary(infill, boundary);
}

std::vector<Contour> InfillGenerator::generateBridgeFill(const Contour& boundary, const Contour& layerBelow, float spacing) {
    std::vector<Contour> bridges;
    std::cout << "[InfillGenerator] Generating bridge fill using spacing " << spacing << "\n";

    // Naive bridge detection: compare if any points in boundary don't overlap layerBelow
    bool isBridgeRegion = false;
    for (const auto& pt : boundary.points) {
        bool supported = false;
        for (const auto& belowPt : layerBelow.points) {
            double dx = pt.x - belowPt.x;
            double dy = pt.y - belowPt.y;
            if (std::sqrt(dx * dx + dy * dy) < spacing / 2.0) {
                supported = true;
                break;
            }
        }
        if (!supported) {
            isBridgeRegion = true;
            break;
        }
    }

    if (!isBridgeRegion) {
        std::cout << "[InfillGenerator] Skipped: region fully supported.\n";
        return bridges;
    }

    // Use 90 degree lines (or use bridge angle heuristics)
    auto raw = generateLine(boundary, spacing, 90.0f);
    bridges = clipToBoundary(raw, boundary);

    return bridges;
}
