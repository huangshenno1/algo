#include <stdio.h>
#define N 101
int max(int x,int y)
{
    return x>y?x:y;
}
void main()
{
    int a[N][N];
    int b[N][N]={0};
    int s[N][N]={0};
    int n;
    int i,j;
    int r,l;
    int best;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            s[i][j]=s[i][j-1]+a[i][j];
        }
    best=a[1][1];
    for (l=1;l<=n;l++)
        for (r=l;r<=n;r++)
        {
            for (i=1;i<=n;i++)
            {
                b[i][r]=max(b[i-1][r]+s[i][r]-s[i][l-1],s[i][r]-s[i][l-1]);
                if (b[i][r]>best)
                    best=b[i][r];
            }
        }
    printf("%d\n",best);
}
