#pragma once
#include "clipper.hpp"

ClipperLib::Paths generateSkin(const ClipperLib::Paths& boundary, double spacing, bool alternate);