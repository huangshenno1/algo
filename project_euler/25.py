a = 1
b = 1
k = 2
while True:
	c = a + b
	k += 1
	s = str(c)
	if len(s) == 1000:
		print k
		print s
		break
	a = b
	b = c
