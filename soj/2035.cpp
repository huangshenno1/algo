#include <cstdio>
#include <cstring>

const int maxn = 4000;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int m,n;
char a[70][70];
int hash1[maxn],hash2[maxn];

int un,vn;
bool g[maxn][maxn];
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

bool inside(int i,int j) {return i>=0 && i<n && j>=0 && j<m;}

int main()
{
    while (scanf("%d%d",&n,&m)==2 && (n||m))
    {
        un=vn=0;
        for(int i=0;i<n;i++) scanf("%s",a[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]=='#') {if (i%2==j%2) hash1[i*m+j]=un++; else hash2[i*m+j]=vn++;}
        if (un!=vn) {puts("IMPOSSIBLE\n"); continue;}

        memset(g,0,sizeof(g));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (a[i][j]=='#' && i%2==j%2)
                    for (int k=0;k<4;k++)
                    {
                        int ii=i+di[k], jj=j+dj[k];
                        if (inside(ii,jj) && a[ii][jj]=='#') g[hash1[i*m+j]][hash2[ii*m+jj]]=1;
                    }
        if(Hungarian()==un) puts("POSSIBLE\n");
        else puts("IMPOSSIBLE\n");
    }
    return 0;
}
