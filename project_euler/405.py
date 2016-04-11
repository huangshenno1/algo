import numpy as np

s = np.asarray([1, 0, 0, 0, 0, 0], dtype=np.int)

a = np.asarray([[4, 1, 4, 0, 0, 0],
		[0, 1, 0, 0, 2, 2],
		[0, 0, 1, 1, 0, 0],
		[0, 0, 2, 0, 0, 1],
		[0, 1, 0, 0, 0, 0], 
		[0, 0, 0, 0, 0, 1]], dtype=np.int)

mmod = 8*17**6
mod = 17**7
def g(a, b, e, p):
    n = 1
    while p > 0:
	if p % 2 == 1:
	    n = n*e % mmod
	e = e*e % mmod
	p /= 2
    c = np.eye(6, dtype=np.int)
    while n > 0:
	if n%2 == 1:
	    c = np.dot(c, b)
	    for i in xrange(6):
		c[i] %= mod
	b = np.dot(b, b)
	for i in xrange(6):
	    b[i] %= mod
	n /= 2
    a = np.dot(a, c)
    for i in xrange(6):
	a[i] %= mod
    return a[-1]
    
ans = g(s, a, 10, 10**18)
print ans
