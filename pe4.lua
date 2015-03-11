function ispal(n)
	local l = 1
	while true do
		if n%(10^l) == n then
			break
		end
		l = l+1
	end
	-- alt: local l = math.ceil(math.log10(n+1))
	for i = 1, math.floor(l/2) do
		if math.floor(n*10^(i-l))%10 ~= math.floor((n%(10^i))*10^(1-i)) then
			return false
		end
	end
	return true
end

function pe4()
	local gp = 0
	for x = 100, 999 do
		for y = 100, 999 do
			local n = x*y
			if ispal(n) then
				if n > gp then
					gp = n
				end
			end
		end
	end
	return gp
end
