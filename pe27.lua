function pe27()
	local sieve = {}
	local primes = {}
	local upper = 1e7
	for i = 2, upper do
		if not sieve[i] then
			table.insert(primes, i)
			for j = 2*i, upper, i do
				sieve[j] = true
			end
		end
	end
	print("built primes")
	local m = {0, 0, 0}
	for a = -999, 999 do
		for b = -999, 999 do
			local n = 0
			while true do
				local i = n^2 + a*n + b
				if i < 1 then i = -i end
				if i > 1e7 then
					return
				end
				local isprime = true
				for _, j in ipairs(primes) do
					if i == j then break end
					if i < j then isprime = false ; break end
				end
				if not isprime then
					if n > m[3] then
						m = {a, b, n-1}
					end
					break
				end
				n = n + 1
			end
		end
	end
	return m[1]*m[2]
end
