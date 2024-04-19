#include <iostream>
#include <lua.hpp>  // Make sure this matches the include path for Lua headers

int main() {
  lua_State *L = luaL_newstate();  // Create a new Lua state
  luaL_openlibs(L);               // Open the standard libraries

  // Load and run a simple Lua script
  if (luaL_dofile(L, "script.lua") != LUA_OK) {
    std::cerr << "Error loading script: " << lua_tostring(L, -1) << std::endl;
  }

  lua_close(L);  // Close the Lua state
  return 0;
}

// g++ -std=c++20 main.cpp -I /usr/local/include/lua/ -llua
