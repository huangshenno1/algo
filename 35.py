maxn = 1000000
isprime = [True] * maxn

def prime_table():
	isprime[0] = isprime[1] = False
	for i in range(2, maxn):
		if isprime[i]:
			j = i*i
			while j < maxn:
				isprime[j] = False
				j += i

def length(n):
	return len(str(n))

def next(n, l):
	return (n%10) * 10**(l-1) + n/10

def circular(n):
	l = length(n)
	if not isprime[n]: return False
	for i in range(1, l):
		n = next(n, l)
		if not isprime[n]: return False
	return True

prime_table()
ans = 0
for i in range(2, maxn):
	if circular(i): ans += 1
print ans
