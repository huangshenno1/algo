#include <stdio.h>
#include <string.h>

#define MAX 2000000000

int height[100][10001];

int main()
{
    int t;
    int n;
    int l[100][100];
    int possible[10001];
    int p[100];
    int h[100];
    int min;
    int temp;
    int i,j,k;
    scanf("%d",&t);
    while (t--)
    {
        min=MAX;
        memset(height,0,sizeof(height));
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            h[i]=0;
            p[i]=0;
            scanf("%d",&temp);
            while (temp!=-1)
            {
                h[i]+=temp;
                l[i][p[i]++]=temp;
                scanf("%d",&temp);
            }
            if (min>h[i])
                min=h[i];
            height[i][0]=1;
            for (j=0;j<p[i];j++)
            {
                for (k=h[i];k>=0;k--)
                {
                    if (k>=l[i][j])
                        height[i][k]=height[i][k]+height[i][k-l[i][j]];
                }
            }
        }
        for (i=0;i<=min;i++)
            possible[i]=1;
        for (i=0;i<n;i++)
        {
            for (j=0;j<=h[i];j++)
            {
                if (!height[i][j])
                    possible[j]=0;
            }
        }
        for (k=min;k>=0;k--)
        {
            if (possible[k])
            {
                printf("%d\n",k);
                break;
            }
        }
    }
    return 0;
}