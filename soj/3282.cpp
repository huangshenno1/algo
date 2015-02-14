#include <stdio.h>



int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m,q,x,y,px,py;
        scanf("%d%d%d",&n,&m,&q);
        int p[10010];
        int d[10010];
        for (int i=1;i<=n;i++)
        {
            p[i]=i;
            d[i]=1;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            while (p[x]!=x)
                x=p[x];
            while (p[y]!=y)
                y=p[y];
            if (d[x]>d[y])
                p[y]=x;
            else if (d[x]<d[y])
                p[x]=y;
            else
            {
                p[y]=x;
                d[x]++;
            }
        }
        for (int i=0;i<q;i++)
        {
            scanf("%d%d",&px,&py);
            x=px;
            y=py;
            while (p[px]!=px)
                px=p[px];
            p[x]=px;
            while (p[py]!=py)
                py=p[py];
            p[y]=py;
            if (px==py)
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}