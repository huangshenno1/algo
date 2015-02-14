#include <cstdio>
typedef long long ll;

int mod = 1000000007;
int n;
char cmd[10];
ll x,ans1[2],ans2[2];
bool flag;

ll inv(ll xx)
{
    ll res=1;
    int k=mod-2;
    while (k)
    {
        if (k&1) res=(res*xx)%mod;
        xx=(xx*xx)%mod;
        k>>=1;
    }
    return res;
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        ans1[0]=0;
        ans2[0]=1;
        flag=0;
        while (n--)
        {
            flag^=1;
            scanf("%s %lld",cmd,&x);
            if (cmd[0]=='i')
            {
                ans1[flag]=(ans1[flag^1]+(ans2[flag^1]*x)%mod)%mod;
                ans2[flag]=(ans2[flag^1]+(ans1[flag^1]*x)%mod)%mod;
            }
            else
            {
                ans1[flag]=((((ans2[flag^1]*x)%mod-ans1[flag^1]+mod)%mod)*inv((x*x-1)%mod))%mod;
                ans2[flag]=((((((ans1[flag^1])*x)%mod)-ans2[flag^1]+mod)%mod)*inv((x*x-1)%mod))%mod;
            }
            printf("%lld\n",ans1[flag]);
        }
    }
    return 0;
}