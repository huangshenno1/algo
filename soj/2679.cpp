#include <stdio.h>
#include <stdlib.h>

int AscendingCompare(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}

int DescendingCompare(const void *a, const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int s;
    scanf("%d",&s);
    while (s)
    {
        int a,b;
        int p[10010],q[10010];
        int i,j;
        int count=0;
        scanf("%d%d",&a,&b);
        for (i=0;i<a;i++)
        {
            scanf("%d",&p[i]);
        }
        for (j=0;j<b;j++)
        {
            scanf("%d",&q[j]);
        }
        qsort(p,a,sizeof(int),AscendingCompare);
        qsort(q,b,sizeof(int),DescendingCompare);
        for (i=0,j=0;i<a&&j<b;)
        {
            if (p[i]+q[j]>s)
                j++;
            else if (p[i]+q[j]<s)
                i++;
            else
            {
                int m=1,n=1;
                int t=p[i++];
                while (t==p[i]&&i<a)
                {
                    m++;
                    i++;
                }
                t=q[j++];
                while (t==q[j]&&j<b)
                {
                    n++;
                    j++;
                }
                count+=m*n;
            }
        }
        printf("%d\n",count);
        scanf("%d",&s);
    }
    return 0;
}