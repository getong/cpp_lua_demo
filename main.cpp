#include <iostream>
#include <lua.hpp>

extern "C" {
    static int l_cppfunction(lua_State *L) {
        double arg = luaL_checknumber(L,1);
        lua_pushnumber(L, arg * 0.5);
        return 1;
    }
}

using namespace std;

int main(int argc, const char * argv[])
{
    lua_State *L;
    L = luaL_newstate();
    cout << ">> 载入（可选）标准库，以便使用打印功能" << endl;
    luaL_openlibs(L);
    cout << ">> 载入文件，暂不执行" << endl;
    if (luaL_loadfile(L, "luascript.lua")) {
        cerr << "载入文件出现错误" << endl;
        cerr << lua_tostring(L, -1) << endl;
        lua_pop(L,1);
    }

    cout << ">> 从 C++ 写入数据 cppvar" << endl;
    lua_pushnumber(L, 1.1);
    lua_setglobal(L, "cppvar");

    cout << ">> 执行 lua 文件" << endl << endl;
    if (lua_pcall(L,0, LUA_MULTRET, 0)) {
        cerr << "执行过程中出现错误" << endl;
        cerr << lua_tostring(L, -1) << endl;
        lua_pop(L,1);
    }

    cout << ">> 从 Lua 读取全局变量 luavar 到 C++" << endl;
    lua_getglobal(L, "luavar");
    double luavar = lua_tonumber(L,-1);
    lua_pop(L,1);
    cout << "C++ 从 Lua 读取到的 luavar = " << luavar << endl << endl;

    cout << ">> 从 C++ 执行 Lua 的方法 myfunction" << endl;
    lua_getglobal(L, "myluafunction");
    lua_pushnumber(L, 5);
    lua_pcall(L, 1, 1, 0);
    cout << "函数返回值是：" << lua_tostring(L, -1) << endl << endl;
    lua_pop(L,1);

    cout << ">> 从 Lua 执行 C++ 的方法" << endl;
    cout << ">>>> 首先在 Lua 中注册 C++ 方法" << endl;
    lua_pushcfunction(L,l_cppfunction);
    lua_setglobal(L, "cppfunction");

    cout << ">>>> 调用 Lua 函数以执行 C++ 函数" << endl;
    lua_getglobal(L, "myfunction");
    lua_pushnumber(L, 5);
    lua_pcall(L, 1, 1, 0);
    cout << "函数返回值是：" << lua_tonumber(L, -1) << endl << endl;
    lua_pop(L,1);

    cout << ">> 释放 Lua 资源" << endl;
    lua_close(L);

    return 0;
}
