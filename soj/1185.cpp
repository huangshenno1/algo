#include <stdio.h>

struct
{
    int l,r,u,d;
}rectangle[8000];

int main()
{
    int n,i,j,count;
    while (scanf("%d",&n)==1)
    {
        count=0;
        for (i=0;i<n;i++)
            scanf("%d%d%d%d",&rectangle[i].l,&rectangle[i].r,&rectangle[i].d,&rectangle[i].u);
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i==j)
                    continue;
                if (rectangle[i].l>=rectangle[j].l && rectangle[i].r<=rectangle[j].r && rectangle[i].d>=rectangle[j].d && rectangle[i].u<=rectangle[j].u)
                {
                    count++;
                    break;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}