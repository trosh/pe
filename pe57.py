cnt = 0
for i in xrange(1, 1001):
	num = 1
	den = 2
	for j in xrange(i-1):
		num += 2*den
		num, den = den, num
	num += den
	lennum = lenden = 0
	while num != 0:
		lennum += 1
		num /= 10
	while den != 0:
		lenden += 1
		den /= 10
	if lennum > lenden:
		cnt += 1
print cnt
