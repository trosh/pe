function pe44()
	local function penshit(n)
		return n*(3*n-1)/2
	end
	local function unpenshit(n)
		local x = n/2
		while penshit(x) > n do
			x = x/2
		end
		for i = 1, 6 do
			x = (3*x*x+2*n)/(6*x-1)
		end
		return x
	end
	local d = math.huge
	local k = 10
	local ld = math.huge
	while true do
		for i = k/10, k do
			for j = math.max(1, i-ld), i-1 do
				local n = penshit(i) + penshit(j)
				if unpenshit(n) % 1 < 1e-4 then
					local m = penshit(i) - penshit(j)
					if unpenshit(m) % 1 < 1e-4 then
						print(i, j, m)
						if m < d then d = m ; ld = i-j end
					end
				end
			end
		end
		if d ~= math.huge then print("curr d:", d) end
		k = k * 10
	end
end
