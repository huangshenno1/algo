#include <cstdio>

int n,m;
int g[110][110],path[10010];

void floyd()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if(g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=m;i++)
            scanf("%d",&path[i]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&g[i][j]);
        floyd();
        long long ans=0;
        for (int i=2;i<=m;i++)
            ans+=(long long)g[path[i-1]][path[i]];
        printf("%lld\n",ans);
    }
    return 0;
}