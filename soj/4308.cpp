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

const int maxn = 105;
int T, n, m;
int edges[maxn], weight[maxn], tot;
vector<int> g[maxn];
int sum[maxn];

void addEdge(int u, int v, int w)
{
    g[u].push_back(tot);
    edges[tot] = v;
    weight[tot] = w;
    tot++;
}

void dfs(int u)
{
    for (int i=0;i<g[u].size();i++)
    {
        int v = edges[g[u][i]];
        if (sum[v] == -1)
        {
            sum[v] = sum[u] ^ weight[g[u][i]];
            dfs(v);
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        tot = 0;
        for (int i=0;i<n;i++) g[i].clear();
        for (int i=0;i<m;i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w); u--; v--;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        memset(sum, -1, sizeof(sum));
        for (int i=0;i<n;i++)
            if (sum[i] == -1)
            {
                sum[i] = 0;
                dfs(i);
            }
        bool go = 1;
        for (int i=0;i<(m<<1);i+=2)
            if ((sum[edges[i]] ^ sum[edges[i^1]]) != weight[i]) {go = 0; break;} // ^ 的优先级居然比 == 低
        if (go) puts("Yes");
        else puts("No");
    }
    return 0;
}
