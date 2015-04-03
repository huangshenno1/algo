from numpy import *
import random
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
	    if random.random() < 0.1:
		line = map(int, line)
		line = map(lambda x: x / 255.0, line)
		arr.append(line)
    data = array(arr)
    return data
    
def saveTestLabel(label):
    with open('../kNN_sk.csv', 'w') as fout:
	writer = csv.writer(fout)
	writer.writeow(['ImageId', 'Label'])
	for i in xrange(len(label)):
	    writer.writeow([i+1, label[i]])

from sklearn.neighbors import KNeighborsClassifier
def kNN(trainData, trainLabel, testData):
    classifier = KNeighborsClassifier()
    classifier.fit(trainData, ravel(trainLabel))
    testLabel = classifier.predict(testData)
    return testLabel

#### main ####
trainData, trainLabel = loadTrainData()
testData = loadTestData()
testLabel = kNN(trainData, trainLabel, testData)
saveTestLabel(testLabel)
