#!./luajit

assert(#arg > 0, "need 1 arg: problem number")
if not _G["pe"..arg[1]] then
	require("pe"..arg[1])
end
assert(_G["pe"..arg[1]], "wrong problem number")
print(_G["pe"..arg[1]](arg[2]))
