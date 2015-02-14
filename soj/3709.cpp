#include <cstdio>

int T,d,n;
int a[50005],sum[50005],cnt[1000005];
long long ans;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&d,&n);
        for (int i=0;i<d;i++) cnt[i]=0;
        ans=0; sum[0]=0; cnt[0]=1;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=(sum[i-1]+a[i])%d;
            ans+=cnt[sum[i]]++;//
        }
//        for (int i=0;i<d;i++) ans+=(long long)cnt[i]*(cnt[i]-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}