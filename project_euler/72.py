maxn = 1000000
isprime = [False] * 2 + [True] * maxn
count = [x for x in xrange(0, maxn+1)]

ans = 0
for i in xrange(2, maxn+1):
	if isprime[i]:
		count[i] -= 1
		j = i*2
		while j <= maxn:
			isprime[j] = False
			count[j] = count[j] * (i-1) / i
			j += i
	ans += count[i]
print ans
