def pow_mod(x, n, mod):
	ret = 1
	while n > 0:
		if n % 2 == 1:
			ret = ret * x % mod
		x = x * x % mod
		n = n / 2
	return ret

ans = 0
mod = 10000000000
for i in range(1, 1001):
	ans += pow_mod(i, i, mod)
ans = ans % mod
print ans
