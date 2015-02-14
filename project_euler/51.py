def gen(sp, l, pattern, x):
	s = ''
	for i in xrange(0, l):
		if (pattern >> i) & 1 == 1: s += chr(x+ord('0'))
		else: s += sp[i]
	return int(s)

def func(p):
	ret = 0
	sp = str(p)
	l = len(sp)
	for pattern in xrange(1, 1<<(l-1)):
		cnt = 0
		for x in xrange(0, 10):
			if pattern & 1 == 1 and x == 0: continue
			s = gen(sp, l, pattern, x)
			if isprime[s]: cnt += 1

		if cnt == 8:
			print bin(pattern)
			for x in xrange(0, 10):
				if pattern & 1 == 1 and x == 0: continue
				s = gen(sp, l, pattern, x)
				print s

		ret = max(ret, cnt)
	return ret

maxn = 1000000
primes = []
isprime = [False] * 2 + [True] * maxn

for i in xrange(2, maxn):
	if isprime[i]:
		primes.append(i)
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i

for p in primes:
	if func(p) == 8:
		break
