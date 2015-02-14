#include <cstdio>
#include <cstring>

const int maxn = 105;
int n;
int a[maxn][maxn];
int dp[maxn][maxn];
int pre[maxn][maxn];
int ans[maxn];

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++)
                scanf("%d", &a[i][j]);
        memset(dp, 0, sizeof(dp));
        dp[1][1] = a[1][1];
        for (int i=2;i<=n;i++)
            for (int j=1;j<=i;j++)
            {
                if (dp[i-1][j-1] > dp[i-1][j])
                {
                    dp[i][j] = dp[i-1][j-1] + a[i][j];
                    pre[i][j] = j-1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + a[i][j];
                    pre[i][j] = j;
                }
            }
        int x = 0, sum = 0;
        for (int i=1;i<=n;i++)
            if (dp[n][i] > sum) {sum = dp[n][i]; x = i;}
        ans[n] = x;
        for (int i=n-1;i>=1;i--)
        {
            x = pre[i+1][x];
            ans[i] = x;
        }
        printf("%d\n", sum);
        printf("%d", a[1][ans[1]]);
        for (int i=2;i<=n;i++) printf(" %d", a[i][ans[i]]);
        puts("");
    }
    return 0;
}
