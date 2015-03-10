# a = p*q
# b = (p^2-q^2)/2
# c = (p^2+q^2)/2
# a+b+c = p*q + p^2

def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)

maxn = 1500000
ways = [0]*(maxn+1)
for p in xrange(1, maxn+1, 2):
	if p**2 > maxn: break
	for q in xrange(1, p, 2):
		l = p*q+p**2
		if l > maxn: break
		if gcd(p, q) > 1: continue
		t = l
		while t <= maxn:
			ways[t] += 1
			t += l
print len(filter(lambda x: ways[x]==1, xrange(1, maxn+1)))
