def digits(x):
	ret = 0
	while x > 0:
		d = x % 10
		x /= 10
		if d == 0 or (ret>>d) & 1 == 1: return 0
		ret |= 1<<d
	return ret

def pandigital(c):
	visc = digits(c)
	if visc == 0: return False
	a = 2
	while a*a < c:
		if c % a == 0:
			b = c / a
			visa = digits(a)
			visb = digits(b)
			if visa | visb | visc == (1<<10)-2:
				return True
		a += 1
	return False

ans = 0
for x in range(1000, 10000):
	if pandigital(x):
		ans += x
		print x
print ans
