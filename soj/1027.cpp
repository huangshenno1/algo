#include <stdio.h>
void main()
{
    int n,i,j,t;
    int i1,i2,i3,i4,i5,i6;
    int a[13];
    scanf("%d",&n);
    while (n!=0)
    {
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (j=0;j<n-1;j++)
            for (i=j;i<n-1;i++)
                if (a[i]>a[i+1])
                {
                    t=a[i];
                    a[i]=a[i+1];
                    a[i+1]=t;
                }
        for (i1=0;i1<n-5;i1++)
            for (i2=i1+1;i2<n-4;i2++)
                for (i3=i2+1;i3<n-3;i3++)
                    for (i4=i3+1;i4<n-2;i4++)
                        for (i5=i4+1;i5<n-1;i5++)
                            for (i6=i5+1;i6<n;i6++)
                                printf("%d %d %d %d %d %d\n",a[i1],a[i2],a[i3],a[i4],a[i5],a[i6]);
        scanf("%d",&n);
        if (n)
            putchar('\n');
    }
}