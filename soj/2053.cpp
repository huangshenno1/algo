#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        int a[11];
        for (int i=0;i<10;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,10,sizeof(int),cmp);
        for (int i=0;i<10;i++)
        {
            printf("%d",a[i]);
            if (i<9)
                printf(" ");
            else printf("\n");
        }
    }
}