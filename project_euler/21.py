def d(n):
	ret = 1
	nn = int((n-1)**0.5)+1
	for i in range(2, nn):
		if n % i == 0:
			ret += i + n/i
	if nn**2 == n:
		ret += nn
	return ret

D = [0] * 10000
ans = 0
for i in range(2, 10000):
	D[i] = d(i)
	if D[i] < i and D[D[i]] == i:
		print i, D[i]
		ans += i + D[i]
print ans
