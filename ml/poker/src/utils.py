# encoding: utf-8

def load_data(filename, pre = False):
    print 'Loading data from %s ...' % filename
    X = []
    y = []
    with open(filename, 'r') as fin:
	lines = fin.readlines()
	for line in lines:
	    arr = map(int, line.strip().split(','))
	    X.append(arr[:-1])
	    y.append(arr[-1])
    print 'Data loaded.'
    if pre:
	X = preprocess(X)
    return X, y

def evaluate(y_pred, y):
    N = len(y)
    T = 0
    for a, b in zip(y_pred, y):
	if a == b: T += 1
    return 1.0 * T / N

def preprocess(raw):
    X = []
    for attr in raw:
	x = [1] + [0] * 13 + [1] # (0)同花 (1-13)各张数
	# 同花
	color = attr[0]
	for i in xrange(2, 10, 2):
	    if attr[i] != color:
		x[0] = 0
		break
	# 张数
	for i in xrange(1, 10, 2):
	    x[attr[i]] += 1
	X.append(x)
    return X
