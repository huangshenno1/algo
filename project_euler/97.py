def pow_mod(x, y, mod=10000000000):
	ret = 1
	while y > 0:
		if y & 1: ret = ret * x % mod
		x = x * x % mod
		y >>= 1
	return ret

print (28433 * pow_mod(2, 7830457) + 1) % 10000000000
