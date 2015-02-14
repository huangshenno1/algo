#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1005;
int T, n1, n2;
int a[maxn], b[maxn];
int dp[maxn][maxn];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n1, &n2);
        if (n2 < n1)
        {
            swap(n1, n2);
            for (int i=1;i<=n2;i++) scanf("%d", &b[i]);
            for (int i=1;i<=n1;i++) scanf("%d", &a[i]);
        }
        else
        {
            for (int i=1;i<=n1;i++) scanf("%d", &a[i]);
            for (int i=1;i<=n2;i++) scanf("%d", &b[i]);
        }
        sort(a+1, a+n1+1);
        sort(b+1, b+n2+1);
        
        memset(dp, 0x3f, sizeof(dp));
        for (int i=0,j=0;j<=n2;j++) dp[i][j] = 0;
        for (int i=1;i<=n1;i++)
        {
            dp[i][i] = dp[i-1][i-1] + abs(a[i] - b[i]);
            for (int j=i+1;j<=n2;j++)
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(a[i] - b[j]));
        }
        
        int ans = 1e9;
        for (int i=n1,j=n1;j<=n2;j++) ans = min(ans, dp[i][j]);
        printf("%d\n", ans);
    }
    return 0;
}
