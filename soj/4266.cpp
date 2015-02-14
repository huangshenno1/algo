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
const int maxn = 510;
int T,n,m,s,t;
vector<Edge> edges;
vector<int> g[maxn];
bool vis[maxn];
int d[maxn];
int cur[maxn];

void init()
{
    edges.clear();
    s=0; t=2*n+1;
    for (int i=s;i<t;i++) g[i].clear();
}

void AddEdge(int from, int to, int cap)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
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
    int a,b,k,ans;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        init();
        ans=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            ans+=a;
            AddEdge(s,i,a);
            AddEdge(i+n,t,b);
        }
        for (int i=1;i<=n;i++)
        {
            AddEdge(i,i+n,INF);
            scanf("%d",&k);
            while (k--)
            {
                scanf("%d",&a);
                AddEdge(i,a+n,INF);
            }
        }
        printf("%d\n",ans-maxflow());
    }
    return 0;
}