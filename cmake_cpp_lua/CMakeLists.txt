cmake_minimum_required(VERSION 3.10)  # Set the minimum version of CMake

project(cmake_cpp_lua VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Lua libraries
find_library(LUA_LIBRARY NAMES lua5.4 lua54 lua PATHS /usr/local/lib /usr/lib)
if(NOT LUA_LIBRARY)
  message(FATAL_ERROR "Lua library not found")
endif()

# Include directories for Lua
include_directories(/usr/local/include/lua/)

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link Lua library
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARY})