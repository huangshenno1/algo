#include <cstdio>

const int maxn = 250010;
int n,a[maxn],dp[maxn],ans,i;

inline int Max(int a,int b) {return a>b?a:b;}

int main()
{
    while (~scanf("%d",&n) && n)
    {
        for (i=1;i<=n;i++) scanf("%d",&a[i]);
        for (dp[0]=0,i=1;i<=n;i++) dp[i]=a[i]+Max(0,dp[i-1]);
        for (ans=a[1],i=2;i<=n;i++) ans=Max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
};