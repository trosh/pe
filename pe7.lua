function pe7()
	local primes = {}
	local cnt = 0
	for i = 2, 1e6 do
		if not primes[i] then
			for z = 2*i, 1e6, i do
				primes[z] = true
			end
			cnt = cnt + 1
			if cnt == 10001 then
				return i
			end
		end
	end
	return 0
end
