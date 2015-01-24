maxn = 2000000
isprime = [True] * maxn
sum = 0
for i in range(2, maxn):
	if isprime[i]:
		sum += i
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i
print sum
