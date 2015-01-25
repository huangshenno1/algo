def fac(n):
	ret = 1
	for i in range(1, n+1):
		ret *= i
	return ret

num = fac(100)
digits = str(num)
ans = 0
for d in digits:
	ans += int(d)
print ans
