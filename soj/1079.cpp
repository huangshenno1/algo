#include <cstdio>
#include <cmath>
#define INF 0x7fffffff

int a[1000],aa;
int f[50001];
int m,n;
int i,j;

int Min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    while (scanf("%d%d",&m,&n)==2 && m)
    {
        for (i=2;i<=m;i++)
            f[i]=INF;
        f[0]=f[1]=0;
        a[0]=1;
        aa=1;
        for (i=2;i<=n;i++)
        {
            for (j=2;(int)(pow((double)j,i)+0.5)<=m;j++)
            {
                a[aa++]=(int)(pow((double)j,i)+0.5);
                f[a[aa-1]]=0;
            }
        }
        for (i=0;i<aa;i++)
        {
            for (j=1;j<=m;j++)
            {
                if (j>=a[i])
                    f[j]=Min(f[j],f[j-a[i]]+1);
            }
        }
        printf("%d\n",f[m]);
    }
    return 0;
}