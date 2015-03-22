import random

T1 = 100000
T2 = 10000
T3 = 10000

f = open('input.txt', 'w')
f.write(str(T1+T2+T3)+'\n')
for t in xrange(0, T1):
    f.write(str(random.randint(1, 10**6))+'\n')
for t in xrange(0, T2):
    f.write(str(random.randint(10**6, 10**12))+'\n')
for t in xrange(0, T3):
    f.write(str(random.randint(10**12, 10**18))+'\n')
f.close()
