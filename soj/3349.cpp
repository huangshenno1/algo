#include <cstdio>

int main()
{
    int n,q;
    int b[102],f[102],t;
    int i;
    int low,high,mid;
    f[0]=-1;
    f[101]=10000;
    while (scanf("%d%d",&n,&q)==2)
    {
        for (i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            f[i]=b[i]+f[i-1];
        }
        while (q--)
        {
            scanf("%d",&t);
            low=1;high=n;mid=(low+high)>>1;
            while (!(f[mid]>=t && f[mid-1]<t))
            {
                if (f[mid]<t)
                {
                    low=mid+1;
                    mid=(low+high)>>1;
                }
                else if (f[mid-1]>=t)
                {
                    high=mid-1;
                    mid=(low+high)>>1;
                }
            }
            printf("%d\n",mid);
        }
    }
    return 0;
}