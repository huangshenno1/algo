isPalindrome = lambda n: str(n) == str(n)[::-1]

next = lambda n: n + int(str(n)[::-1])

def isLychrel(n):
	for i in xrange(1, 50):
		n = next(n)
		if isPalindrome(n):
			return False
	return True

ans = filter(isLychrel, xrange(1, 10000))
print ans
print len(ans)
