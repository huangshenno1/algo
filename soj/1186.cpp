#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 305;
int T,un,vn;
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
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&un,&vn);
        memset(g,0,sizeof(g));
        for (u=0;u<un;u++)
        {
            scanf("%d",&k);
            while (k--)
            {
                scanf("%d",&v); v--;
                g[u][v]=1;
            }
        }
        if (Hungarian()==un) puts("YES");
        else puts("NO");
    }
    return 0;
}
