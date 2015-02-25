def getMinUnused(used):
	ret = 0
	for x in xrange(1, 10):
		if not used[x]:
			return x

def check(a):
	global used, ans
	_used = used[:]
	if sum(a) % 5 != 0: return
	avg = (55 + sum(a)) / 5
	if avg - a[0] - a[1] != getMinUnused(_used): return
	ret = ''
	for i in xrange(0, 5):
		x = avg - a[i] - a[(i+1)%5]
		if x <= 0 or x > 10 or _used[x]: return
		_used[x] = True
		ret += str(x) + str(a[i]) + str(a[(i+1)%5])
	if len(ret) == 16:
		print ret
		iret = int(ret)
		if iret > ans:
			ans = iret

def dfs(k, a):
	if k == 5:
		check(a)
		return 
	for x in xrange(1, 11):
		if not used[x]:
			used[x] = True
			a[k] = x
			dfs(k+1, a)
			used[x] = False


used = [False] * 11
a = [0] * 5
ans = 0
dfs(0, a)
print ans
