#include <cstdio>

int main()
{
    int t;
    int n,a[31],sum;
    int dp[30001];
    int i,j;
    int ans;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        sum=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        dp[0]=1;
        for (i=1;i<=sum;i++)
        {
            dp[i]=0;
        }
        for (i=0;i<n;i++)
        {
            for (j=sum;j>0;j--)
            {
                if (j>=a[i])
                    dp[j]+=dp[j-a[i]];
            }
        }
        ans=0;
        for (i=1;i<=sum;i++)
        {
            if (dp[i])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}