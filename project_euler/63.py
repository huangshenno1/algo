def cmp(x, n):
	l = len(str(x**n))
	if l == n: return 0
	return l > n and 1 or -1

ans = 0
for x in xrange(1, 10):
	n = 1
	while cmp(x, n) == 0:
		print x**n, n
		ans += 1
		n += 1
	x += 1
print ans
