function pe35(m)
	if not m then m = 100 else m = m + 0 end
	local k = {}
	local primes = {}
	for i = 2, m do
		if not k[i] then
			table.insert(primes, i)
			for j = 2*i, m, i do
				k[j] = true
			end
		end
	end
	k = nil
	print("built prime table up to "..primes[#primes])
	local function ntoa(n)
		local l = math.floor(math.log10(n))+1
		local a = {}
		for i = 1, l do
			table.insert(a, n%10)
			n = math.floor(n/10)
		end
		return a
	end
	local function aton(a)
		local n = 0
		for i = 1, #a do
			n = n + a[i]*10^(i-1)
		end
		return n
	end
	local function rot(a)
		local iscp = true
		for i = 1, #a-1 do
			local r = a[1]
			table.remove(a, 1)
			table.insert(a, r)
			local n = aton(a)
			for _, j in ipairs(primes) do
				if j == n then
					break
				elseif j > n then
					iscp = false
					break
				end
			end
			if not iscp then
				break
			end
		end
		if iscp then
			return true
		end
	end
	local cnt = 4
	for j = 5, #primes do
		local n = primes[j]
		if n >= m then break end
		local a = ntoa(n)
		local good = true
		for _, i in ipairs(a) do
			if  i ~= 1 and i ~= 3
			and i ~= 7 and i ~= 9 then
				good = false
				break
			end
		end
		if good and rot(a) then
			cnt = cnt + 1
		end
	end
	return cnt
end
