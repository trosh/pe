from decimal import *
getcontext().prec = 105
squares = [n*n for n in xrange(100)]
cnt = 0
for n in xrange(100):
    if n in squares:
        continue
    s = str(Decimal(n).sqrt())
    cnt += int(s[0]) \
            + sum([int(c) for c in s[2:101]])
    print n, s
print cnt
