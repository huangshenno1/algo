from utils import *
from adaboost import *
from weakclassifier import *
from sklearn import cross_validation
import matplotlib.pyplot as plt

def main():
    X, y = load_data()
    X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.3)
    
    # train and predict
    abc = AdaBoost(WeakClassifier, 100)
    abc.fit(X_train, y_train)    
    pred_y = list(abc.predict(X_test))
    
    # final error rate
    error_rate = 1.0 * sum([1 for a, b in zip(y_test, pred_y) if a != b]) / len(y_test)
    print 'Error rate: %f' % error_rate

    # analysis
    test_errors = abc.test_errors(X_test, y_test)
    
    # plot
    plt.plot(range(1, len(test_errors)+1), test_errors)
    plt.xlabel('Number of weak classifiers')
    plt.ylabel('Test error')

    plt.show()

if __name__ == '__main__':
    main()
