def decrypt(codes, key):
	text = ''
	k = 0
	for c in codes:
		text += chr(c ^ key[k])
		k = (k+1) % 3
	return text

f = open('p059_cipher.txt', 'r')
line = f.readline()
f.close()

codes = [int(c) for c in line.strip().split(',')]
ans_key = ''
ans_text = ''
ans_the_count = 0

for a in xrange(97, 123):
	for b in xrange(97, 123):
		for c in xrange(97, 123):
			key = [a, b, c]
			text = decrypt(codes, key)
			the_count = text.count('the')
			if the_count > ans_the_count:
				ans_text = text
				ans_key = ''.join([chr(d) for d in key])
				ans_the_count = the_count
print ans_key
print ans_text
ans = 0
for c in ans_text:
	ans += ord(c)
print ans
