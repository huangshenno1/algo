# load iris data
def load_iris_data():
    X = []
    y = []
    with open('../data/iris.data') as fin:
	lines = fin.readlines()
	for line in lines:
	    line = line.strip()
	    if not line: continue
	    attrs = line.split(',')
	    X.append(map(float, attrs[:-1]))
	    y.append(attrs[-1])
    return X, y

# load heart disease data
def load_heart_disease_data():
    X = []
    y = []
    with open('../data/heart_disease.data') as fin:
	lines = fin.readlines()
	for line in lines:
	    line = line.strip()
	    if not line: continue
	    attrs = line.split(',')
	    X.append(map(lambda x: 0.0 if x == '?' else float(x), attrs[:-1]))
	    y.append(attrs[-1])
    return X, y

# load wine data
def load_wine_data():
    X = []
    y = []
    with open('../data/wine.data') as fin:
	lines = fin.readlines()
	for line in lines:
	    line = line.strip()
	    if not line: continue
	    attrs = line.split(',')
	    X.append(map(float, attrs[1:]))
	    y.append(attrs[0])
    return X, y

def purity(y, y_pred):
    p = 0
    n = len(y)
    K = len(set(y_pred))
    for k in xrange(K):
	c = {}
	for a, b in zip(y_pred, y):
	    if a == k: c[b] = c.get(b, 0) + 1
	p += max(c.values())
    return 1.0 * p / n
