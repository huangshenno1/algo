def abundant(n):
	if n == 1: return False
	ret = 1
	nn = int((n-1)**0.5)+1
	for i in range(2, nn):
		if n % i == 0:
			ret += i + n/i
	if nn**2 == n:
		ret += nn
	return ret > n

maxn = 28124
can = [False] * maxn
ab = []
for i in range(1, maxn):
	if abundant(i):
		ab.append(i)
		for j in range(0, len(ab)):
			if i+ab[j] >= maxn:
				break
			can[i+ab[j]] = True
ans = 0
for i in range(1, maxn):
	if not can[i]:
		ans += i
print ans
