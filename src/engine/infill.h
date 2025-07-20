#pragma once
#include "clipper.hpp"

ClipperLib::Paths generateGridInfill(const ClipperLib::Paths& boundary, double spacing);