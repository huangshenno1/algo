#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int T,a[10],i;
    scanf("%d",&T);
    while (T--)
    {
        for (i=0;i<10;i++)
            scanf("%d",&a[i]);
        for (i=0;i<9;i++)
            a[i]=a[i]+a[i+1];
        sort(a,a+9);
        printf("%d\n",a[0]+a[1]);
    }
    return 0;
}