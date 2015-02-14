#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int apple[105];
int dp1[105][205],dp2[105][205];
vector<int> g[105];
bool vis[105];

void dfs(int u)
{
    vis[u]=1;
    for (int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if (vis[v]) continue;
        dfs(v);
        for (int j=m;j>=0;j--)
            for (int k=0;k<=j;k++)
            {
                dp1[u][j+1] = max(dp1[u][j+1], dp2[u][j-k]+dp1[v][k]);
                dp1[u][j+2] = max(dp1[u][j+2], dp1[u][j-k]+dp2[v][k]);
                dp2[u][j+2] = max(dp2[u][j+2], dp2[u][j-k]+dp2[v][k]);
            }
    }
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++) scanf("%d",&apple[i]);
        for (int i=1;i<=n;i++) g[i].clear();
        for (int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for (int i=1;i<=n;i++)
            for (int j=0;j<=m;j++)
                dp1[i][j]=dp2[i][j]=apple[i];
        for (int i=1;i<=n;i++) vis[i]=0;
        dfs(1);
        printf("%d\n",dp1[1][m]);
    }
    return 0;
}