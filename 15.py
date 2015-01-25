# C(40, 20)

ans = 1
for i in range(21, 41):
	ans *= i
for i in range(1, 21):
	ans /= i
print ans
