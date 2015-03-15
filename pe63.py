low = 1
upp = 10*low
cnt = 0
for nd in xrange(1, 22):
    i = 1
    while True:
        n = i
        for j in xrange(nd-1):
            n *= i
        i += 1
        if n < low:
            continue
        if n >= upp:
            break
        print i-1, nd, n
        cnt += 1
    low *= 10
    upp *= 10
print "cnt:", cnt
