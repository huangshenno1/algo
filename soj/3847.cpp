#include <stdio.h>
#include <stdlib.h>

struct TIME
{
    int h,m,s;
}time[5001];

int cmp(const void *a,const void *b)
{
    struct TIME *temp1=(struct TIME *)a;
    struct TIME *temp2=(struct TIME *)b;
    if (temp1->h==temp2->h)
    {
        if (temp1->m==temp2->m)
            return temp1->s-temp2->s;
        return temp1->m-temp2->m;
    }
    return temp1->h-temp2->h;
}

int main()
{
    int n;
    int i;
    while (scanf("%d",&n)==1)
    {
        for (i=0;i<n;i++)
            scanf("%d%d%d",&time[i].h,&time[i].m,&time[i].s);
        qsort(time,n,sizeof(struct TIME),cmp);
        for (i=0;i<n;i++)
            printf("%d %d %d\n",time[i].h,time[i].m,time[i].s);
    }
    return 0;
}