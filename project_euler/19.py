days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

ans = 1
s = -1 + 365
for i in range(1, 101):
	for j in range(0, 12):
		s += days[j]
		if i % 4 == 0 and j == 1:
			s += 1
		if s % 7 == 0:
			ans += 1
if s % 7 == 0:
	ans -= 1
print ans
