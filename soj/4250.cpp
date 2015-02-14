#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool dp[50010];
int step[50010];

int main()
{
    int T,n,a[210],sum,ans;
    scanf("%d",&T);
    while (T--)
    {
        memset(dp,0,sizeof(dp));
        memset(step,0x3f,sizeof(step));
        scanf("%d",&n);

        sum=0;
        scanf("%d",&a[0]);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=abs(a[i]);
            sum+=a[i];
        }
        scanf("%d",&a[n+1]);

        dp[0]=1; step[0]=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=a[0];j>=a[i];j--)
            {
                if (dp[j-a[i]])
                {
                    dp[j]=1;
                    step[j]=min(step[j],i);
                }
            }
        }

        ans=0x3f3f3f3f;
        for (int j=0;j<=a[0];j++)
        {
            if (dp[j] && sum-j<=a[n+1]) ans=min(ans,step[j]);
        }

        if (ans==0x3f3f3f3f) {printf("Lazy Power\n"); continue;}

        ans=ans*2+n+1;
        printf("%d\n",ans);
    }
    return 0;
}