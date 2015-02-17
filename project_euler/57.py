from fractions import Fraction

ex = [Fraction(0, 1)] * 1001

def expansion(n):
	if ex[n] > 0: return ex[n]
	if n == 0: ex[n] = Fraction(1, 1)
	else: ex[n] = 1 + 1 / (1 + expansion(n-1))
	return ex[n]

def valid(n):
    f = expansion(n)
    return len(str(f.numerator)) > len(str(f.denominator))

print len(filter(valid, range(1, 1001)))
