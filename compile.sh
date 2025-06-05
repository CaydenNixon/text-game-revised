#!/bin/bash
# Exit if any command fails
set -e

# Create build directory if it doesn't exist
[ -d build ] || mkdir build

# Generate Makefiles and build
cmake -S . -B build
cmake --build build