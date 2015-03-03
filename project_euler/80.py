from decimal import *
getcontext().prec = 200
digit_sum = lambda d: sum([int(x) for x in str(d)[:101] if x!='.'])
print sum(map(digit_sum, [Decimal(x).sqrt() for x in xrange(0, 100) if (lambda x: int(x**0.5)**2 != x)(x)]))
