maxn = 1000000
l = [0] * (maxn+1)

def next(x):
    s = 1
    for i in xrange(2, int(x**0.5)):
	if x%i == 0: s += i + x/i
    if int(x**0.5)**2 == x: s += int(x**0.5)
    return s

def func(s):
    if l[s] != 0: return
    print s
    save = []
    length = 0
    x = s
    while True:
	save.append(x)
	length += 1
	x = next(x)
	if x == s: break
	if x > maxn or x in save: return
    x = s
    while True:
	l[x] = length
	x = next(x)
	if x == s: break
    
ans = (0, 0)
for i in xrange(1, maxn):
    func(i)
    if l[i] > ans[1]:
	ans = (i, l[i])
print ans
