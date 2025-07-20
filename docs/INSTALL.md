# Installation Guide

## Requirements
- C++17 compatible compiler (g++, clang++)
- Clipper2 (optional: embedded or system-wide)
- CMake (for build automation)

## Build Instructions
```bash
mkdir build
cd build
cmake ..
make -j4
```

## Run
```bash
./s9slicer path/to/model.stl -o output.gcode
```
