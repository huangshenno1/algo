f = lambda n: n*(n+1)/2
n = 2000000
ans = (0, n)
i = 1
while f(i)**2 <= n*2:
	j = i
	s = f(i)*f(j)
	while s <= n*2:
		if ans[1] > abs(s-n):
			ans = (i*j, abs(s-n))
		j += 1
		s = f(i)*f(j)
	i += 1
print ans
