max = 100000000
sieve = [0 for i in xrange(max)]
for i in xrange(2, max):
	if sieve[i] == 0:
		for j in xrange(2*i, max, i):
			sieve[j] = 1

def isprime(n):
	return n>1 and sieve[n] == 0

print "prime init"

m = 2
n = 1
primecnt = 0.
diagcnt = 1
while True:
	for i in xrange(4):
		n += m
		if isprime(n): primecnt += 1
	diagcnt += 4
	if 10*primecnt < diagcnt:
		print m+1
		break
	m += 2
