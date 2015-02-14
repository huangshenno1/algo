#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100005;
int T, n, k;
vector<int> g[maxn];
bool ans;

int dfs(int u, int fa)
{
    int ret = 1;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if (v == fa) continue;
        ret += dfs(v, u);
    }
    if (ret > k) ans = 0;
    if (ret == k) ret = 0;
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i=1; i<=n; i++) g[i].clear();
        for (int i=1; i<n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = 1;
        if (dfs(1, 0) > 0) ans = 0;
        if (ans) puts("YES");
        else puts("NO");
    }
    return 0;
}

