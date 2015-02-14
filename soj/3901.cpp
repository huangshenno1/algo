#include <cstdio>

const long long mod = 12345678910LL;
const int maxn = 100010;
int n,a[maxn],cur;

long long f()
{
    long long res=0;
    while (cur<n && a[cur]==0)
    {
        if (a[++cur]==0) res+=f()<<1;
        else res++;
        cur++;
    }
    return res%mod;
}

int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        cur=0;
        printf("%lld\n",f());
    }
    return 0;
}