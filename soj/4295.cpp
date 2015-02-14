#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100010;
struct Edge
{
    int v,d;
    Edge(int v,int d):v(v),d(d){}
};
int n, q;
int maxodd, maxeven;
vector<Edge> g[maxn];
int dpodd[maxn],dpeven[maxn];

void dfs(int u,int fa)
{
    int modd=-INF, meven=0;
    for (int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].v;
        if (v==fa) continue;
        dfs(v,u);
        int d1=g[u][i].d+dpodd[v], d2=g[u][i].d+dpeven[v];
        if (d1&1)
        {
            maxodd=max(maxodd,d1+meven);
            maxeven=max(maxeven,d1+modd);
        }
        else
        {
            maxodd=max(maxodd,d1+modd);
            maxeven=max(maxeven,d1+meven);
        }
        if (d2&1)
        {
            maxodd=max(maxodd,d2+meven);
            maxeven=max(maxeven,d2+modd);
        }
        else
        {
            maxodd=max(maxodd,d2+modd);
            maxeven=max(maxeven,d2+meven);
        }
        if (d1&1) modd=max(modd,d1);
        else meven=max(meven,d1);
        if (d2&1) modd=max(modd,d2);
        else meven=max(meven,d2);
    }
    dpodd[u]=modd;
    dpeven[u]=meven;
}

int main()
{
    while (scanf("%d%d",&n,&q)==2)
    {
        for (int i=1;i<=n;i++) g[i].clear();
        for (int i=1;i<n;i++)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            g[u].push_back(Edge(v,d));
            g[v].push_back(Edge(u,d));
        }
        maxodd=-INF; maxeven=0;
        dfs(1,0);
        while (q--)
        {
            int l;
            scanf("%d",&l);
            if (l<0) {puts("No"); continue;}
            if ((l&1) && l<=maxodd) {puts("Yes"); continue;}
            if (!(l&1) && l<=maxeven) {puts("Yes"); continue;}
            puts("No");
        }
    }
    return 0;
}
