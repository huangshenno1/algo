from utils import *
from baseline import *

def ikmeans(X, k):
    c = []
    n_c = []
    
#   pick data center c0
    c0 = mean(X)

#   pick an entity most distance from c0 as a new centroid
    _X = X[:]
    while len(_X) > 0:
	cc = max([(l2dis(u, v), u) for u, v in zip(_X, [c0]*len(_X))])[1]
	c.append(cc)
	X_new = []
	n_cc = 0
	for x in _X:
	    y = closest_centroid(x, [c0, cc])
	    if y == 0: X_new.append(x)
	    else: n_cc += 1
	n_c.append(n_cc)
	_X = X_new
    
#   reserve k centroids with largest clusters
    c = c[1:] # remove c0
    c = [c[i] for nc, i in sorted(zip(n_c, xrange(len(c))), reverse = True)[:k]]
    return kmeans(X, k, c)

if __name__ == '__main__':
    X, y = load_iris_data()
    y_pred, t = ikmeans(X, 3)
    p = purity(y, y_pred)
    print 'Iris Purity: %.2f' % p
    print 'Iteration times: %d' % t

    X, y = load_heart_disease_data()
    y_pred, t = ikmeans(X, 4)
    p = purity(y, y_pred)
    print 'Heart Disease Purity: %.2f' % p
    print 'Iteration times: %d' % t

    X, y = load_wine_data()
    y_pred,t  = ikmeans(X, 3)
    p = purity(y, y_pred)
    print 'Wine Purity: %.2f' % p
    print 'Iteration times: %d' % t
