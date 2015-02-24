def feature(n):
	return ''.join(sorted(str(n)))

def add(f, n):
	if f in dic: dic[f].append(n)
	else: dic[f] = [n]

dic = {}
for x in xrange(1, 10000):
	add(feature(x**3), x**3)

for key in dic:
	if len(dic[key]) >= 5:
		print dic[key]
