#include <cstdio>

int main()
{
    int n,p[25],dp[25],a[25],b[25],ans;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
    while (scanf("%d",&a[1])==1)
    {
        for (int i=2;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) b[p[i]]=a[i];

//         for (int i=1;i<=n;i++) printf("%d ",a[i]);
//         printf("\n\n");

        for (int i=1;i<=n;i++) dp[i]=1;
        for (int i=2;i<=n;i++)
            for (int j=1;j<i;j++)
                if (b[i]>b[j] && dp[i]<=dp[j]) dp[i]=dp[j]+1;
        ans=dp[1];
        for (int i=2;i<=n;i++)
            if (ans<dp[i]) ans=dp[i];
        printf("%d\n",ans);
    }
    return 0;
}