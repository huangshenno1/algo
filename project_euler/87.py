maxn = 50000000
isprime = [False]*2 + [True]*maxn
primes = []
for i in xrange(2, maxn):
	if isprime[i]:
		primes.append(i)
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i

squares = [x**2 for x in primes if x**2 < maxn]
cubes = [x**3 for x in primes if x**3 < maxn]
fourth_powers = [x**4 for x in primes if x**4 < maxn]
can = [False] * maxn
for a in squares:
	for b in cubes:
		if a+b >= maxn: break
		for c in fourth_powers:
			if a+b+c >= maxn: break
			can[a+b+c] = True
print sum(can)
