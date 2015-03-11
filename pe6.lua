function pe6()
	local sqos = 0
	for i = 1, 100 do
		sqos = sqos + i
	end
	sqos = sqos^2
	local sosq = 0
	for i = 1, 100 do
		sosq = sosq + i^2
	end
	return sqos - sosq
end
