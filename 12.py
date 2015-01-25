def triangle_number(n):
	return n * (n+1) / 2

def count_divisors(n):
	ret = 0
	nn = int((n-1)**0.5) + 1
	for i in range(1, nn):
		if n % i == 0:
			ret += 2
	if nn**2 == n:
		ret += 1
	return ret

i = 1
while True:
	ans = triangle_number(i)
	if count_divisors(ans) > 500:
		print ans
		break
	i += 1
