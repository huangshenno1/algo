#include <stdio.h>
#include <stdlib.h>

struct BUILDING
{
    int l,r;
    int h;
}building[5001];

int cmp(const void *a,const void *b)
{
    struct BUILDING *temp1=(struct BUILDING *)a;
    struct BUILDING *temp2=(struct BUILDING *)b;
    if (temp1->l==temp2->l)
        return temp1->r-temp2->r;
    return temp1->l-temp2->l;
}

int main()
{
    int n=0,i,j;
    int h[10001]={0};
    int current_h;
    bool flag;
    while (scanf("%d%d%d",&building[n].l,&building[n].h,&building[n].r)==3)
        n++;
    qsort(building,n,sizeof(struct BUILDING),cmp);
    for (i=0;i<n;i++)
    {
        for (j=building[i].l;j<building[i].r;j++)
        {
            if (building[i].h>h[j])
                h[j]=building[i].h;
        }
    }
    current_h=0;
    flag=0;
    for (i=0;i<=10000;i++)
    {
        if (h[i]!=current_h)
        {
            if (!flag)
            {
                printf("%d %d",i,h[i]);
                flag=1;
            }
            else printf(" %d %d",i,h[i]);
            current_h=h[i];
        }
    }
    return 0;
}