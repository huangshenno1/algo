#include <stdio.h>

#define MAX 2000000

int w[4][4]={0,1,2,2,1,0,1,1,2,1,0,2,2,1,2,0};

int Min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int f[2][4][4];
    int ans=MAX;
    int flag=1;
    char c;
    int t;
    int i,j;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            f[0][i][j]=MAX;
            f[1][i][j]=MAX;
        }
    }
    f[0][2][3]=f[0][3][2]=0;
    while (scanf("%c",&c)==1)
    {
        if (c=='\n')
        {
            flag=1^flag;
            for (i=0;i<4;i++)
            {
                for (j=0;j<4;j++)
                {
                    if (f[flag][i][j]!=MAX&&f[flag][i][j]<ans)
                    {
                        ans=f[flag][i][j];
                    }
                }
            }
            printf("%d\n",ans);
            ans=MAX;
            for (i=0;i<4;i++)
            {
                for (j=0;j<4;j++)
                {
                    f[0][i][j]=MAX;
                    f[1][i][j]=MAX;
                }
            }
            f[0][2][3]=f[0][3][2]=0;
            flag=1;
            continue;
        }
        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                f[flag][i][j]=MAX;
            }
        }
        t=c-'0';
        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                if (f[1^flag][i][j]!=-1)
                {
                    f[flag][t][j]=Min(f[flag][t][j],f[1^flag][i][j]+w[i][t]);
                    f[flag][i][t]=Min(f[flag][i][t],f[1^flag][i][j]+w[j][t]);
                }
            }
        }
        flag=1^flag;
    }
    return 0;
}