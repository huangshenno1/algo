from sklearn.tree import DecisionTreeClassifier

# weak classifier
# decision tree (max depth = 2) using scikit-learn
class WeakClassifier:
    # initialize
    def __init__(self):
	self.clf = DecisionTreeClassifier(max_depth = 2)

    # train on dataset (X, y) with distribution weight w
    def fit(self, X, y, w):
	self.clf.fit(X, y, sample_weight = w)

    # predict
    def predict(self, X):
	return self.clf.predict(X)
