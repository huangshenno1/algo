//Stoer-Wagner

#include <cstdio>
#include <cstring>

const int INF = 0x3f3f3f3f;
const int maxn = 301;
int n, s, t, mincut;
int g[maxn][maxn];
int dist[maxn];
int comb[maxn];
bool vis[maxn];

void prim()
{
	memset(vis, 0, sizeof(vis));
	memset(dist, 0, sizeof(dist));
	s = t = -1;
	for (int i = 0; i < n; i++)
	{
		int maxdist = -INF;
		int p = -1;
		for (int j = 0; j < n; j++)
		{
			if (!comb[j] && !vis[j] && dist[j]>maxdist)
			{
				maxdist = dist[j];
				p = j;
			}
		}
		if (p == -1) return;
		vis[p] = 1;
		mincut = maxdist;
		s = t; t = p;
		for (int j = 0; j < n; j++)
		{
			if (!comb[j] && !vis[j])
				dist[j] += g[p][j];
		}
	}
}

int StoerWagner()
{
	int res = INF;
	memset(comb, 0, sizeof(comb));
	for (int k = 0; k < n-1; k++)
	{
		prim();
		if (mincut < res) res = mincut;
		comb[t] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!comb[i])
			{
				g[s][i] += g[t][i];
				g[i][s] += g[i][t];
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i==t || j==t || i==j) g[i][j] = 0;
	}
	return res;
}