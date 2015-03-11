function pe26(m)
	if not m then m = 10 end
	local md = 0
	for n = 2, m do
		local d = 0
		local r = {10%n}
		while true do
			local i = (r[#r]*10)%n
			if i == 0 then break end
			for j = 1, #r do
				if r[j] == i then
					d = #r-j+1
					break
				end
			end
			if d ~= 0 then break end
			table.insert(r, i)
		end
		if d > md then
			md = d
			print(n, md)
		end
	end
end
