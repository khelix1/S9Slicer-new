#pragma once
#include <vector>
#include "clipper.hpp"

class LayerPlan {
public:
    LayerPlan(double z);
    void addPerimeters(const ClipperLib::Paths& paths);
    void addInfill(const ClipperLib::Paths& paths);
    void addSkin(const ClipperLib::Paths& top, const ClipperLib::Paths& bottom);
    void addSupports(const ClipperLib::Paths& paths);
    void addBridges(const ClipperLib::Paths& paths);
    const ClipperLib::Paths& getPerimeters() const;
    const ClipperLib::Paths& getInfill() const;
    const ClipperLib::Paths& getTopSkin() const;
    const ClipperLib::Paths& getBottomSkin() const;
    const ClipperLib::Paths& getSupports() const;
    const ClipperLib::Paths& getBridges() const;
    double getZ() const;
private:
    double zHeight;
    ClipperLib::Paths perimeters, infill, topSkin, bottomSkin, supports, bridges;
};