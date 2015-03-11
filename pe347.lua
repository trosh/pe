function pe347()
	-- shit's fd up
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
	local function M(m, n, p)
		if m > n then m, n = n, m end -- n is largest
		local i = n
		while i <= p do
			if i%m == 0 then
				local islidtp = true
				local t = 1
				while t < #primes do
					if i%primes[t] == 0
					and primes[t] ~= n
					and primes[t] ~= m then
						islidtp = false
						break
					end
					t = t + 1
				end
				if islidtp then
					return i
				end
			end
			i = i + n
		end
		return 0
	end
	local S = 0
	local m = #primes - 1
	local cnt = 0
	while primes[m] and primes[m] <= upper do
		local n = m + 1
		while primes[n] and primes[n] <= upper do
			local lidtp = M(primes[m], primes[n], upper)
			if cnt%150000 == 0 then
				print(primes[m], primes[n], lidtp)
			end
			cnt = cnt + 1
			S = S + lidtp
			n = n + 1
		end
		m = m - 1	
	end
	print(S)
end
