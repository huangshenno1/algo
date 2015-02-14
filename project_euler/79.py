# -*- coding: utf-8 -*-
# 只是一个取巧的解法，刚好可用的数字都之用了一次
	
f = open('p079_keylog.txt', 'r')
lines = f.readlines()
f.close()

vis = [True] * 10
pre = [0] * 10

for i in range(0, 10):
	pre[i] = set()

for line in lines:
	a = int(line[0])
	b = int(line[1])
	c = int(line[2])
	pre[b].add(a)
	pre[c].add(b)
	vis[a] = vis[b] = vis[c] = False

ans = ""
go = True
while go:
	go = False
	for i in range(0, 10):
		if vis[i]: continue
		if len(pre[i]) == 0:
			vis[i] = True
			ans += str(i)
			go = True
			for j in range(0, 10):
				if i in pre[j]:
					pre[j].remove(i)
			break
print ans
