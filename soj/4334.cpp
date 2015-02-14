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

const int maxn = 1005;
struct Edge
{
    int to, val;
    Edge(int v, int vv) : to(v), val(vv) {}
};
int n, c;
vector<Edge> g[maxn];

int dfs(int u, int fa)
{
    int ret = 0;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].to;
        if (v == fa) continue;
        ret += min(g[u][i].val, dfs(v, u));
    }
    if (ret == 0) ret = 1000000;
    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &n, &c) == 2)
    {
        for (int i=1;i<=n;i++) g[i].clear();
        for (int i=1;i<n;i++)
        {
            int u, v, val;
            scanf("%d%d%d", &u, &v, &val);
            g[u].push_back(Edge(v, val));
            g[v].push_back(Edge(u, val));
        }
        printf("%d\n", dfs(c, 0));
    }
    return 0;
}
