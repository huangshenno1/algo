#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int from,to;
    int d;
    Edge(int from, int to, int d) {this->from=from; this->to=to; this->d=d;}
};

const int INF = 0x7fffffff;
const int maxn = 50010;
int n,st,ed;
int dis[maxn];
int cnt[maxn];
bool vis[maxn];
vector<Edge> edges;
vector<int> g[maxn];

void init()
{
    for (int i=0;i<=50000;i++)
        g[i].clear();
    edges.clear();
}

void addEdge(int from,int to,int d)
{
    edges.push_back(Edge(from,to,d));
    int t=edges.size();
    g[from].push_back(t-1);
}

void spfa()
{
    for (int i=st;i<=ed;i++)
        dis[i]=INF;
    dis[st]=0;
    for (int i=st;i<=ed;i++)
        vis[i]=0;
    for (int i=st;i<=ed;i++)
        cnt[i]=0;
    queue<int> Q;
    while (!Q.empty()) Q.pop();
    Q.push(st);
    vis[st]=1;
    cnt[st]=1;
    while (!Q.empty())
    {
        int u = Q.front();
        for(unsigned int i=0;i<g[u].size();i++)
        {
            Edge &e=edges[g[u][i]];
            if (dis[e.to]==INF || dis[u]+e.d>dis[e.to])
            {
                dis[e.to]=dis[u]+e.d;
                if(!vis[e.to])
                {
                    Q.push(e.to);
                    vis[e.to]=1;
                    cnt[e.to]++;
                }
            }
        }
        Q.pop();
        vis[u]=0;
    }
}

int main()
{
    int a,b,c;
    while (scanf("%d",&n)==1)
    {
        init();
        st=INF; ed=-INF;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b+1,c);
            if (a<st) st=a;
            if (b+1>ed) ed=b+1;
        }
        for (int i=st;i<ed;i++)
        {
            addEdge(i,i+1,0);
            addEdge(i+1,i,-1);
        }
        spfa();
        printf("%d\n",dis[ed]);
    }
    return 0;
}