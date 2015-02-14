#include <stdio.h>
#define MIN -200000000

int Max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int t;
    int r,w;
    int f[2][51][51];
    int flag;
    char str[1001];
    int i,j,k;
    int temp;
    int ans;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%s",&r,&w,str);
        for (i=0;i<=r;i++)
        {
            for (j=0;j<=w;j++)
            {
                f[0][i][j]=MIN;
            }
        }
        f[0][0][0]=0;
        flag=1;
        for (k=0;str[k]!='\0';k++)
        {
            if (str[k]=='G')
                temp=1;
            else temp=0;
            for (i=0;i<=r;i++)
            {
                for (j=0;j<=w;j++)
                {
                    f[flag][i][j]=MIN;
                }
            }
            for (i=0;i<=r;i++)
            {
                for (j=0;j<=w;j++)
                {
                    if (f[1^flag][i][j]>=0)
                    {
                        if (i==r)
                            f[flag][0][1]=Max(f[flag][0][1],f[1^flag][i][j]+1-temp);
                        else if (j==w)
                            f[flag][1][0]=Max(f[flag][1][0],f[1^flag][i][j]+temp);
                        else
                        {
                            f[flag][i+1][0]=Max(f[flag][i+1][0],f[1^flag][i][j]+temp);
                            f[flag][0][j+1]=Max(f[flag][0][j+1],f[1^flag][i][j]+1-temp);
                        }
                    }
                }
            }
            flag=1^flag;
        }
        ans=0;
        flag=1^flag;
        for (i=0;i<=r;i++)
        {
            for (j=0;j<=w;j++)
            {
                if (f[flag][i][j]>ans)
                    ans=f[flag][i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}