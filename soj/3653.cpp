#include <cstdio>
#include <algorithm>
using namespace std;

struct cc
{
    long long p,c;
    bool operator < (const cc o) const
    {
        return p<o.p;
    }
}a[100010];
int n;
long long m,ans;

int main()
{
    while (scanf("%lld%lld",&n,&m)==2)
    {
        int i;
        long long j;
        for (i=0;i<n;i++)
            scanf("%lld%lld",&a[i].p,&a[i].c);
        sort(a,a+n);
        ans=0;
        for (i=0;i<n&&m>=a[i].p;i++)
        {
            j=min(m/a[i].p,a[i].c);
            ans+=j;
            m-=j*a[i].p;
        }
        printf("%lld\n",ans);
    }
    return 0;
}