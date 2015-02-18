# 10^25 > 2^83
pow2 = []
for i in range(0, 90):
	pow2.append(2**i)

dp = {}

def dfs(n, k=85):
	if (n, k) in dp: return dp[(n, k)]
	if n == 0: return 1
	ret = 0
	for i in xrange(k, -1, -1):
		if n >= pow2[i+2]: break
		if n >= pow2[i]: ret += dfs(n-pow2[i], i-1)
		if n >= pow2[i+1]: ret += dfs(n-pow2[i+1], i-1)
	dp[(n, k)] = ret
	return ret

print dfs(10**25)
