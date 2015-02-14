def is3(t):
	n = int((2*t)**0.5)
	return n*(n+1)/2 == t

def is5(p):
	n = int((p/1.5)**0.5)+1
	return n*(3*n-1)/2 == p

def gen6(n):
	return n*(2*n-1)

for i in range(144, 1000000):
	h = gen6(i)
	if is3(h) and is5(h):
		print h
		break
