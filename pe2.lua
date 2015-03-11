function pe2()
	local a = 1
	local b = 2
	local s = 2
	while true do
		local c = a + b
		if c > 4e6 then break end
		if c%2 == 0 then s = s + c end
		a = b
		b = c
	end
	return s
end
