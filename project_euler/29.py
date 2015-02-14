maxn = 101
ans = 0
vis = [False] * maxn
for x in range(2, maxn):
	if vis[x]: continue
	s = set()
	y = x
	i = 1
	while y < maxn:
		for j in range(2, maxn):
			s.add(i*j)
		vis[y] = True
		y *= x
		i += 1
	l = len(s)
	ans += l
	print x, l
print ans
