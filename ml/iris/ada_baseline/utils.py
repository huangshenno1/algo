# load iris data
def load_data():
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

