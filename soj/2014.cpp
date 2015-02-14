#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}

int main()
{
    int t,iCase;
    scanf("%d",&t);
    for (iCase=0;iCase<t;iCase++)
    {
        int rope[1010];
        int n;
        scanf("%d",&n);
        int max=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&rope[i]);
        }
        qsort(rope,n,sizeof(int),cmp);
        int tearWeight;
        for (int i=0;i<n;i++)
        {
            tearWeight=rope[i]*(n-i);
            if (tearWeight>max)
                max=tearWeight;
        }
        printf("%d\n",max);
    }
    return 0;
}