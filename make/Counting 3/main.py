# 3**38 > 10**18
pow3 = []
for i in range(0, 40):
	pow3.append(3**i)
dp = {}

def dfs(n, k=37):
	if (n, k) in dp: return dp[(n, k)]
	if n == 0: return 1
	ret = 0
	for i in xrange(k, -1, -1):
		if n >= pow3[i+2]/2: break
		if n >= pow3[i]: ret += dfs(n-pow3[i], i-1)
		if n >= pow3[i]*2: ret += dfs(n-pow3[i]*2, i-1)
		if n >= pow3[i]*3: ret += dfs(n-pow3[i]*3, i-1)
	dp[(n, k)] = ret
	return ret

T = input()
for t in xrange(0, T):
    n = input()
    print dfs(n)
