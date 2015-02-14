#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF=0x7fffffff;
const int maxn=1000010;

int n,ans,i,k;
int a[maxn],d[maxn],g[maxn];

int main()
{
    while (scanf("%d",&n)==1)
    {
        ans=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            g[i]=INF;
        }
        for (i=1;i<=n;i++)
        {
            k=lower_bound(g,g+n,a[i])-g;
            d[i]=k;
            g[k]=a[i];
            ans=max(ans,k);
        }
        printf("%d\n",ans);
    }
    return 0;
}