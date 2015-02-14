#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        int a[30000];
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        int query;
        while (m--)
        {
            scanf("%d",&query);
            for (int i=0;i<n;i++)
            {
                if (query<a[i])
                {
                    printf("No %d\n",i);
                    break;
                }
                else if (query==a[i])
                {
                    printf("Yes %d\n",i);
                    break;
                }
                else if (i==n-1)
                {
                    printf("No %d\n",i+1);
                }
            }
        }
        printf("\n");
    }
    return 0;
}