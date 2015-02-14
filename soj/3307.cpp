#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t,n,s,a[10010],i;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        s=a[0]=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n+1);
        for (i=n;i>0;i-=2)
        {
            s^=a[i]-a[i-1]-1;
        }
        if (s) printf("windy will win\n");
        else printf("wqb will win\n");
    }
    return 0;
}