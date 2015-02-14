#include <cstdio>

long long f(long long m)
{
    return m*(m-1)/2;
}

int main()
{
    int n;
    long long m,ans;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%lld",&m);
        if (m&1)
        {
            m/=2;
            ans=f(m)+f(m+1);
        }
        else
        {
            m/=2;
            ans=2*f(m);
        }
        printf("%lld\n",ans);
    }
    return 0;
}