cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(GameOff24Jam VERSION 1.0)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate SFML (adjust paths if needed)
if (WIN32)
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")  # Update path if SFML is installed elsewhere
endif()
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Add the source files
add_executable(GameOff2024 src/main.cpp)

# Link SFML libraries
target_link_libraries(GameOff2024 sfml-system sfml-window sfml-graphics sfml-audio)
