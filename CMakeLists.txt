cmake_minimum_required(VERSION 3.10)
project(S9Slicer)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    src
    src/engine
    external/clipper
    external/arcwelder
)

# Source files
file(GLOB_RECURSE ENGINE_SOURCES src/engine/*.cpp)
file(GLOB_RECURSE MAIN_SOURCES src/*.cpp)
file(GLOB_RECURSE CLIPPER_SOURCES external/clipper/*.cpp)
file(GLOB_RECURSE ARCWELDER_SOURCES external/arcwelder/*.cpp)

add_executable(s9slicer
    ${ENGINE_SOURCES}
    ${MAIN_SOURCES}
    ${CLIPPER_SOURCES}
    ${ARCWELDER_SOURCES}
)

# Optional: Install rule
install(TARGETS s9slicer DESTINATION bin)
