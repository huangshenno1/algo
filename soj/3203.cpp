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

const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int maxn = 205;
int n, tot, a[maxn], b[maxn];
double d, x[maxn], y[maxn];
int ans[maxn], cans;

int dcmp(double x) {if (fabs(x) < eps) return 0; return x < 0 ? -1 : 1;}
double sqr(double x) {return x * x;}

struct Edge
{
    int from, to, cap, flow;
    Edge(int ff,int tt,int cc,int fl) {from=ff; to=tt; cap=cc; flow=fl;}
};

int sz, s, t;
vector<Edge> edges;
vector<int> g[maxn];
bool vis[maxn];
int dep[maxn];
int cur[maxn];

void init()
{
    edges.clear();
    s=n*2;
    for (int i=0;i<=s;i++) g[i].clear();
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

bool check(int i)
{
    t = i*2;
    for (int i=0;i<edges.size();i++) edges[i].flow = 0;
    if (maxflow() == tot) return 1;
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lf", &n, &d);
        init();
        tot = 0;
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf%d%d", &x[i], &y[i], &a[i], &b[i]);
            tot += a[i];
            AddEdge(s, i*2, a[i]);
            AddEdge(i*2, i*2+1, b[i]);
        }
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (dcmp(sqr(x[i]-x[j]) + sqr(y[i]-y[j]) - d*d) <= 0)
                {
                    AddEdge(i*2+1, j*2, INF);
                    AddEdge(j*2+1, i*2, INF);
                }
        cans = 0;
        for (int i=0;i<n;i++)
            if (check(i)) ans[cans++] = i;
        if (cans > 0)
        {
            printf("%d", ans[0]);
            for (int i=1;i<cans;i++) printf(" %d", ans[i]);
            puts("");
        }
        else puts("-1");
    }
    return 0;
}
