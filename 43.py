from itertools import permutations

def valid(s):
	p = [2, 3, 5, 7, 11, 13, 17]
	for i in range(0, 7):
		x = int(s[i+1:i+4])
		if x % p[i] != 0: 
			return False
	return True

ans = 0
s = '0123456789'
for p in permutations(s, 10):
 	d = "".join(p)
	if valid(d):
		ans += int(d)
		print d
print ans
	
