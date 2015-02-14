#include <cstdio>

int n,d;
long long a[50010],sum,low,high,mid,ans;

bool judge(long long t)
{
    long long h=0;
    for (int i=1,j=1;i<=d;i++)
    {
        h>>=1;
        while (h<t&&j<=n)
            h+=a[j++];
        if (h<t) return 0;
    }
    return 1;
}

int main()
{
    while (scanf("%d%d",&n,&d)==2)
    {
        sum=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        low=0; high=sum;
        while (low<=high)
        {
            mid=(low+high)>>1;
            if (judge(mid)) {ans=mid; low=mid+1;}
            else high=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}