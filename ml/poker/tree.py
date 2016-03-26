from utils import *
from sklearn import tree
import time

pre = True

X_train, y_train = load_data('data/poker-hand-training-true.data', pre)
t1 = time.time()
clf = tree.DecisionTreeClassifier()
clf.fit(X_train, y_train)
t2 = time.time()
print 'Training: %f s used.' % (t2-t1)

X_test, y_test = load_data('data/poker-hand-testing.data', pre)
t1 = time.time()
y_pred = clf.predict(X_test)
t2 = time.time()
print 'Testing: %f s used.' % (t2-t1)
print 'Calculating accuracy...'
acc = evaluate(y_pred, y_test)
print 'Accuracy:', acc

'''
from sklearn.externals.six import StringIO
with open('tree.dot', 'w') as f:
    f = tree.export_graphviz(clf, out_file=f)
'''
