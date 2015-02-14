#include <stdio.h>
#include <stdlib.h>

struct Event
{
    int d,s,e;
}event[50010];

int cmp(const void *a,const void *b)
{
    struct Event *aa=(struct Event *)a,*bb=(struct Event *)b;
    if (aa->d==bb->d)
    {
        return aa->e-bb->e;
    }
    else return aa->d-bb->d;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=1;iCase<=t;iCase++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d%d%d",&event[i].d,&event[i].s,&event[i].e);
        qsort(event,n,sizeof(struct Event),cmp);
        int count=0;
        int day=0;
        int end=0;
        for (int i=0;i<n;i++)
        {
            if (event[i].d>day||event[i].s>=end)
            {
                end=event[i].e;
                day=event[i].d;
                count++;
            }
        }
        printf("Scenario #%d:\n",iCase);
        printf("%d\n\n",count);
    }
    return 0;
}