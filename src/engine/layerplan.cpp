#include "layerplan.h"
using namespace ClipperLib;

LayerPlan::LayerPlan(double z) : zHeight(z) {}
void LayerPlan::addPerimeters(const Paths& p) { perimeters.insert(perimeters.end(), p.begin(), p.end()); }
void LayerPlan::addInfill(const Paths& p) { infill.insert(infill.end(), p.begin(), p.end()); }
void LayerPlan::addSkin(const Paths& t, const Paths& b) { topSkin.insert(topSkin.end(), t.begin(), t.end()); bottomSkin.insert(bottomSkin.end(), b.begin(), b.end()); }
void LayerPlan::addSupports(const Paths& p) { supports.insert(supports.end(), p.begin(), p.end()); }
void LayerPlan::addBridges(const Paths& p) { bridges.insert(bridges.end(), p.begin(), p.end()); }
const Paths& LayerPlan::getPerimeters() const { return perimeters; }
const Paths& LayerPlan::getInfill() const { return infill; }
const Paths& LayerPlan::getTopSkin() const { return topSkin; }
const Paths& LayerPlan::getBottomSkin() const { return bottomSkin; }
const Paths& LayerPlan::getSupports() const { return supports; }
const Paths& LayerPlan::getBridges() const { return bridges; }
double LayerPlan::getZ() const { return zHeight; }