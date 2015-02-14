#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 55;
int T, n, m;
long long dp[maxn][maxn];
long long ans;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));

        for (int i=0;i<(1<<m)-1;i++) dp[m][i] = 1;
        for (int i=m;i<n;i++)
            for (int j=0;j<(1<<m)-1;j++)
            {
                dp[i+1][(j&((1<<(m-1))-1))<<1|1] += dp[i][j];
                dp[i+1][(j&((1<<(m-1))-1))<<1] += dp[i][j];
            }

        ans = 0;
        for (int i=0;i<(1<<m)-1;i++)
            ans += dp[n][i];
        printf("%lld\n", ans);
    }
    return 0;
}
