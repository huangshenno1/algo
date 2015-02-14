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
const int INF = 0x3f3f3f3f;
const int maxn = 110;

int n, a[maxn];
int dp[maxn][maxn];

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        for (int k = 2; k < n; k++)
            for (int i = 1; i <= n-k; i++)
            {
                int j = i + k;
                for (int x = i+1; x <= j; x++)
                {
                    int s = dp[i][x] + dp[x][j] + a[i]*a[x]*a[j];
                    if (dp[i][j]==0 || s < dp[i][j]) dp[i][j] = s;
                }
            }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
