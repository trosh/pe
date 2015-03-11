maxm = 0
for a in xrange(100):
	for b in xrange(100):
		n = a ** b
		m = 0
		while n != 0:
			m += n%10
			n /= 10
		if m > maxm:
			maxm = m
print maxm
