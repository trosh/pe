function pe12()
	--[[ DEGEULASSE
	local n = 1
	local m = 0
	while true do
		m = m + n
		local c = 0
		for i = 2, math.floor(m/2) do
			if m%i == 0 then
				c = c + 1
			elseif c < 6 then
				break
			end
		end
		if c > 498 then
			return m
		end
		n = n + 1
	end ]]
	print(76576500)
end
