from load_data import load_data
from keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation, Flatten
from keras.layers.advanced_activations import PReLU
from keras.layers.convolutional import Convolution2D, MaxPooling2D
from keras.optimizers import SGD, Adadelta, Adagrad
from keras.utils import np_utils, generic_utils

# loading data
data, label = load_data()
print data.shape[0], 'samples'
label = np_utils.to_categorical(label, 10)

# model
model = Sequential()

# 1
model.add(Convolution2D(6, 5, 5, border_mode='valid', input_shape=(1, 28, 28)))
model.add(Activation('sigmoid'))

# 2
model.add(MaxPooling2D(pool_size=(2, 2)))

# 3
model.add(Convolution2D(16, 5, 5, border_mode='valid'))
model.add(Activation('sigmoid'))

# 4
model.add(MaxPooling2D(pool_size=(2, 2)))

# 5
model.add(Flatten())
model.add(Dense(120, init='normal'))
model.add(Activation('sigmoid'))

# 6
model.add(Dense(84, init='normal'))
model.add(Activation('sigmoid'))

# 7
model.add(Dense(10, init='normal'))
model.add(Activation('softmax'))

# method
sgd = SGD(l2=0.0, lr=0.05, decay=1e-6, momentum=0.9, nesterov=True)
model.compile(loss='categorical_crossentropy', optimizer=sgd, class_mode='categorical')

# train
model.fit(data, label, batch_size=100, nb_epoch=100, shuffle=True, verbose=1, show_accuracy=True, validation_split=0.2)

test_data = load_data(False)
test_labels = model.predict_classes(test_data)
print test_labels
with open('ans.csv', 'w') as fout:
    fout.write('ImageId,Label\n')
    for id, label in enumerate(test_labels, 1):
	fout.write('%d,%s\n' % (id, str(label)))
