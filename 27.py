def isprime(n):
	if n < 2: 
		return False
	nn = int(n**0.5) + 1
	for i in range(2, nn):
		if n % i == 0:
			return False
	return True

def func(n, a, b):
	return n*n + a*n + b

def solve(a, b):
	n = 0
	while True:
		f = func(n, a, b)
		if not isprime(f):
			return n
		n += 1

ans = 0
maxn = 0
for a in range(-999, 1000):
	for b in range(-999, 1000):
		n = solve(a, b)
		if n > maxn:
			ans = a * b
			maxn = n
print ans, maxn
