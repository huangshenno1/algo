def add(p, b, r, x):
	if (b, r) in p: p[(b, r)] += x
	else: p[(b, r)] = x

n = 15
dp = []
dp.append({(0,0): 1.0})
for rnd in xrange(1, n+1):
	p = {}
	for ((b, r), v) in dp[rnd-1].items():
		add(p, b+1, r, v/(rnd+1))
		add(p, b, r+1, v*rnd/(rnd+1))
	dp.append(p)

s = 0
for ((b, r), v) in dp[n].items():
	if b > r:
		s += v
ans = int(1/s)
print ans
