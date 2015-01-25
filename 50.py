maxn = 1000000
isprime = [False] * 2 + [True] * maxn
prime = []
for i in range(2, maxn):
	if isprime[i]:
		prime.append(i)
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i

ans = 0
maxlen = 0
for i in range(0, len(prime)):
	s = 0
	l = 0
	j = i
	while j < len(prime) and s+prime[j] < maxn:
		s += prime[j]
		l += 1
		j += 1
		if isprime[s]:
			if maxlen < l:
				ans = s
				maxlen = l
print ans
