maxn = 10000001
phi = [x for x in xrange(0, maxn)]
isprime = [False, False] + [True] * maxn
ans = []

def isPermutation(a, b):
	(a, b) = (str(a), str(b))
	if len(a) != len(b): return False
	return sorted(a) == sorted(b)

def ratio(n):
	return n, float(n) / phi[n]

for i in xrange(2, maxn):
	if isprime[i]:
		phi[i] = phi[i] * (i-1) / i
		j = i*2
		while j < maxn:
			phi[j] = phi[j] * (i-1) / i
			isprime[j] = False
			j += i
	if isPermutation(i, phi[i]):
		print i, phi[i]
		ans.append(ratio(i))

print min(ans, key=lambda x:x[1])


