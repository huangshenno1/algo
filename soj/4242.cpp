#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=130000;
int n,i;
double ans,X,Y,a[maxn],b[maxn],f[maxn],g[maxn];

int main()
{
    while (scanf("%d",&n)==1)
    {
        scanf("%lf%lf",&X,&Y);
        if (n==0)
        {
            printf("%d\n",X);
            continue;
        }
        for (i=0;i<n;i++)
            scanf("%lf%lf",&a[i],&b[i]);
        f[n-1]=max(1.0,b[n-1]/a[n-1]);
        g[n-1]=b[n-1];
        for (i=n-2;i>=0;i--)
        {
            f[i]=max(f[i+1],f[i+1]*b[i]/a[i]+g[i+1]/a[i]);
            g[i]=f[i+1]*b[i]+g[i+1];
        }
        ans=f[0]*X+Y*g[0];
        if (ans>=1e15)
            printf("abm win.\n");
        else printf("%.0lf\n",ans);
    }
    return 0;
}