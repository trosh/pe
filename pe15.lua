function pe15(m)
	local function fact(n)
		local f = 1
		for i = 2, n do
			f = f*i
		end
		return f
	end
	if not m then m = 20 end
	return fact(2*m)/fact(m)^2
end
