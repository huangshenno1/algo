maxn = 1000
isprime = [False] * 2 + [True] * maxn
primes = []
for i in xrange(2, maxn):
	if isprime[i]:
		primes.append(i)
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i

dp = [1] + [0] * maxn
for x in primes:
	for v in xrange(maxn-1, -1, -1):
		if dp[v] > 0:
			i = 1
			while v + x*i < maxn:
				dp[v+x*i] += dp[v]
				i += 1
for i in xrange(0, maxn):
	if dp[i] > 5000:
		print i
		break
