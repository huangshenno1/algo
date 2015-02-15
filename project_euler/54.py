def value(c):
	if c == 'A': return 13
	if c == 'K': return 12
	if c == 'Q': return 11
	if c == 'J': return 10
	if c == 'T': return 9
	return ord(c) - ord('1')

def pre(cards):
	count = [0] * 14
	same = [0] * 5
	flush = 'y'
	for c in cards:
		count[value(c[0])] += 1
		if flush == 'y' or flush == c[1]: flush = c[1]
		else: flush = 'n'
	for i in range(1, 14):
		same[count[i]] += 1
	if flush != 'n': flush = 'y'
	return count, same, flush

def isStraight(count):
	for i in range(1, 10):
		if count[i] == 1:
			for j in range(1, 5):
				if count[i+j] != 1: return False
			return True
	return False

def find(count, n):
	ret = []
	for i in range(13, 0, -1):
		if count[i] == n:
			ret.append(i)
	return ret

def rank(cards):
	(count, same, flush) = pre(cards)
	high = find(count, 4) + find(count, 3) + find(count, 2) + find(count, 1)
	if isStraight(count):
		if flush == 'y': return 9, high
		else: return 5, high
	else:
		if same[4] == 1: return 8, high
		if same[3] == 1 and same[2] == 1: return 7, high
		if flush == 'y': return 6, high
		if same[3] == 1: return 4, high
		if same[2] == 2: return 3, high
		if same[2] == 1: return 2, high
		return 1, high

def win(c1, c2):
	(r1, h1) = rank(c1)
	(r2, h2) = rank(c2)
	if r1 != r2: return r1 > r2
	for i in range(0, len(h1)):
		if h1[i] != h2[i]: return h1[i] > h2[i]
	
input_file = open('p054_poker.txt', 'r')
lines = input_file.readlines()
input_file.close()

ans = 0
for line in lines:
	cards = line.strip().split(' ')
	c1 = cards[0:5]
	c2 = cards[5:10]
	if win(c1, c2):
		ans += 1
print ans
