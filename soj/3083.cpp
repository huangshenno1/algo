#include <cstdio>

const int mod = 19871118;
int n,m;
long long ans,t;

long long pow(long long x,int n)
{
    long long res=1;
    while (n)
    {
        if (n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        if (m==1)
        {
            puts("0");
            continue;
        }
        ans=m*(m-1);
        t=(m-2)*(m-2)+m-1;
        ans=(ans*pow(t,n-1))%mod;
        printf("%lld\n",ans);
    }
    return 0;
}