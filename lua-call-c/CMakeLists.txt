cmake_minimum_required(VERSION 3.10)
project(add C)

find_package(Lua REQUIRED)

# If funct.c is in the src directory, change this to src/add.c
add_library(add MODULE add.c)

# Set the output name of the library to funct.so without any prefix
set_target_properties(add PROPERTIES PREFIX "")
set_target_properties(add PROPERTIES OUTPUT_NAME "add")

target_include_directories(add PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(add ${LUA_LIBRARIES})
