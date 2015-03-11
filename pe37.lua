function pe37()
	local k = {}
	local primes = {}
	for i = 2, 1e6 do
		if not k[i] then
			table.insert(primes, i)
			for j = 2*i, 1e6, i do
				k[j] = true
			end
		end
	end
	k = nil
	local function isprime(n)
		for _, j in ipairs(primes) do
			if j == n then return true end
			if j > n then return false end
		end
	end
	local function trunc(m)
		local n = m
		local i = 10
		while n > i do
			if not isprime(n%i) then return false end
			i = i*10
		end
		i = nil
		while true do
			m = math.floor(m/10)
			if m == 0 then break end
			if not isprime(m) then return false end
		end
		return true
	end
	local sum = 0
	local cnt = 0
	for i = 5, #primes do
		if trunc(primes[i]) then
			sum = sum + primes[i]
			cnt = cnt + 1
			if cnt == 11 then return sum end
		end
	end
	return "reached prime table limit"
end
