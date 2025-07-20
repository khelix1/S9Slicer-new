
## [v0.8.0-pre6] — Travel Optimization, Gap Control, Z-Hop

### ✨ Added
- Travel move optimization with gap distance check
- Z-hop and retraction logic during long travel moves
- Prime after move to resume extrusion
- Vertical air gap (0.2mm) for support/bridge interface layers

### 🧪 New Test Modes
- `--test-support-gap` — outputs `support_gap_output.gcode`


## [v0.8.0-pre5] — Support Interface, Perimeter, and Skin Layers

### ✨ Added
- Support interface extrusion layers with vertical separation
- Support perimeter wall generation with offset control
- Sealing skins for top of supports using layer stacking
- CLI Test Modes:
  - `--test-support-interface`
  - `--test-support-perimeter`

### 🧪 Outputs
- `support_interface_output.gcode`
- `support_perimeter_output.gcode`

## [v0.8.0-pre3] - Extrusion Smoothing and Ordering
- Added `path_smoothing` module
- Automatically smooth and order perimeter + infill paths to reduce travel
- Optimized output by reducing unnecessary moves

## [v0.7.8] - 2025-07-19
### Added
- SupportPathGenerator module with grid, line, and concentric path logic
- SupportPlanner integration with type switching and extrusion path generation
- Packaged ready for preview, slicing pipeline compatibility

### Packaging
- Fully structured GitHub release
- All source, headers, documentation, and external libraries included

## [v0.7.8.1] - 2025-07-19
### Changed
- Cleaned up CLI interface in `main.cpp`
- Added support for `--support-type`, `--test-support`, and `--version` flags
- Version-locked using `version.h` and `version.txt`

### Added in v0.7.9-dev
- `support_gcode.cpp/.h`: emits G-code from support extrusion paths
- `--export-support-gcode`: CLI option to output support-only G-code

### Added in v0.7.9-dev
- `bridge_extrusion.cpp/.h`: Detects and generates extrusion paths for bridging regions

- `--test-bridge`: CLI mode to preview bridge extrusion G-code

- Sparse support detection and adjustable density
- `--test-sparse-support`: CLI test mode for sparse support generation

- Full skin extrusion support for top and bottom solid layers
- `--test-skin`: CLI test mode for skin preview G-code

## [v0.8.0-pre7] - ArcWelder CLI Integration

### Added
- Embedded ArcWelderLib C++ engine in `external/arcwelder/`
- New CLI flag: `--enable-arcwelder` for G-code arc optimization
- Smart fallback: compresses G1s into G2/G3 using wrapper logic
- Output simulation confirmed working and CLI-tested

### Planned
- Replace simulation with full ArcWelderLib internal path support
