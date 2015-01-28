fac = [1] * 10
for i in range(1, 10):
	fac[i] = fac[i-1] * i

def curious(n):
	s = n
	while n > 0:
		s -= fac[n%10]
		n /= 10
	return s == 0

maxn = 7 * fac[9]
ans = 0
for i in range(10, maxn):
	if curious(i):
		print i
		ans += i
print ans
