from __future__ import division

def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)

ans = 0

for d in xrange(5, 12001):
	n = int(d/2-0.000000001)
	while n/d > 1/3:
		if gcd(d, n) == 1:
			ans += 1
		n -= 1
print ans
