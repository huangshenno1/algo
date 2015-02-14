#include <cstdio>

int m,n;
int a[1001][1001];
bool flag;
int i,j;

int main()
{
    while (scanf("%d%d",&m,&n)==2)
    {
        flag=1;
        for (i=0;i<m;i++)
            for (j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for (i=1;i<m;i++)
        {
            for (j=1;j<n;j++)
            {
                if (a[i][j]+a[i-1][j-1]>a[i-1][j]+a[i][j-1])
                {
                    flag=0;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}