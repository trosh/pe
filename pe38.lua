function pe38()
	local function mulshit(x, n)
		local s = ""
		for i = 1, n do
			s = s .. x*i
		end
		return s
	end
	local function ispanshit(s)
		if #s ~= 9 then return false end
		for i = 1, 9 do
			if string.sub(s, i, i) == "0" then
				return false
			end
			local m = tostring(i)
			local cnt = 0
			for j = 1, 9 do
				if string.sub(s, j, j) == m then
					cnt = cnt + 1
					if cnt == 2 then return false end
				end
			end
		end
		return true
	end
	local maxmulshit = 0
	for n = 2, 9 do
		local x = 1
		while true do
			local s = mulshit(x, n)
			if #s > 9 then break end
			if ispanshit(s) then
				if s > tostring(maxmulshit) then
					maxmulshit = s
				end
			end
			x = x + 1
		end
	end
	return maxmulshit
end
