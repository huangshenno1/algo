from math import log
    
f = open('p099_base_exp.txt', 'r')
lines = f.readlines()
f.close()

c = 1000000000
ans = (0, 0)
for idx, line in enumerate(lines):
    (a, b) = map(int, line.strip().split(','))
    d = log(c) / log(a)
    if b/d > ans[1]:
	ans = (idx+1, b/d)
print ans
