import numpy as np
import tensorflow as tf
from utils import *

def weight_variable(shape):
    init = tf.truncated_normal(shape, stddev = 0.1)
    return tf.Variable(init)
    
def bias_variable(shape):
    init = tf.constant(0.1, shape = shape)
    return tf.Variable(init)

def conv2d(x, W):
    return tf.nn.conv2d(x, W, strides = [1, 1, 1, 1], padding = 'SAME')

def max_pool_2x2(x):
    return tf.nn.max_pool(x, ksize = [1, 2, 2, 1], strides = [1, 2, 2, 1], padding = 'SAME')

x = tf.placeholder('float', shape = [None, 784])
y = tf.placeholder('float', shape = [None, 10])

x_image = tf.reshape(x, [-1, 28, 28, 1])

W_conv1 = weight_variable([5, 5, 1, 32])
b_conv1 = bias_variable([32])
h_conv1 = tf.nn.relu(conv2d(x_image, W_conv1) + b_conv1)
h_pool1 = max_pool_2x2(h_conv1)

W_conv2 = weight_variable([5, 5, 32, 64])
b_conv2 = bias_variable([64])
h_conv2 = tf.nn.relu(conv2d(h_pool1, W_conv2) + b_conv2)
h_pool2 = max_pool_2x2(h_conv2)
h_pool2_flat = tf.reshape(h_pool2, [-1, 7*7*64])

W_fc1 = weight_variable([7*7*64, 1024])
b_fc1 = bias_variable([1024])
h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, W_fc1) + b_fc1)

keep_prob = tf.placeholder('float')
h_fc1_drop = tf.nn.dropout(h_fc1, keep_prob)

W_fc2 = weight_variable([1024, 128])
b_fc2 = bias_variable([128])
h_fc2 = tf.nn.relu(tf.matmul(h_fc1_drop, W_fc2) + b_fc2)

W_fc3 = weight_variable([128, 10])
b_fc3 = bias_variable([10])
y_pred = tf.nn.softmax(tf.matmul(h_fc2, W_fc3) + b_fc3)
out = tf.argmax(y_pred, 1)

cross_entropy = -tf.reduce_sum(y * tf.log(tf.clip_by_value(y_pred, 1e-10, 1.0)))
train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)
correct_prediction = tf.equal(tf.argmax(y_pred, 1), tf.argmax(y, 1))
accuarcy = tf.reduce_mean(tf.cast(correct_prediction, 'float'))

# go
x_train, y_train = load_data()
x_test = load_data(False)

with tf.Session() as sess:
    print 'Training...'
    sess.run(tf.initialize_all_variables())
    index = 0
    epoch = 1
    print '='*20 + '  epoch: %d  ' %epoch + '='*20
    for i in xrange(20000):
	x_batch, y_batch = x_train[index:index+50, :], y_train[index:index+50, :]
	sess.run(train_step, feed_dict = {x: x_batch, y: y_batch, keep_prob: 0.5})
	if i % 100 == 0:
	    train_accuracy = accuarcy.eval(feed_dict = {x: x_batch, y: y_batch, keep_prob: 1.0})
	    print 'step %d, training accuarcy %.2f' % (i, train_accuracy)
	index += 50
	if index >= 42000:
	    index = 0
	    epoch += 1
	    print '='*20 + '  epoch: %d  ' %epoch + '='*20
	    perm = np.arange(42000)
	    np.random.shuffle(perm)
	    x_train, y_train = x_train[perm], y_train[perm]
    
    print 'Testing...'
    y_test = sess.run(out, feed_dict = {x: x_test, keep_prob: 1.0})
    print 'Outputing...'
    output(y_test)
