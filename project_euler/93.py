from __future__ import division
from itertools import permutations

def operate(x, y):
    ret = []
    for a in x:
	for b in y:
	    ret += [a+b, a*b, a-b, b-a]
	    if b != 0: ret.append(a/b)
	    if a != 0: ret.append(b/a)
    return list(set(ret))

def isInt(x):
    return x == int(x)

def generate(x):
    gen = []
    perm = list(permutations(x, 4))
    for p in perm:
	gen += operate(operate([p[0]], [p[1]]), operate([p[2]], [p[3]]))
	gen += operate(operate(operate([p[0]], [p[1]]), [p[2]]), [p[3]])
    return map(int, filter(isInt, set(gen)))

def func(x):
    gen = generate(x)
    n = 0
    while n+1 in gen: n += 1
    return n

ans = ('', 0)
for a in xrange(1, 10):
    for b in xrange(a+1, 10):
	for c in xrange(b+1, 10):
	    for d in xrange(c+1, 10):
		n = func([a,b,c,d])
		if n > ans[1]:
		    ans = (''.join(map(str, [a,b,c,d])), n)
print ans
