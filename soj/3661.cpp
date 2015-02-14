#include <cstdio>

int main()
{
    int a[181],b[181],dp[181][181];
    int la,lb,i,j,ans;
    while (scanf("%d%d",&la,&lb)==2)
    {
        for (i=1;i<=la;i++) scanf("%d",&a[i]);
        for (j=1;j<=lb;j++) scanf("%d",&b[j]);
        for (i=0;i<=la;i++) dp[i][0]=0;
        for (j=0;j<=lb;j++) dp[0][j]=0;

        ans=0;
        for (i=1;i<=la;i++)
        {
            for (j=1;j<=lb;j++)
            {
                if (a[i]==b[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    if (dp[i][j]>ans) ans=dp[i][j];
                }
                else dp[i][j]=0;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}