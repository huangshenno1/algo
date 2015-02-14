#include <stdio.h>
#include <stdlib.h>

struct Wall
{
    int x1,x2;
};

int cmp(const void *a,const void *b)
{
    struct Wall *ta=(struct Wall *)a;
    struct Wall *tb=(struct Wall *)b;
    if (ta->x2==tb->x2)
        return tb->x1-ta->x1;
    return ta->x2-tb->x2;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        Wall wall[110];
        int x1,x2,y;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&x1,&y);
            scanf("%d%d",&x2,&y);
            if (x1<x2)
            {
                wall[i].x1=x1;
                wall[i].x2=x2;
            }
            else
            {
                wall[i].x1=x2;
                wall[i].x2=x1;
            }
        }
        if (k==0)
        {
            printf("%d\n",n);
            continue;
        }
        qsort(wall,n,sizeof(struct Wall),cmp);
        int m=0;
        int count[110];
        for (int i=0;i<n;i++)
        {
            count[i]=1;
            for (int j=0;j<i;j++)
            {
                if (count[j]&&wall[i].x1<=wall[j].x2)
                {
                    if (count[j]==k)
                    {
                        count[i]=0;
                        m++;
                        break;
                    }
                    else count[j]++;
                }
            }
        }
        printf("%d\n",m);
    }
    return 0;
}