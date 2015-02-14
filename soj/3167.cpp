#include <cstdio>
#include <algorithm>
using namespace std;

struct work
{
    int t,w;
    bool operator < (const work &a) const
    {
        return t*a.w < w*a.t;
    }
};

int T,n;
long long ans,t;
work a[50010];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d%d",&a[i].t,&a[i].w);
        sort(a,a+n);
        ans=t=0;
        for (int i=0;i<n;i++)
        {
            ans+=a[i].w*t;
            t+=a[i].t;
        }
        printf("%lld\n",ans);
    }
    return 0;
}