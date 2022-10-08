cmake_minimum_required(VERSION 3.12)

# Set the project name and version
project(Piano VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug 
    CACHE STRING 
      "Choose the type of build (Debug or Release)" FORCE)
endif()

# Export compile commands for completion engines (optional)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

# Including custom headers
include_directories(./include)

# Compile executable
add_executable(Piano 
    ./src/main.cpp 
    ./src/key/key.cpp 
    ./src/key/black.cpp 
    ./src/key/white.cpp 
    ./src/octave/white.cpp 
    ./src/octave/black.cpp
    ./src/piano.cpp
)

# Link executable to required SFML modules
target_link_libraries(Piano sfml-graphics sfml-audio)