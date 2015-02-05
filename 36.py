def isP10(n):
	s = str(n)
	for i in range(0, len(s)):
		if s[i] != s[-(i+1)]:
			return False
	return True

def isP2(n):
	s = bin(n)
	for i in range(2, len(s)):
		if s[i] != s[-(i-1)]:
			return False
	return True

ans = 0
for i in range(1, 1000000):
	if isP10(i) and isP2(i):
		ans += i
		print i
print ans
