def judge(x1, y1, x2, y2): 
	a = x1**2 + y1**2
	b = x2**2 + y2**2
	c = (x1-x2)**2 + (y1-y2)**2
	if a==0 or b==0 or c==0: return False
	return a+b==c or a+c==b or b+c==a

ans = 0
for x1 in xrange(0, 51):
	for y1 in xrange(0, 51):
		for x2 in xrange(0, 51):
			for y2 in xrange(0, 51):
				if judge(x1, y1, x2, y2): ans += 1
print ans / 2
