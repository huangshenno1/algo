from __future__ import division

def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)

ans = (0, 1)

for d in xrange(2, 1000001):
	if d % 10000 == 0: print d
	n = int(d*3/7-0.000000001)
	while n > 0:
		if gcd(d, n) == 1:
			if 3/7-n/d < ans[1]:
				ans = (n, 3/7-n/d)
			break
		n -= 1
print ans
