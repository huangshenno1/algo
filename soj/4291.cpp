#include <cstdio>
typedef long long ll;

const int mod = 1000000007;
ll n,m,n1,n2,m1,m2,ans1,ans2,ans3,ans4,ans;

int main()
{
    while (scanf("%lld%lld",&n,&m)==2)
    {
        n1=n/2; n2=(n+1)/2; m1=m/2; m2=(m+1)/2;
        ans1=((((n1*m1)%mod)*((n1*m2+n2*m1+n2*m2)%mod)%mod)*((n2*m2*2)%mod))%mod;
        ans2=((((n2*m1)%mod)*((n2*m2+n1*m1+n1*m2)%mod)%mod)*((n1*m2*2)%mod))%mod;
        ans3=((((n1*m2)%mod)*((n1*m1+n2*m2+n2*m1)%mod)%mod)*((n2*m1*2)%mod))%mod;
        ans4=((((n2*m2)%mod)*((n2*m1+n1*m2+n1*m1)%mod)%mod)*((n1*m1*2)%mod))%mod;
        ans=(ans1+ans2+ans3+ans4)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}