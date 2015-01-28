maxn = 1000
can = [-1] * maxn
can[1] = 0
can[89] = 1

def next(n):
	ret = 0
	while n > 0:
		ret += (n%10)**2
		n /= 10
	return ret

def end89(n):
	if n < maxn and can[n] != -1: return can[n] == 1
	if n == 1: return 0
	if n == 89: return 1
	ret = end89(next(n))
	if n < maxn: can[n] = ret
	return ret

ans = 0
for i in range(1, 10000001):
	ans +=  end89(i)
	# show progress
	if i % 100000 == 0: print str(i/100000) + '%'
print ans
