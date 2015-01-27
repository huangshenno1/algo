def cycle(n):
	d = {}
	s = 1
	i = 0
	d[s] = i
	while True:
		s = s * 10 % n
		i += 1
		if s == 0:
			return 0
		if d.has_key(s):
			return i - d[s]
		d[s] = i

ans = 0
maxlen = 0
for i in range(1, 1000):
	l = cycle(i)
	if l > maxlen:
		ans = i
		maxlen = l
print ans, maxlen
