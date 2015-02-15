//kruskal

struct Edge
{
    int from,to;
    int d;
	bool operator < (const Edge rhs) const
	{
		return d < rhs.d;
	}
}edge[maxm];

int ans;
int fa[maxn];

int findset(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = findset(fa[x]);
}

bool mergeset(int x, int y, int d)
{
	x = findset(x);
	y = findset(y);
	if (x == y) return 0;
	fa[y] = x;
	ans += d;
	return 1;
}

void kruskal()
{
	ans=0;
	for (int i = 0; i < n; i++) fa[i] = i;
	sort(edge, edge+m); //将所有边 根据边的权值 从小到大排列
	int nn = n;
	for (int i = 0; i < m; i++)
	{
		if (mergeset(edge[i].from, edge[i].to, edge[i].d)) nn--; //当合并成功，森林的树就少一棵
	}//如果nn!=1,说明该无向图不是连通图,不存在最小生成树
}