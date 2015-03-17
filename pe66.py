import sys
import math

rt = 2
maxD = 1
maxx = 0
for D in xrange(2, 1001):
    if D == rt**2:
        rt += 1
        continue
    cnt = 0
    y = 2
    while True:
        sqx = 1+D*y**2
        cnt += 1
        if cnt%50000 == 0:
            sys.stdout.write(`y`+"..")
            sys.stdout.flush()
        x = math.sqrt(sqx)
        if x == math.floor(x):
            if x > maxx:
                maxx = x
                maxD = D
            break
        y += 1
    print "D=", D, "x=", x
print "maxD=", maxD, "maxx=", maxx
