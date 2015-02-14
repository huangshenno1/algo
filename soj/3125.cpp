#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int n,m;
    int note[100010];
    while (scanf("%d%d",&n,&m)==2)
    {
        int i;
        for (i=0;i<n;i++)
            scanf("%d",&note[i]);
        qsort(note,n,sizeof(int),cmp);
        int s=0;
        int count=0;
        for (i=0;i<n;i++)
        {
            s=s+note[i];
            count++;
            if (s>=m)
                break;
        }
        if (i==n)
            printf("-1\n");
        else printf("%d\n",count);
    }
    return 0;
}