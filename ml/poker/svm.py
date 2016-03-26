from utils import *
from sklearn import svm
import time

X_train, y_train = load_data('data/poker-hand-training-true.data', True)
t1 = time.time()
clf = svm.SVC()
clf.fit(X_train, y_train)
t2 = time.time()
print 'Training: %f s used.' % (t2-t1)

X_test, y_test = load_data('data/poker-hand-testing.data', True)
t1 = time.time()
y_pred = clf.predict(X_test)
t2 = time.time()
print 'Testing: %f s used.' % (t2-t1)
print 'Calculating accuracy...'
acc = evaluate(y_pred, y_test)
print 'Accuracy:', acc
