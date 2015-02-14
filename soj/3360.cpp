#include <stdio.h>

#define MAX 2000000000

int Min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int f[55001];
    int p[100],c[100];
    int n,h;
    int min_c;
    int i,j;
    while (scanf("%d%d",&n,&h)==2)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&p[i],&c[i]);
        }
        f[0]=0;
        for (i=1;i<=h+5000;i++)
            f[i]=MAX;
        for (i=0;i<n;i++)
        {
            for (j=0;j<=h+5000;j++)
            {
                if (j>=p[i])
                    f[j]=Min(f[j],f[j-p[i]]+c[i]);
            }
        }
        min_c=MAX;
        for (i=h;i<=h+5000;i++)
            min_c=Min(min_c,f[i]);
        printf("%d\n",min_c);
    }
    return 0;
}