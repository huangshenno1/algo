#include <stdio.h>
#include <string.h>

#define N 60
#define MAX 2100000000

const int d[4][2]={1,0,-1,0,0,1,0,-1};
int h[N][N];
int mark[N][N];
int maxl[N][N];

void ski(int x,int y)
{
    int i;
    int maxd[4];
    int maxt=0;
    if (mark[y][x])
        return;
    for (i=0;i<4;i++)
    {
        if (h[y+d[i][1]][x+d[i][0]]<h[y][x])
        {
            if (mark[y+d[i][1]][x+d[i][0]]);
            else ski(x+d[i][0],y+d[i][1]);
            maxd[i]=maxl[y+d[i][1]][x+d[i][0]]+1;
            if (maxd[i]>maxt)
                maxt=maxd[i];
        }
    }
    mark[y][x]=1;
    maxl[y][x]=maxt;
}
int main()
{
    int m,n;
    int i,j;
    int max;
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    while(m||n)
    {
        memset(mark,0,sizeof(mark));
        memset(maxl,0,sizeof(maxl));
        max=0;
        for (j=1;j<=n;j++)
        {
            h[j][0]=MAX;
            h[j][m+1]=MAX;
        }
        for (i=1;i<=m;i++)
        {
            h[0][i]=MAX;
            h[n+1][i]=MAX;
        }
        for (j=1;j<=n;j++)
            for (i=1;i<=m;i++)
                scanf("%d",&h[j][i]);
        for (j=1;j<=n;j++)
        {
            for (i=1;i<=m;i++)
            {
                ski(i,j);
                if (maxl[j][i]>max)
                    max=maxl[j][i];
            }
        }
        printf("%d\n",max);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
