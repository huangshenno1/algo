#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
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
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
const int maxn = 10010;

struct Edge
{
    int from, to, cap, flow;
    Edge(int ff,int tt,int cc,int fl) {from=ff; to=tt; cap=cc; flow=fl;}
};

int n,m,sz,s,t;
int a[110][110];
vector<Edge> edges;
vector<int> g[maxn];
bool vis[maxn];
int d[maxn];
int cur[maxn];

void init()
{
    edges.clear();
    for (int i=0;i<=n*m+1;i++) g[i].clear();
    s=0; t=n*m+1;
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

const int di[]={0,0,-1,1}, dj[]={-1,1,0,0};

inline bool inside(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m;
}

inline int hash(int i,int j)
{
    return i*m+j+1;
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        init();
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                if ((i+j)&1)
                {
                    AddEdge(s,hash(i,j),a[i][j]);
                    for (int r=0;r<4;r++)
                    {
                        int ni=i+di[r], nj=j+dj[r];
                        if (!inside(ni,nj)) continue;
                        AddEdge(hash(i,j),hash(ni,nj),INF);
                    }
                }
                else AddEdge(hash(i,j),t,a[i][j]);
            }
        int ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                ans+=a[i][j];
        printf("%d\n",ans-maxflow());
    }
    return 0;
}
