digitSum = lambda x: sum([int(i) for i in str(x)])
x = [i**j for i in xrange(1, 100) for j in xrange(1, 100)]
print max(map(digitSum, x))
