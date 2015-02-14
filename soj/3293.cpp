#include <cstdio>

#define R 1024

int C[901][301];

int main()
{
    int i,j;
    for (i=0;i<=900;i++)
        C[i][0]=1;
    for (i=1;i<=900;i++)
    {
        for (j=1;j<=i/2&&j<=300;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%R;
        for (;j<=i&&j<=300;j++)
            C[i][j]=C[i][i-j];
    }
    int x,y,z;
    while (scanf("%d%d%d",&x,&y,&z)==3)
    {
        int ans=(C[x+y+z][x]*C[y+z][y])%R;
        printf("%d\n",ans);
    }
}