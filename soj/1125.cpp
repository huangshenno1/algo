#include <stdio.h>
#include <string.h>

int Min(int a,int b,int c)
{
    if (a>b) a=b;
    if (a>c) a=c;
    return a;
}

int n,m,p;
char map[101][101];
int dp[101][101];
int t,count;
int i,j;

int main()
{
    while (scanf("%d%d%d",&n,&m,&p)==3)
    {
        memset(dp,0,sizeof(dp));
        for (i=1;i<=n;i++)
            scanf("%s",map[i]+1);
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                if (map[i][j]=='1')
                    dp[i][j]=Min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
            }
        }
        while (p--)
        {
            scanf("%d",&t);
            count=0;
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                {
                    if (dp[i][j]>=t)
                        count++;
                }
            }
            printf("%d\n",count);
        }
    }
    return 0;
}