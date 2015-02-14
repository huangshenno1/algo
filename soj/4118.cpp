#include <cstdio>
#include <algorithm>
using namespace std;

int T,n,p,i;
int a[1000010];
long long ans,cnt;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (a[0]=-1,i=1;i<=n;i++)
        {
            scanf("%d",&p);
            if (p) scanf("%d",&a[i]);
            else a[i]=a[i-1]+1;
        }
        sort(a+1,a+n+1);
        ans=0;
        for (cnt=1,i=2;i<=n;i++)
        {
            if (a[i]==a[i-1]) cnt++;
            else
            {
                ans+=cnt*(cnt-1)/2;
                cnt=1;
            }
        }
        ans+=cnt*(cnt-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}