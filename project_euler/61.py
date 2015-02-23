def f(k, n):
	if k == 3: return n*(n+1)/2
	if k == 4: return n*n
	if k == 5: return n*(3*n-1)/2
	if k == 6: return n*(2*n-1)
	if k == 7: return n*(5*n-3)/2
	if k == 8: return n*(3*n-2)

vis = [False] * 10000

def dfs(k=0, last=0, state=0, n=0, first=0, ans=[]):
	if n == 6:
		if last == first: 
			print ans
			print sum(ans)
		return
	state |= 1<<k
	for x in p[k]:
		if vis[x]: continue
		fx = x / 100
		lx = x % 100
		if n == 0:
			vis[x] = True
			for nk in xrange(0, 6):
				if (state >> nk) & 1 == 0:
					dfs(nk, lx, state, n+1, fx, ans+[x])
			vis[x] = False
		elif fx == last:
			vis[x] = True
			if n == 5: dfs(0, lx, state, n+1, first, ans+[x])
			else:
				for nk in xrange(0, 6):
					if (state >> nk) & 1 == 0:
						dfs(nk, lx, state, n+1, first, ans+[x])
			vis[x] = False

p = []
for i in xrange(0, 6):
	p.append([])
	j = 1
	while True:
		x = f(i+3, j)
		if x >= 10000: break
		if x >= 1000: p[i].append(x)
		j += 1
dfs()
