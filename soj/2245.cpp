#include <stdio.h>

int p[50010];

int find(int n)
{
    if (n!=p[n])
        p[n]=find(p[n]);
    return p[n];
}

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    int iCase=0;
    while (m||n)
    {
        iCase++;
        for (int i=1;i<=n;i++)
            p[i]=i;
        int s=n;
        int a,b;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            a=find(a);
            b=find(b);
            if (a==b);
            else
            {
                s--;
                p[b]=a;
            }
        }

        printf("Case %d: %d\n",iCase,s);
        scanf("%d%d",&n,&m);
    }
    return 0;
}