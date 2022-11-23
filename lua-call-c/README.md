# lua call c

## url
copy from [从Lua调用C/C++](https://ngn999.github.io/2014/07/02/%E4%BB%8ELua%E8%B0%83%E7%94%A8C-C/)


## run command
``` shell
gcc -I /usr/local/include/lua/ -llua -g -O0 -Wall -fPIC -dynamiclib  add.c -o add.so

lua lua-hello.lua
```
