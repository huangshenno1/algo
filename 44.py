maxn = 5000
p = [0]
for i in range(1, maxn+1):
	p.append(i*(3*i-1)/2)

def find(x):
	if x < 1 or x > p[maxn-1]: return False
	low = 0
	high = maxn-1
	while low <= high:
		mid = (low + high) / 2
		if p[mid] == x: return True
		if p[mid] > x: high = mid - 1
		else: low = mid + 1
	return False

flag = False
for i in range(1, maxn):
	print "#%d\t%d" % (i, p[i])
	d = p[i]
	for j in range(1, maxn):
		a = p[j]
		if find(a+d) and find(a+a+d):
			print d
			flag = True
			break
	if flag: break
