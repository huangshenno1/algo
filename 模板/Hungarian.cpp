//Hungarian

#include <cstdio>
#include <cstring>

const int maxn = 505;
int un,vn;
int g[maxn][maxn];
int link[maxn];
bool vis[maxn];

bool dfs(int u)
{
	for (int v = 0; v < vn; v++)
	{
		if (g[u][v] && !vis[v])
		{
			vis[v] = 1;
			if (link[v]==-1 || dfs(link[v]))
			{
				link[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int Hungarian()
{
	int res = 0;
	memset(link, -1, sizeof(link));
	memset(vis, 0, sizeof(vis));
	for (int u = 0; u < un; u++)
	{
		if (dfs(u))
		{
			res++;
			memset(vis, 0, sizeof(vis));
		}
	}
	return res;
}
