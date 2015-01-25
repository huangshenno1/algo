def score(name):
	s = 0
	for c in name:
		s += ord(c) - ord('A') + 1
	return s
	
f = open('p022_names.txt', 'r')
line = f.readline()
f.close()

names = []
for s in line.split(','):
	names.append(s.strip('"'))
names = sorted(names)

ans = 0
for i in range(0, len(names)):
	ans += (i+1) * score(names[i])
print ans
