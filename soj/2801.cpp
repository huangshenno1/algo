#include <stdio.h>
#include <string.h>

int Min(int a,int b,int c)
{
    a=a<c?a:c;
    return a<b?a:b;
}

bool map[1002][1002];
int dp[1002][1002];

int main()
{
    int n,m;
    int i,j;
    int max;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        max=0;
        while (m--)
        {
            scanf("%d%d",&i,&j);
            map[i][j]=1;
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (map[i][j]==0)
                {
                    dp[i][j]=Min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1;
                    if (dp[i][j]>max)
                        max=dp[i][j];
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}