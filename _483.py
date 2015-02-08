# It takes more than 24 hours to solve...

import time

maxn = 350
fac = []
dp = {}

def time_std(t):
	s = t % 60
	t /= 60
	m = t % 60
	h = t / 60
	return (h, m, s)

def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)

def lcm(a, b):
	return a * b / gcd(a, b)

def A(a, b):
	return fac[a] / fac[a-b]

def init():
	global fac
	fac.append(1)
	for i in range(1, maxn+1):
		fac.append(fac[i-1] * i)

def f(n, ml, r, log=""):
	if (n, ml, r) in dp:
		return dp[(n, ml, r)]
	print "%d : %s" % (n, log)
	ret = r**2
	for i in range(2, ml+1):
		if n == 350: print i
		j = 1
		while i*j <= n:
			ret += A(n, i*j)/i**j/fac[j] * f(n-i*j, i-1, lcm(r, i), log + "%d*%d " % (i, j))
			j += 1
	dp[(n, ml, r)] = ret
	return ret

def g(n):
	return float(f(n, n, 1)) / fac[n]

init()
start_time = time.time()
print g(3)
print g(5)
print g(20)
print '\n===START==='
ans = g(50)
print '===END==='
end_time = time.time()
time_used = end_time - start_time
print 'time used: %d h %d m %d s\n' % time_std(time_used)
print "%e" % ans
