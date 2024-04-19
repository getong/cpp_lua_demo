cmake_minimum_required(VERSION 3.10)  # Set the minimum version of CMake

# Define the project name and the language used
project(cpp-call-lua VERSION 1.0.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Lua libraries
find_library(LUA_LIBRARY NAMES lua5.4 lua54 lua PATHS /usr/local/lib /usr/lib)

# Check if Lua library was found
if(NOT LUA_LIBRARY)
  message(FATAL_ERROR "Lua library not found")
endif()

# Include directories for Lua
include_directories(/usr/local/include/lua/)

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link Lua library
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARY})
