import sys
from collections import deque
    
f = open('p083_matrix.txt', 'r')
lines = f.readlines()
f.close()

a = []
for line in lines:
    b = map(int, line.split(','))
    a.append(b)
n = len(a)

dp = []
for i in xrange(0, n):
    dp.append([sys.maxint] * n)

def valid(i, j):
    return i >= 0 and j >= 0 and i < n and j < n

di = [0, 0, 1, -1]
dj = [1, -1, 0, 0]
queue = deque()
def bfs(dp):
    global queue
    queue = deque([(0, 0)])
    dp[0][0] = a[0][0]
    while len(queue) > 0:
	(i, j) = queue.popleft()
	f(i, j, dp)

def f(i, j, dp):
    global queue
    for r in xrange(0, 4):
	(ni, nj) = (i+di[r], j+dj[r])
	if not valid(ni, nj): continue
	if dp[ni][nj] > dp[i][j] + a[ni][nj]:
	    dp[ni][nj] = dp[i][j] + a[ni][nj]
	    queue.append((ni, nj))	    
	
bfs(dp)
ans = dp[n-1][n-1]
print ans
