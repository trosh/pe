function pe9()
	for a = 1, 999 do
		for b = a+1, 999 do
			local c = math.sqrt(a^2+b^2)
			if math.floor(c) == c then
				if a^2+b^2 == c^2 then
					if a+b+c == 1000 then
						return a*b*c
					end
				end
			end
		end
	end
end
