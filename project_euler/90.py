import itertools

def fix(s):
	if s>>6 & 1: s |= 1<<9
	if s>>9 & 1: s |= 1<<6
	return s

def gen(s):
	for x in xrange(0, 10):
		if s>>x & 1:
			yield x

def check(s):
	a, b = set(gen(s[0])), set(gen(s[1]))
	for sq in squares:
		x, y = sq/10, sq%10
		if (x in a and y in b) or (x in b and y in a): continue
		return False
	return True

squares = [1, 4, 9, 16, 25, 36, 49, 64, 81]
states = map(fix, [x for x in xrange(0, 1<<10) if sum(map(int, bin(x)[2:])) == 6])
ans = sum(map(check, itertools.product(states, states)))
print ans/2
