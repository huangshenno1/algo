for c in range(2, 1000):
	for b in range(1, c):
		if b + c >= 1000:
			break
		a = 1000 - c - b
		if a > b:
			continue
		if a*a + b*b == c*c:
			print a, b, c
			print a*b*c
