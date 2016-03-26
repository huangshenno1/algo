from utils import *
from sklearn.ensemble import AdaBoostClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn import cross_validation

def main():
    X, y = load_data()
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3)

    abc = AdaBoostClassifier(DecisionTreeClassifier(max_depth = 2), n_estimators = 100)
    abc.fit(X_train, y_train)
    pred_y = abc.predict(X_test)

    error_rate = 1.0 * sum([1 for a, b in zip(y_test, pred_y) if a != b]) / len(y_test)
    print 'Error rate: %f' % error_rate

if __name__ == '__main__':
    main()
