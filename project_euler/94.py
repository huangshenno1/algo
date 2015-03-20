maxn = int(1e9)
ans = 0

def isSqr(x):
    return (int(x**0.5))**2 == x

def solve(a, b):
    p = a+a+b
    if p > maxn: return
    global ans
    if isSqr(a*a-b*b/4):
	ans += p

for b in xrange(4, maxn, 2):
    if b*3-2 > maxn: break
    solve(b-1, b)
    solve(b+1, b)

print ans
