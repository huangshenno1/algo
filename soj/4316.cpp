#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <cassert>
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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

const int mod = (int)1e9+7;
const int maxn = 5005;
int n, m;
vector<int> g[maxn];
vector<int> color[maxn];
bool can[maxn][maxn];
int sum[maxn];
int dp[maxn][maxn];

void dfs(int u, int fa)
{
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
    }
    ll tot = 0;
    for (int j=0;j<color[u].size();j++)
    {
        ll cur = 1;
        int c = color[u][j];
        for (int i=0;i<g[u].size();i++)
        {
            int v = g[u][i];
            if (v == fa) continue;
            if (can[v][c])
            {
                ll tmp = (sum[v] - dp[v][c] + mod) % mod;
                cur = (cur * tmp) % mod;
            }
            else cur = (cur * sum[v]) % mod;
        }
        dp[u][c] = cur;
        tot += cur;
    }
    sum[u] = tot % mod;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i=1;i<=n;i++) g[i].clear(), color[i].clear();
        memset(can, 0, sizeof(can));
        for (int i=1;i<=n;i++)
        {
            int k, v;
            scanf("%d", &k);
            while (k--)
            {
                scanf("%d", &v);
                color[i].push_back(v);
                can[i][v] = 1;
            }
        }
        for (int i=1;i<n;i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        printf("%d\n", sum[1]);
    }
    return 0;
}
