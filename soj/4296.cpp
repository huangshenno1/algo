#include <cstdio>

typedef long long ll;
const int mod = 1000000007;
const int maxn = 100010;
int n;
ll a[maxn],b[maxn],sa[maxn],sb[maxn],c;

int main()
{
    while (scanf("%d",&n)==1)
    {
        sa[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sa[i]=(sa[i-1]+a[i])%mod;
        }
        sb[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&b[i]);
            sb[i]=(sb[i-1]+b[i])%mod;
        }
        for (int i=1;i<=n;i++)
        {
            c=((sa[i]*b[i])%mod+(sb[i]*a[i])%mod-(a[i]*b[i])%mod+mod)%mod;
            printf("%lld ",c);
        }
        puts("");
    }
    return 0;
}
