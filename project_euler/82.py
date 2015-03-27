import sys
from collections import deque
    
f = open('p082_matrix.txt', 'r')
lines = f.readlines()
f.close()

a = []
for line in lines:
    b = map(int, line.split(','))
    a.append(b)
n = len(a)

dp = []
for i in xrange(0, n):
    dp.append([a[i][0]] + [sys.maxint] * (n-1))

def valid(i, j):
    return i >= 0 and j >= 0 and i < n and j < n

di = [0, 1, -1]
dj = [1, 0, 0]
queue = deque()
def bfs(dp):
    global queue
    queue = deque([(i, 0) for i in xrange(0, n)])
    while len(queue) > 0:
	(i, j) = queue.popleft()
	f(i, j, dp)

def f(i, j, dp):
    global queue
    for r in xrange(0, 3):
	(ni, nj) = (i+di[r], j+dj[r])
	if not valid(ni, nj): continue
	if dp[ni][nj] > dp[i][j] + a[ni][nj]:
	    dp[ni][nj] = dp[i][j] + a[ni][nj]
	    queue.append((ni, nj))	    
	
bfs(dp)
ans = min([dp[i][n-1] for i in xrange(0, n)])
print ans
