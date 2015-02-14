#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int from, to, cap, flow;
    Edge(int ff,int tt,int cc,int fl) {from=ff; to=tt; cap=cc; flow=fl;}
};

const int INF = 0x7f7f7f7f;
const int maxn = 200;
int n,m,sz,s,t;
vector<Edge> edges;
vector<int> g[maxn];
bool vis[maxn];
int d[maxn];
int cur[maxn];

void init(int tot)
{
    edges.clear();
    for (int i=0;i<=tot;i++) g[i].clear();
    s=0; t=tot;
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
    d[s] = 0;
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
                d[e.to] = d[x]+1;
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
        if (d[x]+1 == d[e.to] && (f = dfs(e.to, min(a, e.cap-e.flow))) > 0)
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

int main()
{
    int u, v, c;
    char ch;
    while (scanf("%d%d", &m ,&n) == 2)
    {
        init(m + n + 1);
        for (u=1;u<=m;u++)
        {
            scanf("%d", &c);
            AddEdge(s, u, c);
            v = 0;
            while (ch = getchar(), ch != '\n')
            {
                if (ch>='0' && ch<='9') v = v*10 + ch-'0';
                else
                {
                    if (v > 0) AddEdge(u, m+v, INF);
                    v = 0;
                }
            }
            if (v > 0) AddEdge(u, m+v, INF);
        }
        for (v=1;v<=n;v++)
        {
            scanf("%d", &c);
            AddEdge(m+v, t, c);
        }
        maxflow();
        int ans = 0;
        for (int i=0;i<g[s].size();i++)
        {
            Edge& e = edges[g[s][i]];
            ans += e.cap - e.flow;
        }
        printf("%d\n", ans);
    }
    return 0;
}
