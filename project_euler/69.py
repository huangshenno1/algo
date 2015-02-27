# print 2*3*5*7*11*13*17

maxn = 1000001
phi = [x for x in xrange(0, maxn)]
isprime = [False, False] + [True] * maxn
for i in xrange(2, maxn):
	if isprime[i]:
		phi[i] = phi[i] * (i-1) / i
		j = i*2
		while j < maxn:
			phi[j] = phi[j] * (i-1) / i
			isprime[j] = False
			j += i

def ratio(n):
	return n, float(n) / phi[n]

print max(map(ratio, xrange(2, maxn)), key=lambda x:x[1])
