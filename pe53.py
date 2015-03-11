#!/usr/bin/python

import math
cnt = 0
for n in xrange(1, 101):
    for r in xrange(n+1):
        p = math.factorial(n)/math.factorial(r)/math.factorial(n-r)
        if p > 1000000:
            cnt += 1
print cnt
