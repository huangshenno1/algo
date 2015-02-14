#include <stdio.h>
#include <string.h>

int matrix[401][401];
int f[2][401][401];
int max;

int main()
{
    int n;
    int i,j,k;
    while (scanf("%d",&n)==1)
    {
        max=0;
        memset(f,0,sizeof(f));
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                scanf("%d",&matrix[i][j]);
        for (k=1;k<n;k++)
        {
            for (i=0;i<n-k;i++)
            {
                for (j=0;j<n-k;j++)
                {
                    f[k&1][i][j]=f[k&1][i+1][j+1]+matrix[i][j]+matrix[i+k][j+k]-matrix[i][j+k]-matrix[i+k][j];
                    if (f[k&1][i][j]>max)
                        max=f[k&1][i][j];
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}