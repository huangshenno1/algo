from __future__ import division

def u(n):
    ret = 0
    for i in xrange(0, 11):
	ret += (-1)**i * n**i
    return ret

def solve(k):
    a = []	
    for n in xrange(1, k+1):
	x = [n**x for x in xrange(0, k)]
	x.append(u(n))
	a.append(x)
    for j in xrange(0, k):
	for i in xrange(0, k):
	    if i == j: continue
	    d = a[i][j] / a[j][j]
	    for l in xrange(j, k+1):
		a[i][l] -= a[j][l] * d
    ret = 0
    for i in xrange(0, k):
	ret += (a[i][k] / a[i][i]) * (k+1)**i
    return ret

ans = sum(map(solve, xrange(1, 11)))
print ans
