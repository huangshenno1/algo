#include <cstdio>
#include <cstring>

const int N=10000;
int n;
double dp[N+5][5];

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][2]=1;
    for (int i=0;i<N;i++)
    {
        dp[i+1][1]+=dp[i][0];
        for (int j=1;j<=3;j++)
        {
            dp[i+1][j-1]+=dp[i][j]*0.5;
            dp[i+1][j+1]+=dp[i][j]*0.5;
        }
        dp[i+1][3]+=dp[i][4];
    }

    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<5;i++)
            printf("%.2lf ",dp[n][i]);
        printf("\n");
    }
    return 0;
}