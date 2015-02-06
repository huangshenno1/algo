def euler(n):
	ret = n
	for i in range(2, int(n**0.5)+1):
		if i > n: break
		if n % i == 0:
			ret = ret * (i-1) / i
			while n % i == 0:
				n /= i
	if n > 1: ret = ret * (n-1) / n
	return ret

def R(n):
	return euler(n) / (n-1.0)

prime = [2, 3, 5, 7, 11, 13, 17, 19, 23]
ans = 1
for i in prime:
	ans *= i
rate = 15499.0 / 94744.0
for i in range(1, 29):
	if R(i*ans) < rate:
		print i*ans
		print R(i*ans), rate
		break
