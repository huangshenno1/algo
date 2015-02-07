maxn = 1000000
isprime = [False] * 2 + [True] * maxn
for i in range(2, maxn):
	if isprime[i]:
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i

def truncatable(n):
	x = n
	while x > 0:
		if not isprime[x]: return False
		x /= 10
	b = 10
	x = n % b
	while x < n:
		if not isprime[x]: return False
		b *= 10
		x = n % b
	return True
	
ans = 0
for i in range(10, maxn):
	if truncatable(i):
		ans += i
		print i
print ans
