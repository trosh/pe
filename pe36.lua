-- NOTE: c/pe36.c IS BETTER AND FASTER

function pe36()
	local function ispal(n, b)
		local a = {}
		while n > 0 do
			table.insert(a, n%b)
			n = math.floor(n/b)
		end
		for i = 1, #a/2 do
			if a[i] ~= a[#a-i+1] then return false end
		end
		return true
	end
	local sum = 0
	for i = 1, 1e6-1, 2 do
		if ispal(i, 10) and ispal(i, 2) then
			sum = sum + i
		end
	end
	return sum
end
