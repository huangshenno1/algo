#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 2005;
int n, w[maxn];
vector<int> g[maxn];
int dp[maxn][maxn];
int ans[maxn];

int dfs(int u, int fa)
{
    int cnt = 1;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if (v == fa) continue;
        int cc = dfs(v, u);
        for (int j=cnt-1;j>=0;j--)
            for (int k=1;k<=cc;k++)
                dp[u][j+k] = min(dp[u][j+k], dp[u][j] + dp[v][k]);
        cnt += cc;
    }
    for (int i=cnt;i>=1;i--) dp[u][i] = dp[u][i-1] + w[u];
    return cnt;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i=1;i<=n;i++) g[i].clear();
        memset(dp, 0x3f, sizeof(dp));
        for (int i=1;i<=n;i++) dp[i][0] = 0;
        memset(ans, 0x3f, sizeof(ans));
        for (int i=1;i<=n;i++) scanf("%d", &w[i]);
        for (int i=1;i<n;i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                ans[j] = min(ans[j], dp[i][j]);
        for (int i=1;i<n;i++) printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
    }
    return 0;
}
