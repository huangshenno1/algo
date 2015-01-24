n = 600851475143
i = 3
while i * i <= n:
	if n % i == 0:
		print i
		while n % i == 0:
			n = n / i
	i += 2
print n
