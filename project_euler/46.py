maxn = 10000
prime = []
isprime = [True] * maxn

def prime_table():
	for i in range(3, maxn, 2):
		if isprime[i]:
			prime.append(i)
			j = i*i
			while j < maxn:
				isprime[j] = False
				j += i
	
def issqr(x):
	a = int(x**0.5)
	return a**2 == x

prime_table()
for a in range(3, maxn, 2):
	if not isprime[a]:
		go = False
		for b in prime:
			if b < a:
				c = (a-b) / 2
				if issqr(c):
					go = True
					break
		if not go:
			print a
			break
