#include <stdio.h>
#include <stdlib.h>

int cmp_low_fisrt(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int cmp_high_fisrt(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int a[210];
        int b[210];
        int n,m;
        int count=0;
        int i,j;
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for (i=0;i<m;i++)
            scanf("%d",&b[i]);
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (a[i]+b[j]==0)
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}