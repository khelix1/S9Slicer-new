
#pragma once
#include "clipper.hpp"

ClipperLib::Paths smoothPaths(const ClipperLib::Paths& input, double tolerance);
