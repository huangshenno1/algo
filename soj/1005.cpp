#include <stdio.h>
#define N 100

void main()
{
    int m,n,count;
    int avg;
    int i;
    int a[N];
    scanf("%d",&m);
    for (;m>0;m--)
    {
        count=0;
        avg=0;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            avg+=a[i];
        }
        avg=avg/n;
        for (i=0;i<n-1;i++)
        {
            if (a[i]==avg)
                continue;
            else
            {
                a[i+1]=a[i+1]+a[i]-avg;
                count++;
            }
        }
        printf("%d\n",count);
    }
}