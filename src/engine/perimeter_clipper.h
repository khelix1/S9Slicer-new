#pragma once
#include "clipper.hpp"

ClipperLib::Paths generatePerimeters(const ClipperLib::Paths& boundary, int count, double spacing);