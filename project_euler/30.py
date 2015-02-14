def check(n):
	s = 0
	x = n
	while x > 0:
		s += (x%10)**5
		x /= 10
	return s == n

maxn = 6 * 9**5 + 1
ans = 0
for i in range(2, maxn):
	if check(i):
		ans += i
		print i
print ans
