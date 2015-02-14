maxn = 10000
isprime = [False] * 2 + [True] * maxn
for i in range(2, maxn):
	if isprime[i]:
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i

def encode(x):
	ret = 0
	while x > 0:
		ret += (x % 10)**3
		x = x / 10
	return ret

for a in range(1000, 10000):
	if isprime[a]:
		code = encode(a)
		for inc in range(1, 4500):
			b = a + inc
			c = a + inc * 2
			if c >= 10000:
				break
			if isprime[b] and isprime[c]:
				if encode(b) == code and encode(c) == code:
					print a, b, c

