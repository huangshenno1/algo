def isTriangle(word):
	n = 0
	for c in word:
		n += ord(c) - ord('A') + 1
	m = int((2*n)**0.5)
	return m*m+m == 2*n
	
f = open('p042_words.txt', 'r')
line = f.readline()
f.close()

ans = 0
words = line.split(',')
for word in words:
	word = word.strip('"')
	if isTriangle(word): 
		ans += 1
print ans
