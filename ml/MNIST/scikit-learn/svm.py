from numpy import *
import matplotlib.pyplot as plt
from sklearn.svm import SVC
from sklearn.learning_curve import *
from sklearn import cross_validation
import time
import csv

def loadTrainData():
    data = []
    label = []
    arr = []
    with open('../train.csv', 'r') as fin:
	lines = list(csv.reader(fin))
	for line in lines[1:]:
	    line = map(int, line)
	    line[1:] = map(lambda x: x / 255.0, line[1:])
	    arr.append(line)
    arr = array(arr)
    data = arr[:, 1:]
    label = arr[:, 0]
    return data, label
    
def loadTestData():
    data = []
    arr = []
    with open('../test.csv', 'r') as fin:
	lines = list(csv.reader(fin))
	for line in lines[1:]:
	    line = map(int, line)
	    line = map(lambda x: x / 255.0, line)
	    arr.append(line)
    data = array(arr)
    return data
    
def saveTestLabel(label):
    with open('SVM.csv', 'wb') as fout:
	writer = csv.writer(fout)
	writer.writerow(['ImageId', 'Label'])
	for i in xrange(len(label)):
	    writer.writerow([i+1, int(label[i])])

def SVM(trainData, trainLabel, testData):
    classifier = SVC(C=10, gamma=0.01)
    classifier.fit(trainData, ravel(trainLabel))
    testLabel = classifier.predict(testData)
    return testLabel

def plot(train_scores, test_scores, train_sizes):
    train_scores_mean = np.mean(train_scores, axis=1)
    train_scores_std = np.std(train_scores, axis=1)
    test_scores_mean = np.mean(test_scores, axis=1)
    test_scores_std = np.std(test_scores, axis=1)
    
    plt.xlabel("Training examples")
    plt.ylabel("Score")
    plt.ylim(0, 1.01)
    plt.fill_between(train_sizes, train_scores_mean - train_scores_std, train_scores_mean + train_scores_std, alpha=0.1, color="r")
    plt.fill_between(train_sizes, test_scores_mean - test_scores_std, test_scores_mean + test_scores_std, alpha=0.1, color="g")
    plt.plot(train_sizes, train_scores_mean, label="Training score", color="r")
    plt.plot(train_sizes, test_scores_mean, label="Cross-validation score", color="g")
    plt.legend(loc="best")
    plt.show()

#### main ####
trainData, trainLabel = loadTrainData()
cv = cross_validation.ShuffleSplit(len(trainData), n_iter=3, test_size=0.3, random_state=0)
train_sizes = np.linspace(0.1, 1.0, 10)
train_sizes, train_scores, test_scores = learning_curve(SVC(C=10, gamma=0.01), trainData, ravel(trainLabel), train_sizes=train_sizes, cv=cv, n_jobs=-1)
plot(train_scores, test_scores, train_sizes)

#testData = loadTestData()
#testLabel = SVM(trainData, trainLabel, testData)
#saveTestLabel(testLabel)
print "%ss used." % str(time.clock())
