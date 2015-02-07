maxn = 1000000
d = "."
x = 1
while len(d) <= maxn:
	d += str(x)
	x += 1

ans = 1
for i in [1, 10, 100, 1000, 10000, 100000, 1000000]:
	ans *= int(d[i])
print ans
