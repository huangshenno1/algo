import math

# AdaBoost classifier (multi-class one-label)
class AdaBoost:
    # initialize
    # weakclf: class of the weak classifier
    # m: number of weak classifiers
    def __init__(self, weakclf, m):
	self.m = m
	self.weakclf = weakclf
	self.clf = []
	self.alpha = []
	self.k = 0

    # lambda function
    def _lambda(self, a):
	ret = [0] * self.k
	for i in xrange(self.k):
	    ret[i] = a % 2
	    a /= 2
	return ret

    # Hamming distance between a and b
    def _hamming_distance(self, a, b):
	dis = 0
	for i in xrange(self.k):
	    if a[i] != b[i]:
		dis += 1
	return dis

    def _arg_min(self, h):
	ret = ('', self.k+1)
	for label in self.dic:
	    dis = self._hamming_distance(self.dic[label], h)
	    if dis < ret[1]:
		ret = (label, dis)
	return ret[0]

    # train
    def fit(self, X, y):
	self.k = int(math.ceil(math.log(len(set(y))) / math.log(2)))
	self.labels = list(set(y))
	self.dic = {}
	for i, label in enumerate(self.labels): 
	    self.dic[label] = self._lambda(i)

	for k in xrange(self.k):
	    self.clf.append([self.weakclf() for i in xrange(self.m)])
	    self.alpha.append([0] * self.m)
	    yy = [self.dic[y_i][k] for y_i in y]
	    self._fit(X, yy, k)

    # train on sublabel
    def _fit(self, X, y, k):
	n = len(y)
	w = [1.0 / n] * n # initialize weight distribution
	for i, clf in enumerate(self.clf[k]):
	    clf.fit(X, y, w) # train classifier_i
	    pred_y = clf.predict(X)
	    e = self._error_rate(pred_y, y, w) # calculate the error rate
	    if e == 0: 
		self.alpha[k][i] = 1e9
		return # end
	    self.alpha[k][i] = 0.5 * (math.log(1 - e) - math.log(e)) # calculate alpha for classifier_i
	    for j in xrange(n):
		if y[j] == pred_y[j]: t = 1
		else: t = -1
		if self.alpha < 0: t = -t
		w[j] = w[j] * math.exp(-self.alpha[k][i] * t) # update w
	    Z = sum(w)
	    for j in xrange(n): w[j] /= Z # normalize
	    
    # predict using m weakclassifiers
    def predict(self, X, m = 0):
	n = len(X)
	h = [[] for i in xrange(n)]
	for k in xrange(self.k):
	    h_k = self._predict(X, k, m)
	    for i in xrange(n):
		h[i].append(h_k[i])
	for i in xrange(n):
	    yield self._arg_min(h[i])

    # predict sublabel
    def _predict(self, X, k, m = 0):
	if m == 0: m = self.m
	n = len(X)
	s = [0] * n
	for i, clf in enumerate(self.clf[k][:m]):
	    if self.alpha[k][i] != 0:
		pred_y = clf.predict(X)
		for j, y in enumerate(pred_y):
		    if y == 1: s[j] += self.alpha[k][i]
		    else: s[j] -= self.alpha[k][i]
	s = [x > 0 and 1 or 0 for x in s]
	return s

    # calculate the error rate
    def _error_rate(self, pred_y, y, w):
	e = 0
	for i in xrange(len(y)):
	    if y[i] != pred_y[i]:
		e += w[i]
	return e
    
    # test errors on increasing number of weakclassifiers
    def test_errors(self, X, y):
	errors = []
	for i in xrange(1, self.m+1):
	    pred_y = self.predict(X, i)
	    error = 1.0 * sum([1 for a, b in zip(y, pred_y) if a != b]) / len(y)
	    errors.append(error)
	return errors

