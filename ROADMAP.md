# S9Slicer Roadmap

## ✅ Completed (up to v0.7.8.1)
- STL parsing (ASCII/Binary)
- Layer slicing and Z-stack planner
- Perimeter walls: inner-to-outer, Clipper-based
- Infill types:
  - Grid
  - Lines
  - Gyroid
  - Concentric
  - Archimedean
  - Triangle
- Sparse infill substitution
- Top/bottom skin generation
- Bridge fill detection
- Retraction, Z-hop, wipe logic
- Support types:
  - Grid
  - Line
  - Concentric
- Support extrusion path generation
- SupportPlanner integration
- CLI interface: --version, --support-type, --test-support
- Full packaging for GitHub releases

---

## 🔜 v0.7.9 Goals
- Support extrusion to G-code output
- Bridging extrusion path generation
- Sparse support fill detection + integration
- CLI feature toggles for sparse, bridging, support options
- Visual preview mode (CLI/test for now)

---

## 🔮 v0.8.0 Preview
- Skirt, brim, and raft logic
- Multi-tool support planning
- Material-specific behavior toggles
- Configurable slicing profiles (config loader)
- Initial Qt6 Preview UI for Linux Mint/Debian
- G-code validation & dry run preview

---

## 🧪 Experimental / Long-Term
- Adaptive infill & supports
- Overhang detection for support auto-placement
- OctoPrint/G-code streaming preview mode
- Color-coded path type visualization

### ✅ v0.8.0-pre7 (Current Release)
- CLI: --enable-arcwelder support added
- ArcWelderLib embedded in build via CMake
- ArcGCode simulation implemented in ArcWelderWrapper
- Hooked into main G-code generator path

### 🔜 Coming in v0.8.0-pre8
- Real arc fitting with I/J and E axis tuning
- ArcWelderLib precision CLI flags
- Combined support with ArcFitter fallback
