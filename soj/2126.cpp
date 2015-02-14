#include <cstdio>

int n,m;
int a[50010];

int main()
{
    int p,q,t;
    int i,j;
    while (scanf("%d%d",&n,&m)==2 && n!=-1)
    {
        p=0;
        q=1;
        while (p<m)
            p+=q++;
        p=p-m;
        for (i=1;i<=n-q;i++)
            a[i]=i;
        a[i]=n-p;
        t=n;
        for (j=i+1;j<=n;j++)
        {
            if (t==n-p)
                t--;
            a[j]=t--;
        }
        printf("%d",a[1]);
        for (i=2;i<=n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
