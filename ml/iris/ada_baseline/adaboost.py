import math

# AdaBoost classifier (multi-class one-label)
class AdaBoost:
    # initialize
    # weakclf: class of the weak classifier
    # m: number of weak classifiers
    def __init__(self, weakclf, m):
	self.m = m
	self.clf = []
	for i in xrange(m):
	    self.clf.append(weakclf())
	self.alpha = [0] * m
	self.e = []

    # train
    def fit(self, X, y):
	n = len(y)
	w = [1.0 / n] * n # initialize weight distribution
	for i, clf in enumerate(self.clf):
	    clf.fit(X, y, w) # train classifier_i
	    pred_y = clf.predict(X)
	    e = self._error_rate(pred_y, y, w) # calculate the error rate
	    self.e.append(e)
	    if e == 0: 
		self.alpha = 1e9
		return # end
	    # if e > 0.5: return # fail
	    self.alpha[i] = 0.5 * (math.log(1 - e) - math.log(e)) # calculate alpha for classifier_i
	    for j in xrange(n):
		if y[j] == pred_y[j]: t = 1
		else: t = -1
		if self.alpha[i] < 0: t = -t
		w[j] = w[j] * math.exp(-self.alpha[i] * t) # update w
	    Z = sum(w)
	    for j in xrange(n): w[j] /= Z # normalize
	    
    # predict using m weakclassifiers
    def predict(self, X, m = 0):
	if m == 0: m = self.m
	n = len(X)
	vote_y = []
	for i in xrange(n): vote_y.append({})
	for i, clf in enumerate(self.clf[:m]):
	    if self.alpha[i] > 0:
		pred_y = clf.predict(X)
		for j, y in enumerate(pred_y):
		    vote_y[j][y] = vote_y[j].get(y, 0) + self.alpha[i] # sum up alpha for each label
	pred_y = []
	for i in xrange(n):
	    y = max(vote_y[i].items(), key = lambda x: x[1])[0] # pick the y with max vote
	    pred_y.append(y)
	return pred_y

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

    # weight of each weakclassifier
    def classifier_weights(self):
	return self.alpha
