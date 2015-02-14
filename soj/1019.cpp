#include <cstdio>

int n,m;
int mp[11][101];
int dp[11][101];
int pre[11][101];
int cost,ans[101],k,p;

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&mp[i][j]);
        for (int i=0;i<n;i++) dp[i][0]=mp[i][0];
        for (int i=0;i<n;i++) pre[i][0]=-1;
        for (int j=1;j<m;j++)
            for (int i=0;i<n;i++)
            {
                dp[i][j] = dp[i][j-1]+mp[i][j];
                pre[i][j] = i;
                if (dp[i][j] > dp[(i+1)%n][j-1]+mp[i][j] || (dp[i][j] == dp[(i+1)%n][j-1]+mp[i][j] && i>(i+1)%n))
                {
                    dp[i][j] = dp[(i+1)%n][j-1]+mp[i][j];
                    pre[i][j] = (i+1)%n;
                }
                if (dp[i][j] > dp[(i+n-1)%n][j-1]+mp[i][j] || (dp[i][j] == dp[(i+n-1)%n][j-1]+mp[i][j] && i>(i+n-1)%n))
                {
                    dp[i][j] = dp[(i+n-1)%n][j-1]+mp[i][j];
                    pre[i][j] = (i+n-1)%n;
                }
            }
        k=m-1; cost=0x7fffffff;
        for (int i=0;i<n;i++)
            if (dp[i][k]<cost)
            {
                cost=dp[i][k];
                p=i;
            }
        ans[k]=p+1;
        while (pre[p][k]!=-1)
        {
            p=pre[p][k];
            k--;
            ans[k]=p+1;
        }
        printf("%d",ans[0]);
        for (int i=1;i<m;i++) printf(" %d",ans[i]);
        printf("\n%d\n",cost);
    }
    return 0;
}