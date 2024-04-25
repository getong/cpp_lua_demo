#include <lauxlib.h>
#include <lua.h>
#include <stdio.h>

static int _do_adder(lua_State *L) {
  double base = lua_tonumber(L, lua_upvalueindex(1));
  double to_add = luaL_checknumber(L, 1);
  lua_pushnumber(L, base + to_add);

  return 1;
}

static int _adder(lua_State *L) {
  /* double base = luaL_checknumber(L, 1); */
  lua_pushvalue(L, 1);
  /* 1 upvalue */
  lua_pushcclosure(L, _do_adder, 1);
  /* the c closure */
  return 1;
}

int luaopen_add(lua_State *L) {
  luaL_checkversion(L);

  luaL_Reg l[] = {
      {"adder", _adder},
      {NULL, NULL},
  };
  luaL_newlib(L, l);
  luaL_setfuncs(L, l, 0);
  /* 返回一个结果，一个table */
  return 1;
}
