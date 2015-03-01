a1 = lambda k: (-(-1)**k, k*(3*k-1)/2)
a2 = lambda k: (-(-1)**k, k*(3*k+1)/2)

maxn = 1000000
p = [1] + [0] * maxn
for n in xrange(1, maxn+1):
	i = 1
	while True:
		(f, k) = a1(i)
		if k <= n: p[n] += f*p[n-k]
		else: break
		(f, k) = a2(i)
		if k <= n: p[n] += f*p[n-k]
		else: break
		i += 1
	if p[n] % 1000000 == 0:
		print n
		break
