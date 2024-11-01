cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(GameOff24Jam VERSION 1.0)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable generation of compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Locate and link SFML libraries
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Add the source files
add_executable(GameOff2024 
    src/main.cpp
    src/game.cpp
    src/input_manager.cpp
    src/entity.cpp
    src/player.cpp
)

# Link SFML libraries to the executable
target_link_libraries(GameOff2024 sfml-system sfml-window sfml-graphics sfml-audio)
