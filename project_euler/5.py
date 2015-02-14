def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def lcm(a, b):
	return a / gcd(a, b) * b

s = 1
for i in range(1, 21):
	s = lcm(s, i)
print s
