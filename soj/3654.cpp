#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 50010;

struct Edge
{
    int from,to;
    int d;
    Edge(int from, int to, int d) {this->from=from; this->to=to; this->d=d;}
};

struct HeapNode
{
    int d,u;
    HeapNode(int d, int u) {this->d=d; this->u=u;}
    bool operator < (const HeapNode &rhs) const
    {
        return d>rhs.d;
    }
};

int n,m,b;
int dis[maxn];
bool vis[maxn];
vector<Edge> edges;
vector<int> g[maxn];

void init()
{
    for (int i=0;i<n;i++)
        g[i].clear();
    edges.clear();
}

void addEdge(int from,int to,int d)
{
    edges.push_back(Edge(from,to,d));
    int t=edges.size();
    g[from].push_back(t-1);
}

void dijkstra(int st)
{
    priority_queue<HeapNode> Q;
    while (!Q.empty()) Q.pop();
    for (int i=0;i<n;i++)
        dis[i]=-1;
    dis[st]=0;
    for (int i=0;i<n;i++)
        vis[i]=0;
    Q.push(HeapNode(0,st));
    while (!Q.empty())
    {
        HeapNode x=Q.top(); Q.pop();
        int u=x.u;
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=0;i<g[u].size();i++)
        {
            Edge &e=edges[g[u][i]];
            if (dis[e.to]==-1 || dis[e.to]>dis[u]+e.d)
            {
                dis[e.to]=dis[u]+e.d;
                Q.push(HeapNode(dis[e.to],e.to));
            }
        }
    }
}

int main()
{
    int u,v,d;
    while (scanf("%d%d%d",&n,&m,&b)==3)
    {
        init();
        while (m--)
        {
            scanf("%d%d%d",&u,&v,&d);
            addEdge(u-1,v-1,d);
            addEdge(v-1,u-1,d);
        }
        dijkstra(0);
        while (b--)
        {
            scanf("%d%d",&u,&v);
            d=dis[u-1]+dis[v-1];
            printf("%d\n",d);
        }
    }
    return 0;
}