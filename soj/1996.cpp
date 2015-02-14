#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define ll long long

struct Edge
{
    int from, to, cap, flow;
    Edge(int ff,int tt,int cc,int fl) {from=ff; to=tt; cap=cc; flow=fl;}
};

const int INF = 0x3f3f3f3f;
const int maxn = 1505;
int n, m, sz, s, t;
vector<Edge> edges;
vector<int> g[maxn];
bool vis[maxn];
int dep[maxn];
int cur[maxn];
char tmp[1000000];

void init(int tot)
{
    edges.clear();
    for (int i=0;i<=tot;i++) g[i].clear();
    s = tot-1; t = tot;
}

void AddEdge(int from, int to, int cap)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    sz = edges.size();
    g[from].push_back(sz-2);
    g[to].push_back(sz-1);
}

bool bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    dep[s] = 0;
    vis[s] = 1;
    while (!Q.empty())
    {
        int x = Q.front(); Q.pop();
        for (int i = 0; i < g[x].size(); i++)
        {
            Edge& e = edges[g[x][i]];
            if (!vis[e.to] && e.cap > e.flow)
            {
                vis[e.to] = 1;
                dep[e.to] = dep[x]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}

int dfs(int x, int a)
{
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < g[x].size(); i++)
    {
        Edge& e = edges[g[x][i]];
        if (dep[x]+1 == dep[e.to] && (f = dfs(e.to, min(a, e.cap-e.flow))) > 0)
        {
            e.flow += f;
            edges[g[x][i]^1].flow -= f;
            flow += f;
            a -= f;
            if (a == 0) break;
        }
    }
    return flow;
}

int maxflow()
{
    int flow = 0;
    while (bfs())
    {
        memset(cur,0,sizeof(cur));
        flow += dfs(s, INF);
    }
    return flow;
}

bool check(int lim)
{
    for (int i=0;i<edges.size();i++) edges[i].flow = 0;
    for (int i = 0; i < g[t].size(); i++)
    {
        Edge& e = edges[g[t][i]^1];
        e.cap = lim;
    }
    if (maxflow() == n) return 1;
    return 0;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2 && n)
    {
        getchar();
        init(n+m+1);
        for (int i=0;i<n;i++)
        {
            AddEdge(s, i, 1);
            gets(tmp); int l = strlen(tmp);
            tmp[l] = '$'; tmp[l+1] = 0;
            int x = 0, go = 0;
            for (int j=0;tmp[j];j++)
            {
                if (tmp[j] >= '0' && tmp[j] <= '9')
                {
                    go = 1;
                    x = x*10 + tmp[j]-'0';
                }
                else
                {
                    if (go)
                    {
                        AddEdge(i, n+x, 1);
                        go = 0;
                        x = 0;
                    }
                }
            }
        }
        for (int i=n;i<n+m;i++)
            AddEdge(i, t, INF);
        int low = 1, high = n, mid, ans;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            if (check(mid)) high = mid-1, ans = mid;
            else low = mid+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
