a = [1, 2, 5, 10, 20, 50, 100, 200]

def solve(s, k):
	if k == 0: return 1
	ret = 0
	while s >= 0:
		ret += solve(s, k-1)
		s -= a[k]
	return ret

print solve(200, 7)
