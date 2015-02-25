f = open('p067_triangle.txt')
sss = f.read().rstrip()
f.close()

a = []
lines = sss.split('\n')
for line in lines:
	b = []
	nums = line.strip().split(' ')
	for num in nums:
		b.append(int(num))
	a.append(b)

n = len(lines)
print n
dp = []
dp.append([a[0][0]])
for i in range(1, n):
	line = []
	for j in range(0, i+1):
		t = 0
		if j > 0:
			t = max(t, dp[i-1][j-1])
		if j < i:
			t = max(t, dp[i-1][j])
		t += a[i][j]
		line.append(t)
	dp.append(line)
ans = 0
for i in range(0, n):
	ans = max(ans, dp[n-1][i])
print ans
