#include <stdio.h>
#include <string.h>
#define N 6
struct num
{
    int value;
    int length;
}a[N];
void sort(struct num a[N],int n)
{
    int i,j,t,x,y,k;
    for (i=0;i<n-1;i++)
        for (j=0;j<n-1;j++)
        {
            x=a[j+1].value;
            for (k=0;k<a[j].length;k++)
                x*=10;
            x+=a[j].value;
            y=a[j].value;
            for (k=0;k<a[j+1].length;k++)
                y*=10;
            y+=a[j+1].value;
            if (x>y)
            {
                t=a[j].value;
                a[j].value=a[j+1].value;
                a[j+1].value=t;
                t=a[j].length;
                a[j].length=a[j+1].length;
                a[j+1].length=t;
            }
        }
}
void main()
{
    int l,n,i,j;
    scanf("%d",&l);
    for (j=0;j<l;j++)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i].value);
            if (a[i].value<10)
                a[i].length=1;
            else if (a[i].value<100)
                a[i].length=2;
            else if (a[i].value<1000)
                a[i].length=3;
            else a[i].length=4;
        }
        sort(a,n);
        for (i=0;i<n;i++)
        printf("%d",a[i].value);
        putchar('\n');
    }
}
