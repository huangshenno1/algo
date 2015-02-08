import time

maxn = 350
fac = []

def time_std(t):
	s = t % 60
	t /= 60
	m = t % 60
	h = t / 60
	return (h, m, s)

def print_time_used():
	global start_time
	end_time = time.time()
	time_used = end_time - start_time
	print 'time used: %d h %d m %d s' % time_std(time_used)

def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)

def lcm(a, b):
	return a * b / gcd(a, b)

def A(a, b):
	return fac[a] / fac[a-b]

def count(n, a, i):
	return A(n, a*i) / a**i / fac[i]

def init():
	global fac
	fac.append(1)
	for i in range(1, maxn+1):
		fac.append(fac[i-1] * i)

def g(n):
	dp = []
	for i in range(0, n+1):
		dp.append({})
	dp[0][1] = 1
	for a in range(n, 1, -1):
		print a,
		print_time_used()
		for v in range(n-a, -1, -1):
			for r in dp[v]:
				i = 1
				while v + a*i <= n:
					rr = lcm(r, a)
					if rr not in dp[v+a*i]: dp[v+a*i][rr] = 0
					dp[v+a*i][rr] += dp[v][r] * count(n-v, a, i)
					i += 1
	ret = 0
	for i in range(0, n+1):
		for r in dp[i]:
			ret += r**2 * dp[i][r]
	return float(ret) / fac[n]


init()
start_time = time.time()
print "%e" % g(3)
print "%e" % g(5)
print "%e" % g(20)
print '\n===START==='
ans = g(350)
print '===END==='
print_time_used()
print "%.9e" % ans
