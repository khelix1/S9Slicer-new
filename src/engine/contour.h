#pragma once
#include "clipper.hpp"

ClipperLib::Paths offsetContour(const ClipperLib::Paths& input, double offset);