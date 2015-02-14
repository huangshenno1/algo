#include <stdio.h>

int main()
{
    char a[60][60],b[60][60];
    int m,n;
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++)
    {
        scanf("%s",a[i]);
    }
    for (int i=0;i<m;i++)
    {
        scanf("%s",b[i]);
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j]!=b[i][j])
                printf("(%d,%d)\n",i,j);
        }
    }
    return 0;
}