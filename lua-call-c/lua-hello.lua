package.cpath = package.cpath .. ";build/add.so"

local c = require "add"
local addTwo = c.adder(2)
print(addTwo(3))                -- 5
