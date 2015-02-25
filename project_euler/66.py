hh = []
kk = []
cf = []

issqrt = lambda x: int(x**0.5)**2 == x

def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)

def geta(D, n):
	if n == 0:
		a = int(D**0.5)
		cf.append((a, 1))
	else:
		(m0, p0) = cf[n-1]
		d1 = D - m0**2
		n1 = p0*D**0.5 + p0*m0
		a = 1
		while (a+1)*d1 < n1: a += 1
		# c = gcd(gcd(p0, a*d1-p0*m0), d1)
		cf.append(((a*d1)/p0-m0, d1/p0))
	return a

def gethk(D, n):
	a = geta(D, n)
	if n == 0:
		(h, k) = (a, 1)
	elif n == 1:
		(h, k) = (a*hh[n-1]+1, a)
	else:
		h = a*hh[n-1] + hh[n-2]
		k = a*kk[n-1] + kk[n-2]
	d = gcd(h, k)
	(h, k) = (h/d, k/d)
	hh.append(h)
	kk.append(k)
	return h, k

def findx(D):
	global hh, kk, cf
	hh = []
	kk = []
	cf = []
	i = 0
	while True:
		(h, k) = gethk(D, i)
		if h**2 - D*k**2 == 1: return h
		i += 1

ans = (0, 0)
for D in xrange(2, 1001):
	if not issqrt(D):
		x = findx(D)
		print D, x
		if x > ans[1]:
			ans = (D, x)
print ans
