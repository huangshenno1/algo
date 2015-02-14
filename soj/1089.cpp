#include <stdio.h>
#define N 101
void main()
{
    int m,n;
    int i,j,k;
    int count;
    int a[N];
    scanf("%d %d",&n,&m);
    while (m!=0&&n!=0)
    {
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        count=0;
        for (i=0;i<n-2;i++)
            for (j=i+1;j<n-1;j++)
                for (k=j+1;k<n;k++)
                {
                    if ((a[i]+a[j]+a[k])==m)
                        count++;
                }
        printf("%d\n",count);
        scanf("%d %d",&n,&m);
    }
}