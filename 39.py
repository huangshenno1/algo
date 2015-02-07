count_p = [0] * 1001
for a in range(3, 334):
	for b in range(a, 501):
		for c in range(b, 501):
			p = a + b + c
			if p <= 1000 and a*a + b*b == c*c:
				count_p[p] += 1

ans = 0
for i in range(0, 1001):
	if count_p[i] > count_p[ans]:
		ans = i
print ans, count_p[ans]
