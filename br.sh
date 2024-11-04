#!/bin/bash

# Navigate to the build directory
BUILD_DIR="./build"

# Check if the build directory exists
if [ ! -d "$BUILD_DIR" ]; then
    echo "Build directory does not exist. Creating it..."
    mkdir -p "$BUILD_DIR"
fi

# Move into the build directory
cd "$BUILD_DIR" || exit

# Run cmake and make
echo "Running CMake..."
cmake .. || { echo "CMake failed"; exit 1; }

echo "Building the project..."
make || { echo "Make failed"; exit 1; }

# Run the program
echo "Running the program..."
./GameOff2024 || { echo "Execution failed"; exit 1; }
