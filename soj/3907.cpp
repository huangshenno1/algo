#include <stdio.h>

struct direction
{
    int x,y;
}dir[4]={1,0,0,1,-1,0,0,-1};

int spiral[760][760];

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int i=1,j=n;
        int l=n-1;
        int s=n*n;
        for (int k=1;k<=n;k++)
        {
            spiral[i][k]=k;
        }
        int d=0;
        for (int k=n+1;k<=s;)
        {
            d=(d+1)%4;
            for (int p=0;p<l;p++)
            {
                i+=dir[d].y;
                j+=dir[d].x;
                spiral[i][j]=k++;
            }
            d=(d+1)%4;
            for (int p=0;p<l;p++)
            {
                i+=dir[d].y;
                j+=dir[d].x;
                spiral[i][j]=k++;
            }
            l--;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                printf("%d",spiral[i][j]);
                if (j==n)
                    putchar('\n');
                else putchar(' ');
            }
        }
    }
    return 0;
}