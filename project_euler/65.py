def gcd(a, b):
	if b == 0: return a
	return gcd(b, a%b)
def lcm(a, b):
	return a / gcd(a, b) * b

class Fraction():
	def __init__(self, a, b=1):
		self.a = a
		self.b = b
	def show(self):
		print '%d/%d' % (self.a, self.b)
	def add(self, x):
		bb = lcm(self.b, x.b)
		aa = bb / self.b * self.a + bb / x.b * x.a
		dd = gcd(aa, bb)
		return Fraction(aa/dd, bb/dd)
	def inverse(self):
		return Fraction(self.b, self.a)

def find(n):
	if n == 1: return 2
	if n % 3 == 0: return n/3*2
	return 1

def solve(n):
	ret = Fraction(find(n))
	while n > 1:
		n -= 1
		ret = ret.inverse().add(Fraction(find(n)))
	return ret

def digitsum(n):
	s = 0
	while n > 0:
		s += n%10
		n /= 10
	return s

ans = solve(100)
ans.show()
print digitsum(ans.a)
