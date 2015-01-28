ans = 1
x = 1
d = 2
while d < 1001:
	for i in range(0, 4):
		x += d
		ans += x
	d += 2
print ans
