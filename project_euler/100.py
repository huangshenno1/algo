import sys

def check(n):
	tmp = n*(n-1)/2
	x = int(tmp**0.5)
	return x*(x+1) == tmp

def next(n, rate):
	m = int(n*rate)
	while not check(m):
		m += 1
	return m, float(m)/n

n = 4
rate = 5.0
for i in xrange(0, 100):
	(n, rate) = next(n, rate)
	print n
	if n > int(1e12): 
		print '-'*50
		print int((n*(n-1)/2)**0.5)+1
		break
