def valid(s):
	if len(s) != 9: return False
	vis = [False] * 10
	for c in s:
		if c == '0': return False
		if vis[int(c)]: return False
		vis[int(c)] = True
	return True

for x in range(1, 10000):
	for n in range(2, 10):
		s = ""
		for i in range(1, n+1):
			s += str(x*i)
		if valid(s):
			print s, x, n
