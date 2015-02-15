//Tarjan

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 4005;
int n;
vector<int> g[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;
stack<int> stk;

void dfs(int u)
{
	pre[u]=lowlink[u]=++dfs_clock;
	stk.push(u);
	for (int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if (!pre[v])
		{
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if (!sccno[v])
		{
			lowlink[u]=min(lowlink[u],pre[v]);
		}
	}
	if (lowlink[u]==pre[u])
	{
		scc_cnt++;
		while (1)
		{
			int x=stk.top(); stk.pop();
			sccno[x]=scc_cnt;
			if (x==u) break;
		}
	}
}

void find_scc()
{
	dfs_clock=scc_cnt=0;
	while (!stk.empty()) stk.pop();
	memset(sccno,0,sizeof(sccno));
	memset(pre,0,sizeof(pre));
	for (int i=0;i<n;i++)
		if (!pre[i]) dfs(i);
}
