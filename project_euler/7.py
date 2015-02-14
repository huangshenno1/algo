maxn = 200000

isprime = [True] * maxn
prime = []
tot = 0
i = 2
while i < maxn:
	if isprime[i] == True:
		prime.append(i)
		tot += 1
		j = i * i
		while j < maxn:
			isprime[j] = False
			j += i
	i += 1

print tot
print prime[10000]
