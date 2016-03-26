import numpy as np
import csv

def load_data(is_train = True):
    if is_train:
	print 'Loading data...'
        data = np.empty((42000, 1, 28, 28), dtype='float32')
	label = np.empty((42000, ), dtype='uint8')
        with open('../train.csv', 'r') as fin:
	    lines = list(csv.reader(fin))
	    for i, line in enumerate(lines[1:]):
		numbers = map(int, line)
		arr = np.array(numbers[1:], dtype='float32')
		arr = arr.reshape(28, 28)
		data[i,:,:,:] = arr
		label[i] = numbers[0]
	print 'Data loaded.'
	return data, label
    
    else:
	print 'Loading data...'
        data = np.empty((28000, 1, 28, 28), dtype='float32')
        with open('../test.csv', 'r') as fin:
	    lines = list(csv.reader(fin))
	    for i, line in enumerate(lines[1:]):
		numbers = map(int, line)
		arr = np.array(numbers, dtype='float32')
		arr = arr.reshape(28, 28)
		data[i,:,:,:] = arr
	print 'Data loaded.'
	return data
