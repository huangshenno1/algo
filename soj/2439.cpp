#include <cstdio>

int T,n,l,m,i,k;
int a[2][1050];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&l);
        n=1<<n;
        for (k=0,i=0;i<n;i++)
        {
            scanf("%d",&a[k][i]);
            a[1-k][i]=a[k][i];
        }
        m=n;
        while (l--)
        {
            for (i=0;i<m;i+=2)
            {
                a[1-k][i/2]=a[k][i]+a[k][i+1];
                a[1-k][i/2+m/2]=a[k][i]-a[k][i+1];
            }
            k=1-k;
            for (i=0;i<m;i++)
                a[1-k][i]=a[k][i];
            m>>=1;
        }
        printf("%d",a[k][0]);
        for (i=1;i<n;i++)
            printf(" %d",a[k][i]);
        printf("\n");
    }
    return 0;
}