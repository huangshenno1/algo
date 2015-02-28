fac = [1] * 10
for i in xrange(1, 10):
	fac[i] = fac[i-1] * i

next = lambda n: sum([fac[int(x)] for x in str(n)])

def chainLength(n):
	num = set()
	while n not in num:
		num.add(n)
		n = next(n)
	return len(num)

def find(n, l=60):
	return chainLength(n) == l

print len(filter(find, xrange(1, 1000001)))
