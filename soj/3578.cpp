#include <stdio.h>

long long Pow(long long a,long long b,long long p)
{
    long long ans=1;
    while (b)
    {
        if (b&1)
            ans=(ans*a)%p;
        a=(a*a)%p;
        b=b>>1;
    }
    return ans;
}

int main()
{
    int t;
    long long a,b,c;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",Pow(a,Pow(b,c,317000010),317000011));
    }
    return 0;
}