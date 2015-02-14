#include <stdio.h>

bool Live(int i,int j,bool life[105][105])
{
    int count=0;
    if (life[i+1][j])
        count++;
    if (life[i-1][j])
        count++;
    if (life[i][j+1])
        count++;
    if (life[i][j-1])
        count++;
    if (life[i+1][j+1])
        count++;
    if (life[i-1][j-1])
        count++;
    if (life[i+1][j-1])
        count++;
    if (life[i-1][j+1])
        count++;
    if (count==3)
        return 1;
    if (count==2)
        return life[i][j];
    return 0;
}

int main()
{
    int n,m,x;
    while (scanf("%d%d%d",&n,&m,&x)==3)
    {
        if (!(n||m||x))
            break;
        bool life[105][105];
        bool next[105][105];
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&life[i][j]);
            }
        }
        for (int i=1;i<=n;i++)
        {
            life[i][0]=life[i][m];
            life[i][m+1]=life[i][1];
        }
        for (int j=1;j<=m;j++)
        {
            life[0][j]=life[n][j];
            life[n+1][j]=life[1][j];
        }
        life[0][0]=life[n][m];
        life[0][m+1]=life[n][1];
        life[n+1][0]=life[1][m];
        life[n+1][m+1]=life[1][1];
        while (x--)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    next[i][j]=Live(i,j,life);
                }
            }
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    life[i][j]=next[i][j];
                }
            }
            for (int i=1;i<=n;i++)
            {
                life[i][0]=life[i][m];
                life[i][m+1]=life[i][1];
            }
            for (int j=1;j<=m;j++)
            {
                life[0][j]=life[n][j];
                life[n+1][j]=life[1][j];
            }
            life[0][0]=life[n][m];
            life[0][m+1]=life[n][1];
            life[n+1][0]=life[1][m];
            life[n+1][m+1]=life[1][1];
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                printf("%d",life[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}