maxn = 10000
ans = 0
for c in xrange(1, maxn):
	print c, ans
	for b in xrange(1, c+1):
		for a in xrange(1, b+1):
			if (lambda x: int(x**0.5)**2 == x)((a+b)**2+c**2):
				ans += 1
				if ans > 1000000: 
					print c
					exit()
