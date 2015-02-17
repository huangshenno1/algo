def isprime(n):
	nn = int(n**0.5)+1
	for i in xrange(3, nn, 2):
		if n % i == 0: return False
	return True

length = 3
x = 9
primes = 3
tot = 5

while primes * 10 >= tot:
	for i in range(0, 4):
		x = x + length + 1
		if isprime(x): primes += 1
	length += 2
	tot += 4
print length
