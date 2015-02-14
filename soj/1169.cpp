#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parent[51];

struct ROAD
{
    int a,b;
    int length;
}road[1250];

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
    int p,r;
    int a,b;
    int i;
    int min_length;
    while (scanf("%d",&p)==1)
    {
        if (p==0)
            break;
        memset(parent,0xffffffff,sizeof(parent));
        min_length=0;
        scanf("%d",&r);
        if (p==1)
        {
            printf("0\n");
            continue;
        }
        for (i=0;i<r;i++)
            scanf("%d%d%d",&road[i].a,&road[i].b,&road[i].length);
        qsort(road,r,sizeof(struct ROAD),cmp);
        for (i=0;i<r;i++)
        {
            a=Parent(road[i].a);
            b=Parent(road[i].b);
            if (a!=b)
            {
                parent[b]=a;
                min_length+=road[i].length;
            }
        }
        printf("%d\n",min_length);
    }
    return 0;
}