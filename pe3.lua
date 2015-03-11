function pe3()
	local n = 600851475143
	for i = 2, n-1 do
		if n%i == 0 then
			local f = n/i
			local isprime = true
			for r = 2, math.ceil(math.sqrt(f)) do
				if f%r == 0 then
					isprime = false
					break
				end
			end
			if isprime then
				return f
			end
		end
	end
end
