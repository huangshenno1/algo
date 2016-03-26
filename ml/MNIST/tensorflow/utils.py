import numpy as np
import csv

def load_data(is_train = True):
    if is_train:
	print 'Loading training data...'
        data = np.empty((42000, 784), dtype='float32')
	label = np.empty((42000, 10), dtype='float32')
        with open('../train.csv', 'r') as fin:
	    lines = list(csv.reader(fin))
	    for i, line in enumerate(lines[1:]):
		numbers = map(int, line)
		arr = np.array(numbers[1:], dtype='float32')
		data[i, :] = arr
		label[i, numbers[0]] = 1.0
	data = np.multiply(data, 1.0/255.0)
	print 'Data loaded.'
	return data, label
    
    else:
	print 'Loading testing data...'
        data = np.empty((28000, 784), dtype='float32')
        with open('../test.csv', 'r') as fin:
	    lines = list(csv.reader(fin))
	    for i, line in enumerate(lines[1:]):
		numbers = map(int, line)
		arr = np.array(numbers, dtype='float32')
		data[i, :] = arr
	data = np.multiply(data, 1.0/255.0)
	print 'Data loaded.'
	return data

def output(y):
    with open('ans.csv', 'w') as fout:
	fout.write('ImageId,Label\n')
	for i, label in enumerate(y, 1):
	    fout.write('%d,%s\n' % (i, str(label)))
