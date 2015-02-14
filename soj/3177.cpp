#include <stdio.h>
#include <stdlib.h>

struct Order
{
    int priority;
    int number;
    char name[12];
}order[100010];

int cmp(const void *a, const void *b)
{
    int temp=((struct Order *)b)->priority-((struct Order *)a)->priority;
    if (temp==0)
        return ((struct Order *)a)->number-((struct Order *)b)->number;
    return temp;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s%d",order[i].name,&order[i].priority);
            order[i].number=i;
        }
        qsort(order,n,sizeof(struct Order),cmp);
        for (int i=0;i<n;i++)
        {
            printf("%s\n",order[i].name);
        }
    }
    return 0;
}