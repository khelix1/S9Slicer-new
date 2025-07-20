# S9Slicer

S9Slicer is a high-performance, open-source 3D printing slicer optimized for the Sunlu S9+ and advanced multi-material systems. Built from the ground up in C++ with Qt6 and Clipper2 integration.

## Features

- Full STL parsing (ASCII and Binary)
- Dynamic G-code generation
- Clipper2-powered perimeter generation
- Layer planning with extrusion logic
- Modular slicing engine with professional documentation
- Designed for expansion: supports, infill, GUI coming in v0.8+

## Build Instructions

```bash
mkdir build && cd build
cmake ..
make
```

## Run Example

```bash
./s9slicer path/to/model.stl
```

## License

MIT License – with a request to credit for 3D printing or slicing-related use. See LICENSE file.
