def isKFactors(n, k):
	cnt = 0
	nn = int(n**0.5) + 1
	for i in range(2, nn):
		if n % i == 0:
			cnt += 1
			if cnt > k: return False
			while n % i == 0:
				n /= i
	if n > 1: cnt += 1
	return cnt == k

def check(x, k):
	for i in range(0, k):
		if not isKFactors(x+i, k):
			return False
	return True

for i in range(210, 1000000):
	if check(i, 4):
		print i
		break
