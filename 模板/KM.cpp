#include <cstdio>
#include <cstring>

const int INF = 10000;
const int maxn = 105;
int n,un,vn,ans;
int a[maxn], b[maxn];
int g[maxn][maxn], mp[maxn][maxn];
int link[maxn], lu[maxn], lv[maxn], slack[maxn];
bool visu[maxn], visv[maxn];

bool dfs(int u)
{
	visu[u] = 1;
	for (int v = 0; v < vn; v++)
	{
		if (visv[v]) continue;
		int t = lu[u] + lv[v] - g[u][v];
		if (t == 0)
		{
			visv[v] = 1;
			if (link[v] == -1 || dfs(link[v]))
			{
				link[v] = u;
				return 1;
			}
		}
		else if (slack[v] > t)
			slack[v] = t;
	}
	return 0;
}

int KM()
{
	memset(link, -1, sizeof(link));
	memset(lv, 0, sizeof(lv));
	for (int u = 0; u < un; u++) lu[u] = -INF;
	for (int u = 0; u < un; u++)
		for (int v = 0; v < vn; v++)
			if (g[u][v] > lu[u]) lu[u] = g[u][v];

	for (int u = 0; u < un; u++)
	{
		for (int v = 0; v < vn; v++) slack[v] = INF;
		while (1)
		{
			memset(visu, 0, sizeof(visu));
			memset(visv, 0, sizeof(visv));
			if (dfs(u)) break;
			int d = INF;
			for (int v = 0; v < vn; v++)
				if (!visv[v] && d>slack[v])
					d = slack[v];
			for (int i = 0; i < un; i++)
				if (visu[i]) lu[i] -= d;
			for (int v = 0; v < vn; v++)
				if (visv[v]) lv[v] += d;
				else slack[v] -= d;
		}
	}
	int res = 0;
	for (int v = 0; v < vn; v++)
		if (link[v] > -1)
			res += g[link[v]][v];
	return res;
}