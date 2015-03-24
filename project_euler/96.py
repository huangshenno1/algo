def load(lines):
    for line in lines:
	yield(map(int, line.strip()))

def show(a):
    print '-'*9
    for i in xrange(0, 9):
	print ''.join(map(str, a[i]))

def possible(a, i, j):
    can = set(xrange(1, 10))
    for k in xrange(0, 9):
	if a[i][k] > 0: can.discard(a[i][k])
	if a[k][j] > 0: can.discard(a[k][j])
    (i0, j0) = (i/3*3, j/3*3)
    for k1 in xrange(0, 3):
	for k2 in xrange(0, 3):
	    if a[i0+k1][j0+k2] > 0: can.discard(a[i0+k1][j0+k2])
    return can     
 
def dfs(a, i, j):
    if i == 9: return True
    (ni, nj) = (i, j+1)
    if nj == 9: (ni, nj) = (i+1, 0)
    if a[i][j] > 0:
	return dfs(a, ni, nj)
    else:
	can = possible(a, i, j)
	for x in can:
	    a[i][j] = x
	    if dfs(a, ni, nj): return True
	a[i][j] = 0
    return False

def solve(a):
    dfs(a, 0, 0)
    return a

f = open('p096_sudoku.txt', 'r')
lines = f.readlines()
f.close()

ans = 0
for grid in xrange(0, 50):
    print "Grid %d" % (grid+1)
    a = list(load(lines[grid*10+1:grid*10+10]))
    b = solve(a)
    ans += int(''.join(map(str, b[0][0:3])))
    show(b)
print ans
