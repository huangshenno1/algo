maxn = 100
c = []
for i in xrange(0, maxn+1):
	cc = [0] * (i+1)
	cc[0] = cc[i] = 1
	c.append(cc)

ans = 0
for i in xrange(2, maxn+1):
	for j in xrange(1, i):
		c[i][j] = c[i-1][j-1] + c[i-1][j]
		if c[i][j] > 1000000:
			c[i][j] = 1000000
			ans += 1
print ans
