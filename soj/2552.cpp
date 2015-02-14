#include <cstdio>
#include <cstring>
const int maxn = 1000010;
int n;
int dp[maxn][2];

int main()
{
    memset(dp,0,sizeof(dp));
    dp[1][1]=1; dp[1][0]=0;
    dp[2][1]=2; dp[2][0]=1;
    dp[3][1]=5; dp[3][0]=2;
    for (int i=4;i<=1000000;i++)
    {
        dp[i][0]=(dp[i][0]+dp[i-1][0]+dp[i-2][1])%10000;
        dp[i][1]=(dp[i][1]+dp[i-1][1]+dp[i-2][1]+dp[i-1][0]*2)%10000;
    }
    while (scanf("%d",&n)==1)
    {
        printf("%d\n",dp[n][1]);
    }
    return 0;
}
