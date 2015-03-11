def ispal(n):
	digits = []
	i = 0
	while n != 0:
		digits.append(n%10)
		n /= 10
		i += 1
	i -= 1
	j = i
	while j>=0:
		if digits[j] != digits[i-j]:
			return False
		j -= 1
	return True

def rev(n):
	m = 0
	while n != 0:
		m *= 10
		m += n%10
		n /= 10
	return m

lychrelcnt = 0
for i in xrange(10000):
	j = i + rev(i)
	for itercnt in xrange(1, 50):
		if ispal(j):
			break
		j += rev(j)
	else:
		lychrelcnt += 1
print "lychrel numbers < 10000 :", lychrelcnt
