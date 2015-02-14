#include <stdio.h>

int main()
{
    int t;
    long long ans,n,m;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&n);
        m=n-n/3;
        ans=((1+m)*m/2+1)*(n+1-m);
        printf("%lld\n",ans);
    }
    return 0;
}