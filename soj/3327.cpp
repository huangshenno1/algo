#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int a,b,d;
}node[100001];

int cmp(const void *a,const void *b)
{
    struct NODE *t1=(struct NODE *)a;
    struct NODE *t2=(struct NODE *)b;
    return t2->d-t1->d;
}

int main()
{
    int t;
    int n,m;
    int i;
    bool flag;
    scanf("%d",&t);
    while (t--)
    {
        flag=1;
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&node[i].a,&node[i].b);
            node[i].d=node[i].a-node[i].b;
        }
        qsort(node,n,sizeof(struct NODE),cmp);
        for (i=0;i<n;i++)
        {
            if (m>=node[i].a)
                m-=node[i].b;
            else
            {
                flag=0;
                break;
            }
        }
        if (flag)
            printf("Clever Dahema\n");
        else printf("Stupid Dahema\n");
    }
    return 0;
}