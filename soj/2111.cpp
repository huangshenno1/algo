#include <stdio.h>

int Max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int m,n;
    int p[30];
    int f[210];
    int i,j;
    while (scanf("%d%d",&m,&n)==2)
    {
        for (i=0;i<n;i++)
            scanf("%d",&p[i]);
        for (j=0;j<=m;j++)
            f[j]=0;
        for (i=0;i<n;i++)
        {
            for (j=m;j>0;j--)
            {
                if (j>=p[i])
                    f[j]=Max(f[j],f[j-p[i]]+p[i]);
            }
        }
        printf("%d\n",f[m]);
    }
    return 0;
}