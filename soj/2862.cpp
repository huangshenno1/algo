#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[1000010],i;

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        if (n&1 || a[n/2]==a[n/2-1]) printf("%d\n",a[n/2]);
        else
        {
            if (a[0]==a[n/2-1]) printf("%d\n",a[0]);
            else printf("%d\n",a[n-1]);
        }
    }
    return 0;
}
