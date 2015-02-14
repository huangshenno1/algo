from itertools import permutations

def isprime(n):
	if n % 2 == 0: return False
	m = int(n**0.5) + 1
	for i in range(3, m, 2):
		if n % i == 0:
			return False
	return True

def solve(n):
	s = '987654321'
	s = s[-n:]
	for l in permutations(s, n):
		x = int("".join(l))
		if isprime(x):
			return x
	return 0

ans = 0
for i in range(8, 0, -1):
	ans = solve(i)
	if ans > 0:
		print ans
		break
