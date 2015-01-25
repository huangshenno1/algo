maxn = 1000000
l = [0] * maxn

def collatz_length(n):
	if n < maxn and l[n] > 0:
		return l[n]
	ret = 0
	t = n
	while t > 1:
		if t % 2 == 0:
			t = t / 2
		else:
			t = t * 3 + 1
		ret += 1
		if t < maxn:
			ret += collatz_length(t)
			break
	l[n] = ret
	return ret

l[1] = 1
for i in range(2, maxn):
	collatz_length(i)
ans = 0
maxlen = 0
for i in range(1, maxn):
	if l[i] > maxlen:
		ans = i
		maxlen = l[i]
print ans, maxlen
