assert(bit, "run with luajit for bit array")
local band, bor, brs, bls = bit.band, bit.bor, bit.rshift, bit.lshift
local up = 1e6
local primes = {}
for i = 0, brs(up, 5)+1 do primes[i] = 0 end
local function isprime(n)
	return band(primes[brs(n, 5)], bls(1, n%32)) == 0 
end
for n = 2, up do
	if isprime(n) then
		for m = 2*n, up, n do
			local pos = brs(m, 5)
			primes[pos] = bor(primes[pos], bls(1, m%32))
		end
	end
end

print("built primes up to", up)

local function primefactors(n)
	return "bleh"
end
os.exit(0) --fuck the system
