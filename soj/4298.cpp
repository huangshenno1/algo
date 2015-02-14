#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100010;
int n,ans;
vector<int> g[maxn];
int dp[maxn];

void dfs(int u,int fa)
{
    dp[u]=1;
    for (int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if (v==fa) continue;
        dfs(v,u);
        dp[u]+=dp[v];
    }
    if (dp[u]%2==0) ans++;
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++) g[i].clear();
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=0;
        dfs(1,0);
        printf("%d\n",ans-1);
    }
    return 0;
}
