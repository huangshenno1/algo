maxn = 1000000

def check(x, k):
	y = x*k
	if len(str(x)) != len(str(y)): return False
	d = [0]*10
	for i in xrange(0, len(str(x))):
		d[int(str(x)[i])] += 1
		d[int(str(y)[i])] -= 1
	for i in xrange(0, 10):
		if d[i] != 0: return False
	return True

for x in xrange(1, maxn):
	flag = True
	for i in xrange(2, 7):
		if not check(x, i):
			flag = False
			break
	if flag:
		print x
		break
