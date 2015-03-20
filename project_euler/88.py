maxn = 12000
mps = [int(1e9)] * (maxn+1)

def divide(n, s, x, r, k):
    if s == 1:
	if k+r <= maxn:
	    mps[k+r] = min(mps[k+r], n)
	return
    for i in xrange(x, s+1):
	if s % i == 0:
	    divide(n, s/i, i, r-i, k+1)

def func(n):
    divide(n, n, 2, n, 0)

for i in xrange(2, 2*maxn+1):
    func(i)
ans = sum(set(mps[2:maxn+1]))
print ans
