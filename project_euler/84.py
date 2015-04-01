import random

s = ['GO', 'A', 'CC', 'A', 'T', 'R', 'B', 'CH', 'B', 'B', \
    'JAIL', 'C', 'U', 'C', 'C', 'R', 'D', 'CC', 'D', 'D', \
    'FP', 'E', 'CH', 'E', 'E', 'R', 'F', 'F', 'U', 'F', \
    'G2J', 'G', 'G', 'CC', 'G', 'R', 'CH', 'H', 'T', 'H']

CC = range(1, 17)
CH = range(1, 17)
cci = 0
chi = 0

def shuffle(cards):
    for i in xrange(0, 16):
	j = random.randint(0, 15)
	cards[i], cards[j] = cards[j], cards[i]
    return cards

def roll(dice = 4):
    return random.randint(1, dice)

def findNext(x, c):
    while True:
	x = (x+1) % 40
	if s[x] == c: return x

def goCC(x):
    global cci
    r = CC[cci]
    cci = (cci+1) % 16
    if r == 1: return 0
    if r == 2: return 10
    return x

def goCH(x):
    global chi
    r = CH[chi]
    chi = (chi+1) % 16
    if r == 1: return 0
    if r == 2: return 10
    if r == 3: return 11
    if r == 4: return 24
    if r == 5: return 39
    if r == 6: return 5
    if r == 7 or r == 8: return findNext(x, 'R')
    if r == 9: return findNext(x, 'U')
    if r == 10: 
	x = (x+37) % 40
    return x

def go2Jail(double):
    if double == 3: 
	double = 0
	return True
    return False

def go(x, double):
    d1 = roll()
    d2 = roll()
    if d1 == d2: double += 1
    else: double = 0
    if go2Jail(double): x = 10
    else:
	d = d1 + d2
	x = (x+d) % 40
	if s[x] == 'G2J': x = 10
	elif s[x] == 'CC': x = goCC(x)
	elif s[x] == 'CH': x = goCH(x)
    return x, double

def play(rolls):
    ans = [0] * 40
    x = 0
    double = 0
    global CC, CH, cci, chi
    CC = shuffle(CC)
    CH = shuffle(CH)
    cci, chi = 0, 0
    for i in xrange(rolls):
	(x, double) = go(x, double)
	ans[x] += 1
    for i in xrange(0, 40):
	ans[i] = 1.0*ans[i]/rolls
    return ans

ans0 = play(10000000)
ans = []
for i in xrange(0, 40):
    ans.append((ans0[i], i, s[i]))
print sorted(ans, reverse=True)
