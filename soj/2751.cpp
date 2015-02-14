#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3fffffff;
const int maxn = 510;

struct Edge
{
    int from,to;
    int d;
    Edge(int from, int to, int d) {this->from=from; this->to=to; this->d=d;}
};

int T,n,m,w;
int dis[maxn];
int cnt[maxn];
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

bool spfa(int st)
{
    for (int i=0;i<n;i++)
        dis[i]=INF;
    dis[st]=0;
    for (int i=0;i<n;i++)
        vis[i]=0;
    for (int i=0;i<n;i++)
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
            if (dis[u]+e.d<dis[e.to]) //更改后距离更短,进行松弛操作
            {
                dis[e.to]=dis[u]+e.d;
                if(!vis[e.to])
                {
                    Q.push(e.to);
                    vis[e.to]=1;
                    cnt[e.to]++;
                    if(cnt[e.to]>=n) //已经超过n次,出现负环
                        return 0;
                }
            }
        }
        Q.pop();
        vis[u]=0;
    }
    return 1;
}

int main()
{
    while (scanf("%d",&T)==1)
    {
        while (T--)
        {
            scanf("%d%d%d",&n,&m,&w);
            init();
            while (m--)
            {
                int s,e,t;
                scanf("%d%d%d",&s,&e,&t);
                addEdge(s-1,e-1,t);
                addEdge(e-1,s-1,t);
            }
            while (w--)
            {
                int s,e,t;
                scanf("%d%d%d",&s,&e,&t);
                addEdge(s-1,e-1,-t);
            }
            bool ans=0;
            for (int i=0;i<n;i++)
                if (!spfa(i)) {ans=1; break;}
            if (ans) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
