import re
	
f = open('p089_roman.txt', 'r')
lines = f.readlines()
f.close()

ans = 0
pattern = 'VIIII|LXXXX|DCCCC|IIII|XXXX|CCCC'
for s in lines:
	s = s.strip()
	ans += len(s) - len(re.sub(pattern, '--', s))
	print s, re.sub(pattern, '--', s)
print ans
