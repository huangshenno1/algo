#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
const int maxn = 6010;

int n,ans;
int w[maxn];
vector<int> g[maxn];
int dp[maxn][2];

void dfs(int u,int fa)
{
    dp[u][0]=0;
    dp[u][1]=w[u];
    for (int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if (v==fa) continue;
        dfs(v,u);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++) scanf("%d",&w[i]);
        for (int i=1;i<=n;i++) g[i].clear();
        int u,v;
        while (scanf("%d%d",&u,&v)==2 && u)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        ans=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=1;j++)
                ans=max(ans,dp[i][j]);
        printf("%d\n",ans);
    }
    return 0;
}
