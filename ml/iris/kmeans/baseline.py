from utils import *
import random

def l2dis(u, v):
    return sum([(a-b)**2 for a, b in zip(u, v)])**0.5

def closest_centroid(x, c):
    return min([(l2dis(u, v), i) for i, (u, v) in enumerate(zip([x]*len(c), c))])[1]

def mean(X):
    n, d = len(X), len(X[0])
    return map(lambda i: sum(x[i] for x in X) / n, xrange(d))

def kmeans(X, k, c = None):
    n = len(X)
    y = [0] * n
    
#   init k centroids
    if c is None: c = random.sample(X, k)
    
    times = 0

    while times < 1e8:
	times += 1
	updated = False
#	find closest centroids
	for i, x in enumerate(X):
	    y_new = closest_centroid(x, c)
	    if y_new != y[i]: updated = True
	    y[i] = y_new

	if not updated: break

#	update each centroids
	for j in xrange(k):
	    _X = []
	    for i in xrange(n):
		if y[i] == j: _X.append(X[i])
	    c[j] = mean(_X)
	
    return y, times

if __name__ == '__main__':
    X, y = load_iris_data()
    p = t = 0
    for times in xrange(100):
	y_pred, ct = kmeans(X, 3)
	p += purity(y, y_pred)
	t += ct
    p /= 100.0
    t /= 100.0
    print 'Iris Purity: %.2f' % p
    print 'Iteration times: %.2f' % t

    X, y = load_heart_disease_data()
    p = t = 0
    for times in xrange(100):
	y_pred, ct = kmeans(X, 4)
	p += purity(y, y_pred)
	t += ct
    p /= 100.0
    t /= 100.0
    print 'Heart Disease Purity: %.2f' % p
    print 'Iteration times: %.2f' % t

    X, y = load_wine_data()
    p = t = 0
    for times in xrange(100):
	y_pred, ct = kmeans(X, 3)
	p += purity(y, y_pred)
	t += ct
    p /= 100.0
    t /= 100.0
    print 'Wine Purity: %.2f' % p
    print 'Iteration times: %.2f' % t
