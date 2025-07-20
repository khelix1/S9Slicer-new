#pragma once
#include "clipper.hpp"

ClipperLib::Paths clipToBoundary(const ClipperLib::Paths& input, const ClipperLib::Paths& bounds);