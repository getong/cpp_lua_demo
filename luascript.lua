print("Hello from Lua")
print("Lua code is capable of reading the value set from C++", cappvar)
luavar = cppvar * 3

function myluafuntion(times)
   return string.rep("(-)", times)
end

function myfunction(arg)
   return cppfunction(arg)
end
