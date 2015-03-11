function pe5()
	local i = 20
	while true do
		i = i + 20
		local isdiv = false
		for n = 3, 19 do
			if i%n ~= 0 then
				isdiv = true
				break
			end
		end
		if not isdiv then
			return i
		end
	end
end
