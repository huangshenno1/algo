#include <cstdio>
#include <cstring>

int main()
{
    int T,a[6][6],b[6][6],i,j;
    scanf("%d",&T);
    while (T--)
    {
        for (i=0;i<6;i++)
            for (j=0;j<6;j++)
                scanf("%d",&a[i][j]);
        memcpy(b,a,sizeof(a));
        for (i=1;i<5;i++)
            for (j=1;j<5;j++)
                b[i][j]=a[i][j]*5-a[i-1][j]-a[i+1][j]-a[i][j-1]-a[i][j+1];
        for (i=0;i<6;i++)
            for (j=0;j<6;j++)
            {
                if (b[i][j]>255)
                    b[i][j]=255;
                if (b[i][j]<0)
                    b[i][j]=0;
            }
        for (i=0;i<6;i++)
        {
            printf("%d",b[i][0]);
            for (j=1;j<6;j++)
                printf(" %d",b[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}