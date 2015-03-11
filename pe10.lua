function pe10()
	local s = 2
	local p = {}
	for i = 3, 2e6-1, 2 do
		if not p[i] then
			s = s + i
			for j = 2*i, 2e6, i do
				p[j] = true
			end
		end
	end
	return s
end
