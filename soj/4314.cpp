#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int n, m;
vector<int> g[maxn];
int ans[maxn];
bool vis[maxn];

void dfs(int u, int x)
{
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if (ans[v] >= 0) continue;
        ans[v] = x;
        dfs(v, x);
    }
}

int main()
{
    int i, u, v;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (i=1;i<=n;i++) g[i].clear();
        for (i=1;i<=m;i++)
        {
            u, v;
            scanf("%d%d", &u, &v);
            g[v].push_back(u);
        }
        memset(ans, -1, sizeof(ans));
        for (i=n;i>=1;i--)
            if (ans[i] < 0)
            {
                ans[i] = i;
                dfs(i, i);
            }
        for (int i=1;i<n;i++) printf("%d ", ans[i]);
        printf("%d\n", ans[n]);
        
    }
    return 0;
}