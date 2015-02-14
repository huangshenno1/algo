#include <stdio.h>
#include <string.h>

int Cost(int a,int b)
{
    return (a-b)*(a-b);
}

int f[5001][1001];

int main()
{
    int t,n,k;
    int l[5001];
    int i,j;
    int temp;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&k,&n);
        k+=8;
        for (i=1;i<=n;i++)
            scanf("%d",&l[i]);
        memset(f,0xffffffff,sizeof(f));
        for (i=0;i<=n;i++)
        {
            f[i][0]=0;
        }
        for (i=n-2;i>0;i--)
        {
            for (j=1;j<=k;j++)
            {
                f[i][j]=f[i+1][j];
                if (f[i+2][j-1]>=0 && (n-i+1)>=3*j)
                {
                    temp=f[i+2][j-1]+Cost(l[i+1],l[i]);
                    if (temp<f[i][j] || f[i][j]==-1)
                    {
                        f[i][j]=temp;
                    }
                }                
            }
        }
        printf("%d\n",f[1][k]);
    }
    return 0;
}