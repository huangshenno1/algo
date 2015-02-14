#include <cstdio>
#include <algorithm>
using namespace std;

#define N 10010

long long x[N],y[N],z[N];

int main()
{
    int n;
    int i,j;
    long long ans;
    while (scanf("%d",&n)==1)
    {
        ans=0;
        for (i=0;i<n;i++)
            scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
        sort(x,x+n);
        sort(y,y+n);
        sort(z,z+n);
        for (i=0,j=n-1;i<j;i++,j--)
            ans+=x[j]+y[j]+z[j]-x[i]-y[i]-z[i];
        printf("%lld\n",ans);
    }
    return 0;
}