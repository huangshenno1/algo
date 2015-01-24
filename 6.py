a = 0
for i in range(1, 101):
	a = a + i
a = a**2

b = 0
for i in range(1, 101):
	b = b + i**2

print a - b
