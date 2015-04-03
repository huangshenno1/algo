from __future__ import division
from multiprocessing import Process
from Queue import PriorityQueue
import random

def loadDataSet(filename):
    dataSet = []
    dataLabel = []
    lines = open(filename).readlines()[1:]
    for line in lines:
	arr = map(int, line.strip().split(','))
	dataLabel.append(arr[0])
	dataSet.append(arr[1:])
    return dataSet, dataLabel    

def selectTrainingSet(dataSet, dataLabel):
    trainingSet = []
    trainingLabel = []
    for i in xrange(len(dataSet)):
	if random.random() < 0.5:
	    trainingSet.append(dataSet[i])
	    trainingLabel.append(dataLabel[i])
    return trainingSet, trainingLabel

def loadTestSet(filename):
    testSet = []
    lines = open(filename).readlines()[1:]
    for line in lines:
	arr = map(int, line.strip().split(','))
	testSet.append(arr)
    return testSet    

def distance(u, v, p):
    dis = 0
    for i in xrange(len(u)):
	dis += abs(u[i] - v[i])**p
    return dis**(1/p)

def kNN(test, data, labels, k):
    queue = PriorityQueue()
    for i in xrange(len(data)):
	queue.put((-distance(test, data[i], 2), i))
	if queue.qsize() > k: queue.get()
    indices = []
    for i in xrange(k):
	indices.append(queue.get()[1])
    class_count = {}
    for i in indices:
	label = labels[i]
	class_count[label] = class_count.get(label, 0) + 1
    max_count = 0
    for label in class_count:
	if class_count[label] > max_count:
	    max_count = class_count[label]
	    max_label = label
    return max_label

def solve(a, b):
    print 'Loading data...'
    dataSet, dataLabel = loadDataSet('../train.csv')
    print 'Selecting training data...'
    trainingSet, trainingLabel = selectTrainingSet(dataSet, dataLabel)
    print 'Training data size: %d' % len(trainingSet)
    print 'Loading test data...'
    testSet = loadTestSet('../test.csv')[a:b]
    print 'Predicting...'
    fout = open('predictions_kNN_%d.csv' % a, 'w')
    fout.write('ImageId,Label\n')
    count = a
    for test in testSet:
	count += 1
	print count
	label = kNN(test, trainingSet, trainingLabel, 5)
	fout.write("%d,%d\n" % (count, label))
    fout.close()
    print 'Done.'

#### main ####
if __name__ == '__main__':
    plist = []
    pcnt = 7
    n = 28000
    step = n // pcnt
    for i in xrange(pcnt):
	p = Process(target=solve, args=(i*step, (i+1)*step))
	p.start()
	plist.append(p)
    for i in xrange(pcnt):
	p.join()
    print 'All done'
