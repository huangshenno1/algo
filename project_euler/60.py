maxn = 10000
isprime = [False]*2 + [True]*maxn
primes = []

def isPrime(n):
	if n < maxn: return isprime[n]
	if n % 2 == 0: return False
	nn = int(n**0.5)+1
	for i in xrange(3, nn, 2):
		if n % i == 0: return False
	return True

for i in xrange(2, maxn):
	if isprime[i]:
		primes.append(i)
		j = i*i
		while j < maxn:
			isprime[j] = False
			j += i

edge = [[]] * maxn
for i in xrange(0, len(primes)):
	u = primes[i]
	edge[u] = []
	for v in primes[i+1:]:
		w1 = int(str(u) + str(v))
		w2 = int(str(v) + str(u))
		if isPrime(w1) and isPrime(w2):
			edge[u].append(v)

def find(s):
	if len(s) >= 5:
		print s
		print sum(s)
		return True
	for v in edge[s[-1]]:
		flag = True
		for u in s:
			if not v in edge[u]:
				flag = False
				break
		if flag: 
			if find(s + [v]): return True
	return False

print '-'*50
for u in primes:
	if len(edge[u]) >= 4:
		if find([u]):
			break
