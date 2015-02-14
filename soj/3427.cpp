#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parent[200000];

struct ROAD
{
    int a,b;
    int length;
}road[200000];

int cmp(const void *a,const void *b)
{
    struct ROAD *p1=(struct ROAD *)a;
    struct ROAD *p2=(struct ROAD *)b;
    return p1->length-p2->length;
}

int Parent(int n)
{
    if (parent[n]==-1)
        return n;
    return parent[n]=Parent(parent[n]);
}

int main()
{
    int m,n;
    int a,b;
    int i;
    int min_length;
    int sum_length;
    while (scanf("%d%d",&m,&n)==2 && m)
    {
        memset(parent,0xffffffff,sizeof(parent));
        min_length=0;
        sum_length=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d%d",&road[i].a,&road[i].b,&road[i].length);
            sum_length+=road[i].length;
        }
        if (m==1)
        {
            printf("%d\n",sum_length);
            continue;
        }
        qsort(road,n,sizeof(struct ROAD),cmp);
        for (i=0;i<n;i++)
        {
            a=Parent(road[i].a);
            b=Parent(road[i].b);
            if (a!=b)
            {
                parent[b]=a;
                min_length+=road[i].length;
            }
        }
        printf("%d\n",sum_length-min_length);
    }
    return 0;
}