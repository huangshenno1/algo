#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 505;
int n,un,vn;
int g[maxn][maxn];
int link[maxn];
bool vis[maxn];

bool dfs(int u)
{
    for (int v = 0; v < vn; v++)
    {
        if (g[u][v] && !vis[v])
        {
            vis[v] = 1;
            if (link[v]==-1 || dfs(link[v]))
            {
                link[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int Hungarian()
{
    int res = 0;
    memset(link, -1, sizeof(link));
    memset(vis, 0, sizeof(vis));
    for (int u = 0; u < un; u++)
    {
        if (dfs(u))
        {
            res++;
            memset(vis, 0, sizeof(vis));
        }
    }
    return res;
}


int main()
{
    int k,u,v;
    while (scanf("%d",&n)==1)
    {
        un=vn=n;
        memset(g,0,sizeof(g));
        for (int i=0;i<n;i++)
        {
            scanf("%d: (%d)",&u,&k);
            while (k--)
            {
                scanf("%d",&v);
                g[u][v]=1;
            }
        }
        printf("%d\n",n-Hungarian()/2);
    }
    return 0;
}
