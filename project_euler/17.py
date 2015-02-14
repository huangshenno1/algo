num = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
ten = ['zero', 'ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

def spell(n):
	if n == 1000:
		return 'one thousand'
	s = ''
	if n >= 100:
		s += num[n/100] + ' hundred'
		n = n % 100
		if n > 0:
			s += ' and ' + spell(n)
	else:
		if n < 20:
			s += num[n]
		else:
			s += ten[n/10]
			n = n % 10
			if n > 0:
				s += '-' + num[n]
	return s

def length(n):
	return len(spell(n).replace(' ', '').replace('-', ''))

ans = 0
for i in range(1, 1001):
	ans += length(i)
print ans
