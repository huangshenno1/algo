#include <stdio.h>

int min(int a,int b)
{
    return a<b?a:b;
}

int abs(int a)
{
    return a<0?-a:a;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for (int i=0;i<q;i++)
        {
            int x0,y0,x1,y1;
            scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
            printf("%d\n",min(abs(x1-x0),min(abs(n+1+x0-x1),abs(n+1+x1-x0)))+min(abs(y1-y0),min(abs(m+1+y0-y1),abs(m+1+y1-y0))));
        }
    }
    return 0;
}