#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=10000;
int ans,a[maxn];

int f(int n)
{
    if (n==1)
        return a[0];
    if (n==2)
        return a[1];
    if (n==3)
        return a[0]+a[1]+a[2];
    return min(a[0]+2*a[1]+a[n-1],2*a[0]+a[n-2]+a[n-1])+f(n-2);
}

int main()
{
    int n,i;
    while (scanf("%d",&n)==1)
    {
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        ans=f(n);
        printf("%d\n",ans);
    }
    return 0;
}