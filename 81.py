f = open('p081_matrix.txt', 'r')
lines = f.readlines()
f.close()

n = 80
a = []
for line in lines:
	b = []
	for s in line.split(','):
		b.append(int(s))
	a.append(b)

dp = a
for i in range(0, n):
	for j in range(0, n):
		if i > 0 and j > 0: dp[i][j] += min(dp[i-1][j], dp[i][j-1])
		elif i > 0:	dp[i][j] += dp[i-1][j]
		elif j > 0:	dp[i][j] += dp[i][j-1]

print dp[n-1][n-1]
