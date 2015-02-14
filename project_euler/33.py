def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)

def check(a, b, c, d):
	x = a*10+b
	y = c*10+d
	if x * d == y * a and b == c: return True
	return False

num = 1
den = 1
for x in range(10, 100):
	for y in range(x+1, 100):
		if check(x/10, x%10, y/10, y%10):
			print x, y
			num *= x
			den *= y
d = gcd(num, den)
print "%d/%d"% (num, den)
print "%d/%d"% (num/d, den/d)
