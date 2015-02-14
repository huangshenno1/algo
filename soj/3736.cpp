#include <cstdio>

const int maxn = 1010;
int n,m;
int value[maxn];
int sum[maxn];
int dp[maxn][maxn];
int att[maxn][maxn];

inline int Sum(int a,int b) {return sum[b]-sum[a]-value[a]*(value[b]-value[a]);}

int main()
{
    int i,j,k;
    while (scanf("%d%d",&n,&m)==2 && n)
    {
        for (sum[0]=value[0]=0,i=1;i<=n;i++)
        {
            scanf("%d",&value[i]);
            sum[i]=sum[i-1]+value[i]*value[i-1];
            value[i]+=value[i-1];
            dp[0][i]=sum[i];
            att[0][i]=0;
        }
        for (i=1;i<=m;i++)
        {
            att[i][n+1]=n;
            for (j=n;j>=i;j--)
            {
                dp[i][j]=dp[i-1][att[i-1][j]]+Sum(att[i-1][j],j);
                att[i][j]=att[i-1][j];
                for (k=att[i-1][j]+1;k<=att[i][j+1];k++)
                {
                    if (dp[i][j]>dp[i-1][k]+Sum(k,j))
                    {
                        dp[i][j]=dp[i-1][k]+Sum(k,j);
                        att[i][j]=k;
                    }
                }
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}