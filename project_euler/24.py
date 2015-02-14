fac = [1]
for i in range(1, 11):
	fac.append(fac[i-1] * i)
used = [False] * 10

def kth(k):
	cnt = 0
	for i in range(0, 10):
		if not used[i]:
			cnt += 1
			if cnt == k:
				used[i] = True
				return i

n = 1000000 - 1
ans = ''
i = 9
while i > 0:
	k = n / fac[i] + 1
	ans += str(kth(k))
	n = n % fac[i]
	i -= 1
ans += str(kth(1))
print ans
