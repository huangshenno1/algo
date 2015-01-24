def is_palindrome(a):
	digit = []
	while a > 0:
		d = a % 10
		a = a / 10
		digit.append(d)
	for i in range(0, len(digit)):
		if digit[i] != digit[-(i+1)]:
			return False
	return True

s = 0
for a in range(100, 1000):
	for b in range(a, 1000):
		if is_palindrome(a * b):
			if s < a * b:
				s = a * b
print s
