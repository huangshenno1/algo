f = open('p098_words.txt', 'r')
line = f.readline()
f.close()
words = [word.strip('"') for word in line.split(',')]

def hash(word):
    sorted_word = sorted(word)
    code = 0
    for c in sorted_word:
	code = code * 27 + ord(c) - ord('A') + 1
    return code

def issqr(x):
    if not x: return False
    return int(x**0.5)**2 == x

def getmap(word, num):
    num = str(num)
    dic = {}
    dic2 = {}
    for i in xrange(0, len(word)):
	if word[i] in dic:
	    if dic[word[i]] != num[i]: return False
	if num[i] in dic2:
	    if dic2[num[i]] != word[i]: return False
	dic[word[i]] = num[i]
	dic2[num[i]] = word[i]
    return dic

def mapdic(word, dic):
    ret = ''
    for c in word:
	ret += dic[c]
    if ret[0] == '0': return 0
    return int(ret)

s = {}
for word in words:
    code = hash(word)
    if code in s:
	s[code].append(word)
    else:
	s[code] = [word]
s = filter(lambda x: len(x[1]) > 1, s.items())
s = [x[1] for x in s]
ans = 0
for p in s:
    w1 = p[0]
    w2 = p[1]
    n = len(w1)
    for d in [i*i for i in xrange(1, 40000)]:
	if len(str(d)) > n: break
	if len(str(d)) < n: continue
	dic = getmap(w1, d)
	if dic:
	    d2 = mapdic(w2, dic)
	    if issqr(d2):
		print w1, d
		print w2, d2
		ans = max(ans, d, d2)
print ans
