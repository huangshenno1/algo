def next(x, y, z):
	den = x - y*y
	num = y*z
	a = (num + z*int(x**0.5)) / den
	while True:
		b = a*den - num
		if b*b < z*z*x and b > 0 and b % z == 0:
			return b/z, den/z
		a -= 1

def period(x):
	y = int(x**0.5)
	z = 1
	yz = []
	while True:
		(y, z) = next(x, y, z)
		if (y, z) in yz: return len(yz)
		yz.append((y, z))

ans = 0
for i in xrange(1, 10001):
	if int(i**0.5)**2 != i:
		if period(i) % 2 == 1:
			ans += 1
print ans
